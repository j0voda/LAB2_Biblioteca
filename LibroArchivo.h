#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Libro.h"

class LibroArchivo {
private:
    char _nombreArchivo[50] = "libros.dat";

public:
    bool guardar(const Libro &libro);
    bool modificar(int index, const Libro &libro);
    int buscarById(int id);
    Libro leer(int index);
    vector<Libro> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();
    void actualizar(const vector<Libro> &libros);

};
