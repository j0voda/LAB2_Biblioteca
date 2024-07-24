#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Categoria.h"

Categoria::Categoria(){
    _id= 0;
    strcpy(_nombre, "");
    //_nombre = "";
}
Categoria::Categoria(int id, const string &nombre){
    _id=id;
    strcpy(_nombre, nombre.c_str());
    //_nombre=nombre;
}

int Categoria::getId() const {
    return _id;
}
void Categoria::setId(int id) {
    _id = id;
}

string Categoria::getNombre() const {
    string str = _nombre;
    return str;
}
void Categoria::setNombre(const string &nombre) {
    strcpy(_nombre, nombre.c_str());
    //_nombre = nombre;
}
