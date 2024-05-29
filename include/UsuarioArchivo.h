#pragma once
#include <fstream> //para trabajar con archivos
#include <iostream>
#include <vector>

#include "Usuario.h"

using namespace std;

class UsuarioArchivo {
private:
    string _nombreArchivo = "usuarios.dat";
public:
    bool guardar(const Usuario &usuario);
    bool modificar(int index, const Usuario &usuario);
    int buscarByID(int id);
    Usuario leer(int index);
    vector<Usuario> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();
};
