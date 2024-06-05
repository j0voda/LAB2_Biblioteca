#pragma once
#include "Libro.h"
#include "Persona.h"
#include <string>

class Prestamo {
private:
    int _idPrestamo;
    std::string _fechaPrestamo;
    std::string _fechaDevolucion;
    Libro _libro;
    Persona _usuario;
    bool _estado; // true: activo, false: devuelto

public:
    Prestamo();
    Prestamo(int idPrestamo, const std::string &fechaPrestamo, const Libro &libro, const Persona &usuario);

    int getIdPrestamo() const;
    void setIdPrestamo(int idPrestamo);

    std::string getFechaPrestamo() const;
    void setFechaPrestamo(const std::string &fechaPrestamo);

    std::string getFechaDevolucion() const;
    void setFechaDevolucion(const std::string &fechaDevolucion);

    Libro getLibro() const;
    void setLibro(const Libro &libro);

    Persona getUsuario() const;
    void setUsuario(const Persona &usuario);

    bool getEstado() const;
    void setEstado(bool estado);
};
