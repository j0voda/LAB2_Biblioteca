#include "admin.h"

Admin::Admin() : Usuario() {}

Admin::Admin(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
}

