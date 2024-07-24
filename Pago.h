#pragma once
#include <string>

#include "Fecha.h"

using namespace std;

class Pago {
private:
    int _idPago;
    int _idUsuario;
    int _idMembresia;
    float _monto;
    Fecha _fecha;
    int _metodoPago;
    int _metodoPagoClave;

public:
    Pago();

    Pago(int idPago, int idUsuario, int idMembresia, float monto, const Fecha &fecha, int metodoPago, int metodoPagoClave);

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

    int getMetodoPago() const;
    void setMetodoPago(int metodoPago);

    int getMetodoPagoClave() const;
    void setMetodoPagoClave(int metodoPagoClave);
};
