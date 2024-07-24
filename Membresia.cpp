#include "Membresia.h"

Membresia::Membresia(){
    id = 0;
    cliente = Usuario();
    tipoMembresia = TipoMembresia();
    fechaInicio = Fecha();
    fechaFin = Fecha();
    //pago = Pago();
    estado = false;
}

Membresia::Membresia(int _id, const Usuario &_cliente, const TipoMembresia &_tipoMembresia, const Fecha &_fechaInicio, const Fecha &_fechaFin, /*const Pago &_pago,*/ bool _estado){
    id = _id;
    cliente = _cliente;
    tipoMembresia = _tipoMembresia;
    fechaInicio = _fechaInicio;
    fechaFin = _fechaFin;
    //pago = _pago;
    estado = _estado;
}

int Membresia::getId() const{
    return id;
}
void Membresia::setId(int _id){
    id = _id;
}

Usuario Membresia::getCliente() const {
    return cliente;
}
void Membresia::setCliente(const Usuario &_cliente){
    cliente = _cliente;
}

TipoMembresia Membresia::getTipoMembresia() const{
    return tipoMembresia;
}
void Membresia::setTipoMembresia(const TipoMembresia &_tipoMembresia){
    tipoMembresia = _tipoMembresia;
}

Fecha Membresia::getFechaInicio() const{
    return fechaInicio;
}
void Membresia::setFechaInicio(const Fecha &_fechaInicio){
    fechaInicio = _fechaInicio;
}

Fecha Membresia::getFechaFin() const{
    return fechaFin;
}
void Membresia::setFechaFin(const Fecha &_fechaFin){
    fechaFin = _fechaFin;
}
/*
Pago Membresia::getPago() const{
    return pago;
}
void Membresia::setPago(const Pago &_pago){
    pago = _pago;
}
*/
bool Membresia::getEstado() const{
    return estado;
}
void Membresia::setEstado(bool _estado){
    estado = _estado;
}


