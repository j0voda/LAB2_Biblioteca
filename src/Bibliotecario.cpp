#include <iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "Bibliotecario.h"

// Constructor por defecto
Bibliotecario::Bibliotecario() : Usuario() {}

// Constructor parametrizado
Bibliotecario::Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {}
