#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "Pago.h"

using namespace std;

class PagoArchivo {
private:
    const string _nombreArchivo = "pagos.dat";

public:
    bool guardar(const Pago &pago);
    Pago leer(int index);
    vector<Pago> leerTodos();
    vector<Pago> leerPorIdUsuario(int idUsuario);
    int getCantidadRegistros();
    int getNuevoID();
};
