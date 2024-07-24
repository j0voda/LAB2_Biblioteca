#pragma once

#include <iostream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

#include "Persona.h"


class Usuario : public Persona {
private:
    int _id;
    char _telefono[50];
    char _mail[50];
    char _clave[50];
    int _permisos; // 1: Bibliotecario 2: Cliente

public:
    Usuario();

    Usuario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);

    int getId() const;
    void setId(int id);

    string getTelefono() const;
    void setTelefono(const string &telefono);

    string getMail() const;
    void setMail(const string &mail);

    string getClave() const;
    void setClave(const string &clave);

    int getPermisos() const;
    void setPermisos(int permisos);
};
