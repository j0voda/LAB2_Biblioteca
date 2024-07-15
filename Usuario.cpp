#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

#include "Usuario.h"

Usuario::Usuario() : Persona() {
    _id = 0;
    strcpy(_telefono, "");
    strcpy(_mail, "");
    strcpy(_clave, "");
    _permisos = 0;
}

Usuario::Usuario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Persona(nombre, apellido) {
    _id = id;
    strcpy(_telefono, telefono.c_str());
    strcpy(_mail, mail.c_str());
    strcpy(_clave, clave.c_str());
    _permisos = permisos;
}

int Usuario::getId() const {
    return _id;
}
void Usuario::setId(int id) {
    _id = id;
}

string Usuario::getTelefono() const {
    string str = _telefono;
    return str;
}
void Usuario::setTelefono(const string &telefono) {
    strcpy(_telefono, telefono.c_str());
    //_telefono = strcpy(telefono);
}

string Usuario::getMail() const {
    string str = _mail;
    return str;
}
void Usuario::setMail(const string &mail) {
    strcpy(_mail, mail.c_str());
    //_mail = strcpy(mail);
}

string Usuario::getClave() const {
    string str = _clave;
    return str;
}
void Usuario::setClave(const string &clave) {
    strcpy(_clave, clave.c_str());
    //_clave = strcpy(clave);
}

int Usuario::getPermisos() const {
    return _permisos;
}
void Usuario::setPermisos(int permisos) {
    _permisos = permisos;
}
