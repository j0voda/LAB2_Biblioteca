#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Categoria.h"
#include "AutorArchivo.h"

class CategoriaArchivo {
private:
    char _nombreArchivo[50] = "categorias.dat";

public:
    bool guardar(const Categoria &categoria);
    bool modificar(int index, const Categoria &categoria);
    int buscarById(int id);
    Categoria leer(int index);
    vector<Categoria> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();
    void actualizar(const vector<Categoria> &categorias);

};
