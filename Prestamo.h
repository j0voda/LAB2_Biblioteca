#pragma once
#include "Libro.h"
#include "Persona.h"
#include <string>

using namespace std;

class Prestamo {
private:
    int _idPrestamo;
    string _fechaPrestamo;
    string _fechaDevolucion;
    Libro _libro;
    Persona _usuario;
    bool _estado; // true: activo, false: devuelto

public:
    Prestamo();
    Prestamo(int idPrestamo, const string &fechaPrestamo, const Libro &libro, const Persona &usuario);

    int getIdPrestamo() const;
    void setIdPrestamo(int idPrestamo);

    string getFechaPrestamo() const;
    void setFechaPrestamo(const string &fechaPrestamo);

    string getFechaDevolucion() const;
    void setFechaDevolucion(const string &fechaDevolucion);

    Libro getLibro() const;
    void setLibro(const Libro &libro);

    Persona getUsuario() const;
    void setUsuario(const Persona &usuario);

    bool getEstado() const;
    void setEstado(bool estado);
};
