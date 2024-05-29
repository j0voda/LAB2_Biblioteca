#pragma once
#include <iostream>
#include <string>

using namespace std;


class Persona {
private:
    string _nombre;
    string _apellido;
    string _telefono;
    string _mail;

public:
    // Constructor por defecto
    Persona();

    // Constructor parametrizado
    Persona(const string& nombre, const string& apellido, const string& telefono, const string& mail);

    // Getters y Setters
    string getNombre() const;
    void setNombre(const string& nombre);

    string getApellido() const;
    void setApellido(const string& apellido);

    string getTelefono() const;
    void setTelefono(const string& telefono);

    string getMail() const;
    void setMail(const string& mail);
};

