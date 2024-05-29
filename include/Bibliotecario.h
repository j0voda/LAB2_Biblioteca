#pragma once
#include "Usuario.h"

class Bibliotecario : public Usuario {
public:
    // Constructor por defecto
    Bibliotecario();

    // Constructor parametrizado
    Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);
};
