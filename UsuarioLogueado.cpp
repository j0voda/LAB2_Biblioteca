#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

#include "UsuarioLogueado.h"

void UsuarioLogueado::limpiar() {
    ofstream file(this->_nombreArchivo);
    file.close();
}

void UsuarioLogueado::guardar(const Usuario &usuario) {
    this->limpiar();

    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "ab");
    if(pFile == nullptr){
        return;
    }
    // Apuntamos a pisar siempre el mismo registro
    //fseek(pFile, 0 * sizeof(Usuario), SEEK_SET);
    fwrite(&usuario, sizeof(Usuario), 1, pFile)==1;
    fclose(pFile);
    //return result;
}

Usuario UsuarioLogueado::leer() {
    Usuario usuario;
    FILE *pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return usuario;
    }
    fseek(pFile, 0 * sizeof(Usuario), SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, pFile);
    fclose(pFile);
    return usuario;
}

void UsuarioLogueado::actualizar(const Usuario &usuario) {
	FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    fwrite(&usuario, sizeof(Usuario), 1, pFile);

    fclose(pFile);
}

void UsuarioLogueado::mostrarUsuarioLogueado() {
    Usuario registro = this->leer();
    cout << "---------------" << endl;
	cout<<endl;
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout<<endl;
    cout << "---------------" << endl;
}

int UsuarioLogueado::leerIdLogueado() {
    Usuario registro = this->leer();
    return registro.getId();
}
