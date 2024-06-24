#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

#include "UsuarioArchivo.h"


bool UsuarioArchivo::guardar(const Usuario &usuario) {
    cout << "Guardando usuario";
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "ab"); //uso _nombreArchivo para flexibilizar el codigo

    cout << "Archivo abierto";

    if(pFile == nullptr){
        cout << "Puntero null";
        return false;
    }

    bool result = fwrite(&usuario, sizeof(Usuario), 1, pFile)==1;
    if(result){
        cout << "Escrito con exito";
    }
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
        cout << "No se pudo abrir el archivo de usuarios." << endl;
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
    Usuario reg;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return usuarios;
    }
    while (fread(&reg, sizeof(Usuario), 1, pFile)) {
        usuarios.push_back(reg);
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
    ofstream file(_nombreArchivo, ios::trunc);
    if (file.is_open()) {
        for (const auto &usuario : usuarios) {
            file.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuario));
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para actualizar." << endl;
    }
}
