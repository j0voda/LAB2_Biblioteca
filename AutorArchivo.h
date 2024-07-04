#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Autor.h"

class AutorArchivo {
private:
    char _nombreArchivo[50] = "autores.dat";

public:
    bool guardar(const Autor &autor);
    bool modificar(int index, const Autor &autor);
    int buscarById(int id);
    Autor leer(int index);
    vector<Autor> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();
    void actualizar(const vector<Autor>& autores);

};
