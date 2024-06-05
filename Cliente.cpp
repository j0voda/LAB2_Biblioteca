#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Cliente.h"

// Constructor por defecto
Cliente::Cliente() : Usuario() {
    _membresia = false;
}

// Constructor parametrizado
Cliente::Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos, bool membresia)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
    _membresia = membresia;
}

// Getters y Setters
bool Cliente::getMembresia() const {
    return _membresia;
}
void Cliente::setMembresia(bool membresia) {
    _membresia = membresia;
}

