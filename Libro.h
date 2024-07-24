#pragma once
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

#include "AutorArchivo.h"
#include "CategoriaArchivo.h"

class Libro {
private:
    int _idLibro;
    char _titulo[50];
    Autor _autor;
    Categoria _categoria;
    int _anioPublicacion;
    int _ejemplares;
    int _disponibles;
    bool _estado;

public:
    Libro();

    Libro(int idLibro, const string &titulo, const Autor &autor, const Categoria &categoria, int anioPublicacion, int ejemplares, int disponibles, bool estado);

    int getIdLibro() const;
    void setIdLibro(int idLibro);

    string getTitulo() const;
    void setTitulo(const string &titulo);

    Autor getAutor() const;
    void setAutor(const Autor &autor);

    Categoria getCategoria() const;
    void setCategoria(const Categoria &categoria);

    int getAnioPublicacion() const;
    void setAnioPublicacion(int anioPublicacion);

    int getEjemplares() const;
    void setEjemplares(int ejemplares);

    int getDisponibles() const;
    void setDisponibles(int disponibles);

    bool getEstado() const;
    void setEstado(bool estado);
};
