#pragma once
#include <iostream>

#include "Usuario.h"
#include "UsuarioManager.h"
#include "Membresia.h"
#include "MembresiaManager.h"
#include "Fecha.h"

using namespace std;

class Cliente : public Usuario {
private:
    bool _membresia;
    MembresiaManager _membresiaManager;
    Usuario _usuario;

public:
    Cliente();

    Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string& clave, int permisos, bool membresia);

    bool getMembresia() const;
    void setMembresia(bool membresia);

    void asignarMembresia(MembresiaManager &_membresiaManager);
    void menuCliente();
};
