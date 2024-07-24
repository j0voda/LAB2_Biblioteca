#pragma once
#include <string>
#include "Fecha.h"
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

class Pago {
private:
    int _idPago;
    int _idUsuario;
    int _idMembresia;
    float _monto;
    Fecha _fecha;
    char _metodoPago[17];
    char _metodoPagoClave[4];

public:
    // Constructor por defecto
    Pago();

    // Constructor parametrizado
    Pago(int idPago, int idUsuario, int idMembresia, float monto, const Fecha &fecha, const string &metodoPago, const string &metodoPagoClave);

    // Getters y Setters
    int getIdPago() const;
    void setIdPago(int idPago);

    int getIdUsuario() const;
    void setIdUsuario(int idUsuario);

    int getIdMembresia() const;
    void setIdMembresia(int idMembresia);

    float getMonto() const;
    void setMonto(float monto);

    Fecha getFecha() const;
    void setFecha(const Fecha &fecha);

    string getMetodoPago() const;
    void setMetodoPago(const string &metodoPago);

    string getMetodoPagoClave() const;
    void setMetodoPagoClave(const string &metodoPagoClave);
};
