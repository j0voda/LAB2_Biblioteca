#include "Bibliotecario.h"

Bibliotecario::Bibliotecario() : Usuario() {}

Bibliotecario::Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
}




