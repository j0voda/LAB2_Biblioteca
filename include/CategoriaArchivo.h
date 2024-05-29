#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "Categoria.h"

using namespace std;

class CategoriaArchivo {
private:
    const string _nombreArchivo = "categorias.dat";

public:
    bool guardar(const Categoria &categoria);
    bool modificar(int index, const Categoria &categoria);
    int buscarByID(int id);
    Categoria leer(int index);
    vector<Categoria> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();

};
