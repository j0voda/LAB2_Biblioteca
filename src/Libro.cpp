#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Libro.h"

// Constructor por defecto
Libro::Libro() {
    _idLibro = 0;
    _titulo = "";
    _anioPublicacion = 0;
    _ejemplares = 0;
    _disponibles = 0;
    _estado = false;
}

// Constructor parametrizado
Libro::Libro(int idLibro, const string &titulo, const Autor &idAutor, const Categoria &idCategoria, int anioPublicacion, int ejemplares, int disponibles, bool estado) {
    _idLibro = idLibro;
    _titulo = titulo;
    _idAutor = idAutor;
    _idCategoria = idCategoria;
    _anioPublicacion = anioPublicacion;
    _ejemplares = ejemplares;
    _disponibles = disponibles;
    _estado = estado;
}

// Getters y Setters
int Libro::getIdLibro() const {
    return _idLibro;
}
void Libro::setIdLibro(int idLibro) {
    _idLibro = idLibro;
}

string Libro::getTitulo() const {
    return _titulo;
}
void Libro::setTitulo(const string &titulo) {
    _titulo = titulo;
}

Autor Libro::getIdAutor() const {
    return _idAutor;
}
void Libro::setIdAutor(const Autor &idAutor) {
    _idAutor = idAutor;
}

Categoria Libro::getIdCategoria() const {
    return _idCategoria;
}
void Libro::setIdCategoria(const Categoria &idCategoria) {
    _idCategoria = idCategoria;
}

int Libro::getAnioPublicacion() const {
    return _anioPublicacion;
}
void Libro::setAnioPublicacion(int anioPublicacion) {
    _anioPublicacion = anioPublicacion;
}

int Libro::getEjemplares() const {
    return _ejemplares;
}
void Libro::setEjemplares(int ejemplares) {
    _ejemplares = ejemplares;
}

int Libro::getDisponibles() const {
    return _disponibles;
}
void Libro::setDisponibles(int disponibles) {
    _disponibles = disponibles;
}

bool Libro::getEstado() const {
    return _estado;
}
void Libro::setEstado(bool estado) {
    _estado = estado;
}
