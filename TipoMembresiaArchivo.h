#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "TipoMembresia.h"

class TipoMembresiaArchivo {
private:
    char _nombreArchivo[50] = "TipoMembresias.dat";

public:
    bool guardar(const TipoMembresia& tipoMembresia);
    bool modificar(int index, const TipoMembresia& tipoMembresia);
    int buscarById(int id);
    TipoMembresia leer(int index);
    vector<TipoMembresia> leerTodas();
    int getCantidadRegistros();
    int getNuevoID();
    void actualizar(const vector<TipoMembresia> &tipoMmembresias);
};
