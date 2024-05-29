#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "Libro.h"

using namespace std;


class LibroArchivo {
private:
    const string _nombreArchivo = "libros.dat";

public:
    bool guardar(const Libro &libro);
    bool modificar(int index, const Libro &libro);
    int buscarByID(int id);
    Libro leer(int index);
    vector<Libro> leerTodos();
    int getCantidadRegistros();
    int getNuevoID();

};
