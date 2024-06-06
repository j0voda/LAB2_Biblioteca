#pragma once
#include <iostream>

#include "UsuarioManager.h"
#include "LibroManager.h"
#include "CategoriaManager.h"
#include "AutorManager.h"
#include "MembresiaManager.h"
//#include "PagoArchivo.h"
#include "Fecha.h"

using namespace std;

class MenuPrincipal {
private:
    UsuarioManager _usuarioManager;
    LibroManager _libroManager;
    CategoriaManager _categoriaManager;
    AutorManager _autorManager;
    MembresiaManager _membresiaManager;
    Bibliotecario _bibliotecario;
    Cliente _cliente;
    //PagoArchivo pagoArchivo;

public:
    void menuInicio();
    void iniciarSesion();
    void registrarse();

    //void menuCliente();
    //void registro();
};
