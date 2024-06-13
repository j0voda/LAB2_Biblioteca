#pragma once
#include <iostream>

#include "AutorArchivo.h"
#include "CategoriaArchivo.h"

using namespace std;

class Libro {
private:
    int _idLibro;
    char _titulo[50];
    Autor _idAutor;
    Categoria _idCategoria;
    int _anioPublicacion;
    int _ejemplares;
    int _disponibles;
    bool _estado;

public:
    // Constructor por defecto
    Libro();

    // Constructor parametrizado
    Libro(int idLibro, const string &titulo, const Autor &autor, const Categoria &categoria, int anioPublicacion, int ejemplares, int disponibles, bool estado);

    // Getters y Setters
    int getIdLibro() const;
    void setIdLibro(int idLibro);

    string getTitulo() const;
    void setTitulo(const string &titulo);

    Autor getIdAutor() const;
    void setIdAutor(const Autor &autor);

    Categoria getIdCategoria() const;
    void setIdCategoria(const Categoria &categoria);

    int getAnioPublicacion() const;
    void setAnioPublicacion(int anioPublicacion);

    int getEjemplares() const;
    void setEjemplares(int ejemplares);

    int getDisponibles() const;
    void setDisponibles(int disponibles);

    bool getEstado() const;
    void setEstado(bool estado);
};
