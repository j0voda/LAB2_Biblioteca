#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Persona.h"

// Constructor por defecto
Persona::Persona() {
    _nombre = "";
    _apellido = "";
}

// Constructor parametrizado
Persona::Persona(const string& nombre, const string& apellido) {
    _nombre = nombre;
    _apellido = apellido;
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
