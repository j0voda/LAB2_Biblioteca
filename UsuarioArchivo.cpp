#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

#include "UsuarioArchivo.h"


bool UsuarioArchivo::guardar(const Usuario &usuario) {
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "ab");
    if(pFile == nullptr){
        return false;
    }
    bool result = fwrite(&usuario, sizeof(Usuario), 1, pFile)==1;
    fclose(pFile);
    return result;
}

bool UsuarioArchivo::modificar(int index, const Usuario& usuario) {
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Usuario) * index, SEEK_SET);
    bool result = fwrite(&usuario, sizeof(Usuario), 1, pFile)==1;
    fclose(pFile);
    return result;
}

int UsuarioArchivo::buscarById(int id) {
    Usuario usuario;
    int pos = 0;
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&usuario, sizeof(Usuario), 1, pFile)) {
        if(usuario.getId() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Usuario UsuarioArchivo::leer(int index) {
    Usuario usuario;
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return usuario;
    }
    fseek(pFile, index * sizeof(Usuario), SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, pFile);
    fclose(pFile);
    return usuario;
}

vector<Usuario> UsuarioArchivo::leerPorPermisos(int permisos) {
    vector<Usuario> usuarios;
    Usuario usuario;
    FILE *pFile = fopen(this->_nombreArchivo, "rb");
    if (pFile == nullptr) {
        return usuarios;
    }
    while (fread(&usuario, sizeof(Usuario), 1, pFile) == 1) {
        if (usuario.getPermisos() == permisos) {
            usuarios.push_back(usuario);
        }
    }
    fclose(pFile);
    return usuarios;
}

vector<Usuario> UsuarioArchivo::leerTodos() {
    vector<Usuario> usuarios;
    Usuario libro;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return usuarios;
    }
    while (fread(&libro, sizeof(Usuario), 1, pFile)) {
        usuarios.push_back(libro);
    }
    fclose(pFile);
    return usuarios;
}

int UsuarioArchivo::getCantidadRegistros() {
    FILE *pFile;
    int tam;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    tam = ftell(pFile) / sizeof(Usuario);
    fclose(pFile);

    return tam;
}

int UsuarioArchivo::getCantidadRegistrosPorPermiso(int permisos) {
    FILE *pFile;
    Usuario usuario;
    int contador=0;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return 0;
    }
    while(fread(&usuario,sizeof(Usuario),1,pFile)){
		if(usuario.getPermisos()==permisos){
			contador++;
		}
    }
    fclose(pFile);
    return contador;
}

int UsuarioArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if(cantidad > 0){
        return leer(cantidad-1).getId() + 1;
    }
    else{
        return 1;
    }
}

void UsuarioArchivo::actualizar(const vector<Usuario> &usuarios) {
	FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &usuario : usuarios) {
        fwrite(&usuario, sizeof(Usuario), 1, pFile);
    }
    fclose(pFile);
}



