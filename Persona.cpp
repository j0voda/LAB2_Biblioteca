#include <iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stdio.h>

using namespace std;

#include "Persona.h"

// Constructor por defecto
Persona::Persona() {
    strcpy(_nombre, "");
    strcpy(_apellido, "");
}

// Constructor parametrizado
Persona::Persona(const string &nombre, const string &apellido) {
    strcpy(_nombre, nombre.c_str());
    strcpy(_apellido, apellido.c_str());
}

// Getters y Setters
string Persona::getNombre() const {
    string str = _nombre;
    return str;
}
void Persona::setNombre(const string &nombre) {
    strcpy(_nombre, nombre.c_str());
    //_nombre = strcpy(nombre);
}

string Persona::getApellido() const {
    string str = _apellido;
    return str;
}
void Persona::setApellido(const string &apellido) {
    strcpy(_apellido, apellido.c_str());
    //_apellido = strcpy(apellido);
}
