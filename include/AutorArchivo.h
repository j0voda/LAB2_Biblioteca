#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "Autor.h"

using namespace std;

class AutorArchivo {
private:
    const string _nombreArchivo = "Autor.dat";

public:
    bool guardar(const Autor &autor);
    bool modificar(int index, const Autor &autor);
    int buscarByID(int id);
    Autor leer(int index);
    vector<Autor> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();

};
