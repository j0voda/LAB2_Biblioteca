#pragma once
#include <string>

#include "Fecha.h"

using namespace std;

class Membresia{
private:
    int _id;
    int _idCliente;
    int _tipo; /// 1- Membresia Basica 2- Membresia Premium
    Fecha _fechaInicio;
    Fecha _fechaFin;
    bool _estado; /// Vencido/Activo

public:
    Membresia();

    Membresia(int id, int idCliente, int tipo, const Fecha &fechaInicio, const Fecha &fechaFin, bool estado);

    int getId() const;
    void setId(int id);

    int getIdCliente();
    void setIdCliente(int idCliente);

    int getTipo() const;
    void setTipo(int tipo);

    Fecha getFechaInicio() const;
    void setFechaInicio(const Fecha &fechaInicio);

    Fecha getFechaFin() const;
    void setFechaFin(const Fecha &fechaFin);

    bool getEstado() const;
    void setEstado(bool estado);

};
