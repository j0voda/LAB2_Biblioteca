#pragma once
#include "Libro.h"
#include "Persona.h"
#include <string>

using namespace std;

class Prestamo {
private:
    int _idPrestamo;
    char _fechaPrestamo[50];
    char _fechaDevolucion[50];
    Libro* _libro;
    int _idCliente;
    bool _estado; // true: activo, false: devuelto

public:
    Prestamo();
    Prestamo(int idPrestamo, const string &fechaPrestamo, Libro *libro, int idCliente);

    int getIdPrestamo() const;
    void setIdPrestamo(int idPrestamo);

    string getFechaPrestamo() const;
    void setFechaPrestamo(const string &fechaPrestamo);

    string getFechaDevolucion() const;
    void setFechaDevolucion(const string &fechaDevolucion);

    Libro* getLibro() const;
    void setLibro(Libro *libro);

    int getIdCliente() const;
    void setIdCliente(int idCliente);

    bool getEstado() const;
    void setEstado(bool estado);
};
