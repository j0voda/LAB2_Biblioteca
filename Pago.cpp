#include "Pago.h"

using namespace std;

Pago::Pago(){
    _idPago = 0;
    _idUsuario = 0;
    _monto = 0.0f;
    _fecha = Fecha();
    _metodoPago = 0;
}

Pago::Pago(int idPago, int idUsuario, float monto, const Fecha &fecha, int metodoPago){
    _idPago = idPago;
    _idUsuario = idUsuario;
    _monto = monto;
    _fecha = fecha;
    _metodoPago = metodoPago;
}

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
