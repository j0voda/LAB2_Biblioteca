#include "Libro.h"

Libro::Libro() {
    _idLibro = 0;
    strcpy(_titulo, "");
    _anioPublicacion = 0;
    _ejemplares = 0;
    _disponibles = 0;
    _estado = false;
}

Libro::Libro(int idLibro, const string &titulo, const Autor &autor, const Categoria &categoria, int anioPublicacion, int ejemplares, int disponibles, bool estado){
    _idLibro = idLibro;
    strcpy(_titulo, titulo.c_str());
    _autor = autor;
    _categoria = categoria;
    _anioPublicacion = anioPublicacion;
    _ejemplares = ejemplares;
    _disponibles = disponibles;
    _estado = estado;
}

int Libro::getIdLibro() const {
    return _idLibro;
}
void Libro::setIdLibro(int idLibro) {
    _idLibro = idLibro;
}

string Libro::getTitulo() const {
    string str = _titulo;
    return str;
}
void Libro::setTitulo(const string &titulo) {
    strcpy(_titulo, titulo.c_str());
}

Autor Libro::getAutor() const {
    return _autor;
}
void Libro::setAutor(const Autor &autor) {
    _autor = autor;
}

Categoria Libro::getCategoria() const {
    return _categoria;
}
void Libro::setCategoria(const Categoria &categoria) {
    _categoria = categoria;
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
