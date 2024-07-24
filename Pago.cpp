#include "Pago.h"

using namespace std;

Pago::Pago(){
    _idPago = 0;
    _idUsuario = 0;
    _idMembresia = 0;
    _monto = 0.0f;
    _fecha = Fecha();
    strcpy(_metodoPago, "");
    strcpy(_metodoPagoClave, "");
}

Pago::Pago(int idPago, int idUsuario, int idMembresia, float monto, const Fecha &fecha, const string &metodoPago, const string &metodoPagoClave){
    _idPago = idPago;
    _idUsuario = idUsuario;
    _idMembresia = idMembresia;
    _monto = monto;
    _fecha = fecha;
    strcpy(_metodoPago, metodoPago.c_str());
    strcpy(_metodoPagoClave, metodoPagoClave.c_str());
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

string Pago::getMetodoPago() const{
    string str = _metodoPago;
    return str;
}
void Pago::setMetodoPago(const string &metodoPago){
    strcpy(_metodoPago, metodoPago.c_str());
}

string Pago::getMetodoPagoClave() const{
    string str = _metodoPagoClave;
    return str;
}
void Pago::setMetodoPagoClave(const string &metodoPagoClave){
    strcpy(_metodoPagoClave, metodoPagoClave.c_str());
}
