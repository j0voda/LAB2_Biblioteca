#include "Prestamo.h"

Prestamo::Prestamo() {
    _idPrestamo = 0;
    _devuelto = false;
}

Prestamo::Prestamo(int idPrestamo, const Fecha &fechaPrestamo, const Fecha &fechaDevolucion, const Libro &libro, const Cliente &cliente, bool devuelto) {
    _idPrestamo = idPrestamo;
    _fechaPrestamo = fechaPrestamo;
    _fechaDevolucion = fechaDevolucion;
    _libro = libro;
    _cliente = cliente;
    _devuelto = devuelto;
    // Por defecto la fecha de devoluci�n es 7 d�as despu�s de la fecha de pr�stamo
    // l�gica para calcular la fecha de devoluci�n
}

int Prestamo::getIdPrestamo() const {
    return _idPrestamo;
}
void Prestamo::setIdPrestamo(int idPrestamo) {
    _idPrestamo = idPrestamo;
}

Fecha Prestamo::getFechaPrestamo() const {
    return _fechaPrestamo;
}
void Prestamo::setFechaPrestamo(const Fecha &fechaPrestamo) {
    _fechaPrestamo = fechaPrestamo;
}

Fecha Prestamo::getFechaDevolucion() const {
    return _fechaDevolucion;
}
void Prestamo::setFechaDevolucion(const Fecha &fechaDevolucion) {
    _fechaDevolucion = fechaDevolucion;
}

Libro Prestamo::getLibro() const {
    return _libro;
}
void Prestamo::setLibro(const Libro &libro) {
    _libro = libro;
}

Cliente Prestamo::getCliente() const {
    return _cliente;
}
void Prestamo::setCliente(const Cliente &cliente) {
    _cliente = cliente;
}

bool Prestamo::getDevuelto() const {
    return _devuelto;
}
void Prestamo::setDevuelto(bool devuelto) {
    _devuelto = devuelto;
}
