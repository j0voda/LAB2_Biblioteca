#ifndef ADMIN_H
#define ADMIN_H

#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Usuario.h"

class Admin : public Usuario
{
    private:

    public:
        Admin();
        Admin(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);
};

#endif // ADMIN_H
