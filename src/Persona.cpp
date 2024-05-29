#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Persona.h"

// Constructor por defecto
Persona::Persona() {
    _nombre = "";
    _apellido = "";
    _telefono = "";
    _mail = "";
}

// Constructor parametrizado
Persona::Persona(const string& nombre, const string& apellido, const string& telefono, const string& mail) {
    _nombre = nombre;
    _apellido = apellido;
    _telefono = telefono;
    _mail = mail;
}

// Getters y Setters
string Persona::getNombre() const {
    return _nombre;
}
void Persona::setNombre(const string& nombre) {
    _nombre = nombre;
}

string Persona::getApellido() const {
    return _apellido;
}
void Persona::setApellido(const string& apellido) {
    _apellido = apellido;
}

string Persona::getTelefono() const {
    return _telefono;
}
void Persona::setTelefono(const string& telefono) {
    _telefono = telefono;
}

string Persona::getMail() const {
    return _mail;
}
void Persona::setMail(const string& mail) {
    _mail = mail;
}

