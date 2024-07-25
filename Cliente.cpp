#include "Cliente.h"


Cliente::Cliente() : Usuario() {}

Cliente::Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos, const Membresia &membresia)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
    _membresia = membresia;
}

Membresia Cliente::getMembresia() const {
    return _membresia;
}
void Cliente::setMembresia(const Membresia &membresia) {
    _membresia = membresia;
}

