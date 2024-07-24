#pragma once
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

#include "Fecha.h"
#include "UsuarioArchivo.h"
#include "TipoMembresiaArchivo.h"


class Membresia{
private:
    int id;
    Usuario cliente;
    TipoMembresia tipoMembresia; /// 1- Membresia Basica 2- Membresia Premium  ...
    Fecha fechaInicio;
    Fecha fechaFin;
    //Pago pago;
    bool estado; /// Vencido/Activo

public:
    Membresia();

    Membresia(int id, const Usuario &cliente, const TipoMembresia &tipoMembresia, const Fecha &fechaInicio, const Fecha &fechaFin, /*const Pago &pago,*/ bool estado);

    int getId() const;
    void setId(int id);

    TipoMembresia getTipoMembresia() const;
    void setTipoMembresia(const TipoMembresia &tipoMembresia);

    Usuario getCliente() const;
    void setCliente(const Usuario &cliente);

    Fecha getFechaInicio() const;
    void setFechaInicio(const Fecha &fechaInicio);

    Fecha getFechaFin() const;
    void setFechaFin(const Fecha &fechaFin);
/*
    Pago getPago() const;
    void setPago(const Pago &pago);
*/
    bool getEstado() const;
    void setEstado(bool estado);

};
