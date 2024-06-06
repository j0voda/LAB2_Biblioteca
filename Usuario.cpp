#include "Usuario.h"

Usuario::Usuario() : Persona() {
    _id = 0;
    _telefono = "";
    _mail = "";
    _clave = "";
    _permisos = 0;
}

Usuario::Usuario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Persona(nombre, apellido) {
    _id = id;
    _telefono = telefono;
    _mail = mail;
    _clave = clave;
    _permisos = permisos;
}

int Usuario::getId() const {
    return _id;
}
void Usuario::setId(int id) {
    _id = id;
}

string Usuario::getTelefono() const {
    return _telefono;
}
void Usuario::setTelefono(const string& telefono) {
    _telefono = telefono;
}

string Usuario::getMail() const {
    return _mail;
}
void Usuario::setMail(const string& mail) {
    _mail = mail;
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
