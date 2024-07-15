#include <iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

#include "Autor.h"

Autor::Autor(): Persona(){
    _id = 0;
    strcpy(_nacionalidad, "");
    strcpy(_bestSellers, "");
}

Autor::Autor(const string &nombre, const string &apellido,int id, const string &nacionalidad, const string &sellers)
    : Persona(nombre, apellido){
    _id = id;
    strcpy(_nacionalidad, nacionalidad.c_str());
    strcpy(_bestSellers, sellers.c_str());
    //_nacionalidad = nacionalidad;
    //_bestSellers = sellers;
}

int Autor::getId() const {
    return _id;
}
void Autor::setId(int id) {
    _id = id;
}

string Autor::getNacionalidad() const {
    string str = _nacionalidad;
    return str;
}
void Autor::setNacionalidad(const string &nacionalidad) {
    strcpy(_nacionalidad, nacionalidad.c_str());
}

string Autor::getBestSellers() const {
    string str = _bestSellers;
    return str;
}
void Autor::setBestSellers(const string &sellers) {
    strcpy(_bestSellers, sellers.c_str());
    //_bestSellers = sellers;
}
