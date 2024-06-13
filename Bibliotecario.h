#pragma once
#include "Usuario.h"
#include "UsuarioManager.h"
#include "LibroManager.h"
#include "CategoriaManager.h"
#include "AutorManager.h"
#include "MembresiaManager.h"
#include <string>

using namespace std;


class Bibliotecario : public Usuario {
private:
    //LibroManager libroManager;
    //CategoriaManager categoriaManager;
    //AutorManager autorManager;
    //MembresiaManager membresiaManager;

public:
    Bibliotecario();

    Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);

    bool ingresarClave();
    void menuBibliotecario();
};
