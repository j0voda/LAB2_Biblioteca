#include "Membresia.h"

Membresia::Membresia(){
    _id = 0;
    _idCliente = 0;
    _tipoMembresia = TipoMembresia();
    _fechaInicio = Fecha();
    _fechaFin = Fecha();
    _estado = false;
}

Membresia::Membresia(int id, int idCliente, const TipoMembresia &tipoMembresia, const Fecha &fechaInicio, const Fecha &fechaFin, bool estado){
    _id = id;
    _idCliente = idCliente;
    _tipoMembresia = tipoMembresia;
    _fechaInicio = fechaInicio;
    _fechaFin = fechaFin;;
    _estado = estado;
}

int Membresia::getId() const{
    return _id;
}
void Membresia::setId(int id){
    _id = id;
}

int Membresia::getIdCliente() const {
    return _idCliente;
}
void Membresia::setIdCliente(int idUsuario){
    _idCliente = idUsuario;
}

TipoMembresia Membresia::getTipoMembresia() const{
    return _tipoMembresia;
}
void Membresia::setTipoMembresia(const TipoMembresia &tipoMembresia){
    _tipoMembresia = tipoMembresia;
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


