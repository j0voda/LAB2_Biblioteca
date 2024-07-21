#include "Pago.h"

using namespace std;

Pago::Pago(){
    _idPago = 0;
    _idUsuario = 0;
    _idMembresia = 0;
    _monto = 0.0f;
    _fecha = Fecha();
    _metodoPago = 0;
    _metodoPagoClave = 0;
}

Pago::Pago(int idPago, int idUsuario, int idMembresia, float monto, const Fecha &fecha, int metodoPago, int metodoPagoClave){
    _idPago = idPago;
    _idUsuario = idUsuario;
    _idMembresia = idMembresia;
    _monto = monto;
    _fecha = fecha;
    _metodoPago = metodoPago;
    _metodoPagoClave = metodoPagoClave;
}

//Getters y Setters

int Pago::getIdPago() const {
    return _idPago;
}
void Pago::setIdPago(int idPago) {
    _idPago = idPago;
}

int Pago::getIdUsuario() const {
    return _idUsuario;
}
void Pago::setIdUsuario(int idUsuario) {
    _idUsuario = idUsuario;
}

int Pago::getIdMembresia() const {
    return _idMembresia;
}
void Pago::setIdMembresia(int idMembresia) {
    _idMembresia = idMembresia;
}

float Pago::getMonto() const{
    return _monto;
}
void Pago::setMonto(float monto){
    _monto = monto;
}

Fecha Pago::getFecha() const{
    return _fecha;
}
void Pago::setFecha(const Fecha &fecha){
    _fecha = fecha;
}

int Pago::getMetodoPago() const{
    return _metodoPago;
}
void Pago::setMetodoPago(int metodoPago){
    _metodoPago = metodoPago;
}

int Pago::getMetodoPagoClave() const{
    return _metodoPagoClave;
}
void Pago::setMetodoPagoClave(int metodoPagoClave){
    _metodoPagoClave = metodoPagoClave;
}
