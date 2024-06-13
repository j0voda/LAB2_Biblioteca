#pragma once
#include <fstream> //para trabajar con archivos
#include <iostream>
#include <vector>

#include "Usuario.h"

using namespace std;

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
    int getNuevoID();
    void actualizar(const vector<Usuario> &usuarios);
};
