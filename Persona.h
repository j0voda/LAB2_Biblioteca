#pragma once
#include <iostream>
#include <string>

using namespace std;


class Persona {
private:
    char _nombre[50];
    char _apellido[50];

public:
    // Constructor por defecto
    Persona();

    // Constructor parametrizado
    Persona(const string &nombre, const string &apellido);

    // Getters y Setters
    string getNombre() const;
    void setNombre(const string &nombre);

    string getApellido() const;
    void setApellido(const string &apellido);

};

