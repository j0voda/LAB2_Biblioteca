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
    Persona* _usuario;
    bool _estado; // true: activo, false: devuelto

public:
    Prestamo();
    Prestamo(int idPrestamo, const string &fechaPrestamo, Libro *libro, Persona *usuario);

    int getIdPrestamo() const;
    void setIdPrestamo(int idPrestamo);

    string getFechaPrestamo() const;
    void setFechaPrestamo(const string &fechaPrestamo);

    string getFechaDevolucion() const;
    void setFechaDevolucion(const string &fechaDevolucion);

    Libro* getLibro() const;
    void setLibro(Libro *libro);

    Persona* getUsuario() const;
    void setUsuario(Persona *usuario);

    bool getEstado() const;
    void setEstado(bool estado);
};
