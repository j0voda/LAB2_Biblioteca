#include "Prestamo.h"

Prestamo::Prestamo() {
    _idPrestamo = 0;
    _devuelto = false;
}

Prestamo::Prestamo(int idPrestamo, const Fecha &fechaPrestamo, const Fecha &fechaDevolucion, const Libro &libro, const Usuario &cliente, bool devuelto) {
    _idPrestamo = idPrestamo;
    _fechaPrestamo = fechaPrestamo;
    _fechaDevolucion = fechaDevolucion;
    _libro = libro;
    _cliente = cliente;
    _devuelto = devuelto;
    // Por defecto la fecha de devolución es 7 días después de la fecha de préstamo
    // lógica para calcular la fecha de devolución
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

Usuario Prestamo::getCliente() const {
    return _cliente;
}
void Prestamo::setCliente(const Usuario &cliente) {
    _cliente = cliente;
}

bool Prestamo::getDevuelto() const {
    return _devuelto;
}
void Prestamo::setDevuelto(bool devuelto) {
    _devuelto = devuelto;
}
