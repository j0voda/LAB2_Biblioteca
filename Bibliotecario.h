#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Usuario.h"

class Bibliotecario : public Usuario {
private:
    //LibroManager libroManager;
    //AutorManager autorManager;
    //CategoriaManager categoriaManager;
    //UsuarioManager usuarioManager;
    //MembresiaManager membresiaManager;

public:
    Bibliotecario();
    Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);

};
