#pragma once
#include <string>

#include "Fecha.h"

using namespace std;

class Pago {
private:
    int _idPago;
    int _idUsuario;
    float _monto;
    Fecha _fecha;
    int _metodoPago;

public:
    // Constructor por defecto
    Pago();

    // Constructor parametrizado
    Pago(int idPago, int idUsuario, float monto, const Fecha &fecha, int metodoPago);

    // Getters y Setters
    int getIdPago() const;
    void setIdPago(int idPago);

    int getIdUsuario() const;
    void setIdUsuario(int idUsuario);

    float getMonto() const;
    void setMonto(float monto);

    Fecha getFecha() const;
    void setFecha(const Fecha &fecha);

    int getMetodoPago() const;
    void setMetodoPago(int metodoPago);
};
