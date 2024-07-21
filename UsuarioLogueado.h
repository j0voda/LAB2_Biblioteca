#pragma once
#ifndef USUARIOLOGUEADO_H
#define USUARIOLOGUEADO_H

using namespace std;

#include "Usuario.h"

class UsuarioLogueado
{
    private:
        char _nombreArchivo[50] = "usuariologueado.dat";

    public:
        void guardar(const Usuario &usuario);
        Usuario leer();
        void actualizar(const Usuario &usuario);
        void mostrarUsuarioLogueado();
        void limpiar();
        int leerIdLogueado();
};

#endif // USUARIOLOGUEADO_H
