#pragma once
#include <iostream>

#include "UsuarioManager.h"
#include "LibroManager.h"
#include "CategoriaManager.h"
#include "AutorManager.h"
#include "MembresiaManager.h"
#include "PagoArchivo.h"

using namespace std;

class MenuPrincipal {
public:
    void mostrarMenu();
    void iniciarSesion();
    void menuBibliotecario();
    void menuCliente();
};
