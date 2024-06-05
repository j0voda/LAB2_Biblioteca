#pragma once

#include "Usuario.h"
#include "Membresia.h"

class Cliente : public Usuario {
private:
    bool _membresia;

public:
    // Constructor por defecto
    Cliente();

    // Constructor parametrizado
    Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string& clave, int permisos, bool membresia);

    // Getters y Setters
    bool getMembresia() const;
    void setMembresia(bool membresia);
};
