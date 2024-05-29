#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Usuario.h"

// Constructor por defecto
Usuario::Usuario() : Persona() {
    _id = 0;
    _clave = "";
    _permisos = 0;
}

// Constructor parametrizado
Usuario::Usuario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Persona(nombre, apellido, telefono, mail) {
    _id = id;
    _clave = clave;
    _permisos = permisos;
}

// Getters y Setters
int Usuario::getId() const {
    return _id;
}
void Usuario::setId(int id) {
    _id = id;
}

string Usuario::getClave() const {
    return _clave;
}
void Usuario::setClave(const string &clave) {
    _clave = clave;
}

int Usuario::getPermisos() const {
    return _permisos;
}
void Usuario::setPermisos(int permisos) {
    _permisos = permisos;
}
