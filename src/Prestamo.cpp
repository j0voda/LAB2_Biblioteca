#include <iostream>
#include<cstdlib>
#include<cstring>

#include "Prestamo.h"

using namespace std;

Prestamo::Prestamo() : _idPrestamo(0), _fechaPrestamo(""), _fechaDevolucion(""), _libro(), _usuario(), _estado(false) {}

Prestamo::Prestamo(int idPrestamo, const string &fechaPrestamo, const Libro &libro, const Persona &usuario)
    : _idPrestamo(idPrestamo), _fechaPrestamo(fechaPrestamo), _libro(libro), _usuario(usuario), _estado(true) {
    // Por defecto la fecha de devolución es 7 días después de la fecha de préstamo
    // Aquí deberías implementar la lógica para calcular la fecha de devolución
    // Por simplicidad, usaremos una fecha fija para este ejemplo
    _fechaDevolucion = "2024-06-03"; // Ejemplo de fecha fija
}

int Prestamo::getIdPrestamo() const {
    return _idPrestamo;
}

void Prestamo::setIdPrestamo(int idPrestamo) {
    _idPrestamo = idPrestamo;
}

std::string Prestamo::getFechaPrestamo() const {
    return _fechaPrestamo;
}

void Prestamo::setFechaPrestamo(const std::string &fechaPrestamo) {
    _fechaPrestamo = fechaPrestamo;
}

std::string Prestamo::getFechaDevolucion() const {
    return _fechaDevolucion;
}

void Prestamo::setFechaDevolucion(const std::string &fechaDevolucion) {
    _fechaDevolucion = fechaDevolucion;
}

Libro Prestamo::getLibro() const {
    return _libro;
}

void Prestamo::setLibro(const Libro &libro) {
    _libro = libro;
}

Persona Prestamo::getUsuario() const {
    return _usuario;
}

void Prestamo::setUsuario(const Persona &usuario) {
    _usuario = usuario;
}

bool Prestamo::getEstado() const {
    return _estado;
}

void Prestamo::setEstado(bool estado) {
    _estado = estado;
}
