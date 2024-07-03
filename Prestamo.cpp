#include <iostream>
#include<cstdlib>
#include<cstring>
#include "Libro.h"
#include "Usuario.h"

#include "Prestamo.h"

using namespace std;

Prestamo::Prestamo() {
    //: _idPrestamo(0), _fechaPrestamo(""), _fechaDevolucion(""), _libro(), _usuario(), _estado(false)
    _idPrestamo = 0;
    strcpy(_fechaDevolucion, "");
    strcpy(_fechaPrestamo, "");
    //_fechaPrestamo = "";
    //_fechaDevolucion = "";
    _libro = new Libro();
    _usuario = new Usuario();
    _estado = false;
}

Prestamo::Prestamo(int idPrestamo, const string &fechaPrestamo, Libro *libro, Persona *usuario) {
    _idPrestamo = idPrestamo;
    strcpy(_fechaPrestamo, fechaPrestamo.c_str());
    _libro = libro;
    _usuario = usuario;
    _estado = true;
    // Por defecto la fecha de devolución es 7 días después de la fecha de préstamo
    // Aquí deberías implementar la lógica para calcular la fecha de devolución
    // Por simplicidad, usaremos una fecha fija para este ejemplo
    strcpy(_fechaDevolucion, "2024-06-03"); // Ejemplo de fecha fija
}

int Prestamo::getIdPrestamo() const {
    return _idPrestamo;
}

void Prestamo::setIdPrestamo(int idPrestamo) {
    _idPrestamo = idPrestamo;
}

string Prestamo::getFechaPrestamo() const {
    string str = _fechaPrestamo;
    return str;
}

void Prestamo::setFechaPrestamo(const string &fechaPrestamo) {
    strcpy(_fechaPrestamo, fechaPrestamo.c_str());
    //_fechaPrestamo = fechaPrestamo;
}

string Prestamo::getFechaDevolucion() const {
    string str = _fechaDevolucion;
    return str;
}

void Prestamo::setFechaDevolucion(const string &fechaDevolucion) {
    strcpy(_fechaDevolucion, fechaDevolucion.c_str());
    //_fechaDevolucion = fechaDevolucion;
}

Libro* Prestamo::getLibro() const {
    return _libro;
}

void Prestamo::setLibro(Libro *libro) {
    _libro = libro;
}

int Prestamo::getIdCliente() const {
    return _idCliente;
}

void Prestamo::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}

bool Prestamo::getEstado() const {
    return _estado;
}

void Prestamo::setEstado(bool estado) {
    _estado = estado;
}
