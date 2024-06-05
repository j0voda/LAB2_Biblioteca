#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "Categoria.h"
#include "AutorArchivo.h"

using namespace std;

class CategoriaArchivo {
private:
    const string _nombreArchivo = "categorias.dat";

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
