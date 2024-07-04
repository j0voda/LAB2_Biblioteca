#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "Membresia.h"

using namespace std;

class MembresiaArchivo {
private:
    char _nombreArchivo[50] = "membresias.dat";

public:
    bool guardar(const Membresia& membresia);
    bool modificar(int index, const Membresia& membresia);
    int buscarById(int id);
    Membresia leer(int index);
    vector<Membresia> leerTodas();
    int getCantidadRegistros();
    int getNuevoID();
    int buscarPorIdUsuario(int idUsuario);
    void actualizar(const vector<Membresia> &membresias);
};
