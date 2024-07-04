#pragma once
#include <string>

using namespace std;

#include "Libro.h"
#include "Fecha.h"
#include "Cliente.h"

class Prestamo {
private:
    int _idPrestamo;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;
    Libro _libro;
    Cliente _cliente;
    bool _devuelto;

public:
    Prestamo();
    Prestamo(int idPrestamo, const Fecha &fechaPrestamo, const Fecha &fechaDevolucion, const Libro &libro, const Cliente &cliente, bool devuelto);

    int getIdPrestamo() const;
    void setIdPrestamo(int idPrestamo);

    Fecha getFechaPrestamo() const;
    void setFechaPrestamo(const Fecha &fechaPrestamo);

    Fecha getFechaDevolucion() const;
    void setFechaDevolucion(const Fecha &fechaDevolucion);

    Libro getLibro() const;
    void setLibro(const Libro &libro);

    Cliente getCliente() const;
    void setCliente(const Cliente &cliente);

    bool getDevuelto() const;
    void setDevuelto(bool devuelto);

};
