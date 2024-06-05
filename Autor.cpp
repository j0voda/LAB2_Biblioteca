#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Autor.h"

Autor::Autor(): Persona(){
    _id = 0;
    _nacionalidad = "";
    _bestSellers = "";
}

Autor::Autor(const string &nombre, const string &apellido,int id, const string &nacionalidad, const string &sellers)
    : Persona(nombre, apellido){
    _id = id;
    _nacionalidad = nacionalidad;
    _bestSellers = sellers;
}

int Autor::getId() const {
    return _id;
}
void Autor::setId(int id) {
    _id = id;
}

string Autor::getNacionalidad() const {
    return _nacionalidad;
}
void Autor::setNacionalidad(const string &nacionalidad) {
    _nacionalidad = nacionalidad;
}

string Autor::getBestSellers() const {
    return _bestSellers;
}
void Autor::setBestSellers(const string &sellers) {
    _bestSellers = sellers;
}
