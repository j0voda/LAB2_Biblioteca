#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Categoria.h"

Categoria::Categoria(){
    _id= 0;
    _nombre = "";
}
Categoria::Categoria(int id, const string &nombre){
    _id=id;
    _nombre=nombre;
}

int Categoria::getId() const {
    return _id;
}
void Categoria::setId(int id) {
    _id = id;
}

string Categoria::getNombre() const {
    return _nombre;
}
void Categoria::setNombre(const string &nombre) {
    _nombre = nombre;
}
