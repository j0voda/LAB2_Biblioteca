#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Categoria.h"

Categoria::Categoria(){
    _idCategoria= 0;
    _nombre = "";
}

Categoria::Categoria(int id, const string &nombre){
    _id=id;
    _nombre=nombre;
}

int Categoria::getIdCategoria() const {
    return _id;
}
void Categoria::setIdCategoria(int id) {
    _id = id;
}

string Categoria::getNombre() const {
    return _nombre;
}
void Categoria::setNombre(const string &nombre) {
    _nombre = nombre;
}
