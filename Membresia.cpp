#include "Membresia.h"

Membresia::Membresia(){
    _id = 0;
    //_cliente = 0;
    _tipo = 0;
    _fechaInicio = Fecha();
    _fechaFin = Fecha();
    _estado = false;
}

Membresia::Membresia(int id,/*const Cliente &cliente*/ int tipo, const Fecha &fechaInicio, const Fecha &fechaFin, bool estado){
    _id = id;
    //_cliente = cliente;
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
/*
Cliente Membresia::getCliente() const {
    return _cliente;
}
void Membresia::setIdUsuario(const Cliente &cliente){
    _cliente = cliente;
}
*/
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


