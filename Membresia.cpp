#include "Membresia.h"

Membresia::Membresia(){
    _id = 0;
    _idCliente = 0;
    _tipo = 0;
    _fechaInicio = Fecha();
    _fechaFin = Fecha();
    _estado = false;
}

Membresia::Membresia(int id, int idCliente,int tipo, const Fecha &fechaInicio, const Fecha &fechaFin, bool estado){
    _id = id;
    _idCliente = idCliente;
    _tipo = tipo;
    _fechaInicio = fechaInicio;
    _fechaFin = fechaFin;
    _estado = estado;
}

int Membresia::getId() const{
    return _id;
}
void Membresia::setId(int id){
    _id = id;
}

int Membresia::getIdCliente() const{
    return _idCliente;
}
void Membresia::setIdCliente(int idCliente){
    _idCliente = idCliente;
}

int Membresia::getTipo() const{
    return _tipo;
}
void Membresia::setTipo(int tipo){
    _tipo = tipo;
}

Fecha Membresia::getFechaInicio() const{
    return _fechaInicio;
}
void Membresia::setFechaInicio(const Fecha &fechaInicio){
    _fechaInicio = fechaInicio;
}

Fecha Membresia::getFechaFin() const{
    return _fechaFin;
}
void Membresia::setFechaFin(const Fecha &fechaFin){
    _fechaFin = fechaFin;
}

bool Membresia::getEstado() const{
    return _estado;
}
void Membresia::setEstado(bool estado){
    _estado = estado;
}


