#include "Cliente.h"
#include<string>
#include<stdio.h>

using namespace std;

Cliente::Cliente() : Usuario() {
    _membresia = false;
}

Cliente::Cliente(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos, bool membresia)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
    _membresia = membresia;
}

bool Cliente::getMembresia() const {
    return _membresia;
}
void Cliente::setMembresia(bool membresia) {
    _membresia = membresia;
}

void Cliente::asignarMembresia(){
    int tipoMembresia;
    cout << "Ingrese su membresía (1 para Básica, 2 para Premium): ";
    cin >> tipoMembresia;

    if (tipoMembresia < 1 || tipoMembresia > 2){
        cout << "Membresia incorrecta. No se puede registrar como cliente." << endl;
        return;
    }

    Fecha fechaInicio = Fecha::obtenerFechaActual();
    Fecha fechaFin = fechaInicio.sumarMes(1);

    Membresia membresia(_membresiaManager.getNuevoID(), this->getId(), tipoMembresia, fechaInicio, fechaFin, true);
    _membresiaManager.guardarMembresia(membresia);

    cout << "Membresía asignada con éxito. Cliente registrado" << endl;
}

void Cliente::menuCliente(){
    cout<<"ESTE ES EL MENU DEL CLIENTE";
}
