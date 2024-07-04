#pragma once
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#include "Usuario.h"


class UsuarioArchivo {
private:
    char _nombreArchivo[50] = "usuarios.dat";

public:
    bool guardar(const Usuario &usuario);
    bool modificar(int index, const Usuario &usuario);
    int buscarById(int id);
    Usuario leer(int index);
    vector<Usuario> leerTodos();
    vector<Usuario> leerPorPermisos(int permisos);
    int getCantidadRegistros();
    int getCantidadRegistrosPorPermiso(int permisos);
    int getNuevoID();
    void actualizar(const vector<Usuario> &usuarios);
};
