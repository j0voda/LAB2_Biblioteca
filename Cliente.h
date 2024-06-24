#pragma once
#include <iostream>

using namespace std;

#include "Usuario.h"
//#include "UsuarioManager.h"
#include "Membresia.h"
//#include "MembresiaManager.h"

#include "Fecha.h"


class Cliente : public Usuario {
private:
    bool _membresia;
    //MembresiaManager _membresiaManager;
    //UsuarioArchivo _usuarioArchivo;
    //Usuario _usuario;

public:
    Cliente();

    Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string& clave, int permisos, bool membresia);

    bool getMembresia() const;
    void setMembresia(bool membresia);
};
