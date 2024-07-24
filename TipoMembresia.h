#pragma once
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

#include "Fecha.h"

class TipoMembresia{
private:
    int tipoMembresia; // (id)
    char nombre[50];/// id 1- Membresia Basica id 2- Membresia Premium  ...
    //int vigencia;
    int librosAlaVez;
    int librosXMes;
    float precio;
    bool estado; /// Activa / Inactiva

public:
    TipoMembresia();

    TipoMembresia(int tipo, const string &nombre,/* int vigencia, */int librosAlaVez, int librosXMes, float precio, bool estado);

    int getTipoMembresia() const;
    void setTipoMembresia(int tipoMembresia);

    string getNombre() const;
    void setNombre(const string &nombre);
/*
    int getVigencia() const;
    void setVigencia(int vigencia);
*/
    int getLibrosAlaVez() const;
    void setLibrosAlaVez(int librosAlaVez);

    int getLibrosXMes() const;
    void setLibrosXMes(int librosXMes);

    float getPrecio() const;
    void setPrecio(float precio);

    bool getEstado() const;
    void setEstado(bool estado);

};
