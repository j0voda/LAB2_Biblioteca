#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Usuario.h"
#include "Membresia.h"
#include "Fecha.h"


class Cliente : public Usuario {
private:
    Membresia _membresia;
    //MembresiaManager _membresiaManager;
    //UsuarioArchivo _usuarioArchivo;
    //Usuario _usuario;

public:
    Cliente();

    Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string& clave, int permisos, const Membresia &membresia);

    Membresia getMembresia() const;
    void setMembresia(const Membresia &membresia);
};
