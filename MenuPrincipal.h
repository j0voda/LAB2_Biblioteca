#pragma once
#include <iostream>

using namespace std;

#include "Persona.h"
#include "UsuarioManager.h"
#include "BibliotecarioManager.h"
#include "ClienteManager.h"

//#include "LibroManager.h"
//#include "CategoriaManager.h"
//#include "AutorManager.h"
//#include "MembresiaManager.h"
//#include "PagoArchivo.h"
//#include "Fecha.h"


class MenuPrincipal {
private:
    UsuarioManager _usuarioManager;
    BibliotecarioManager _bibliotecarioManager;
    ClienteManager _clienteManager;
    //LibroManager _libroManager;
    //CategoriaManager _categoriaManager;
    //AutorManager _autorManager;
    //MembresiaManager _membresiaManager;
    //Bibliotecario _bibliotecario;
    //Cliente _cliente;
    //PagoArchivo pagoArchivo;

public:
    void menuInicio();
    void iniciarSesion();
    void registrarse();

    //void menuCliente();
    //void registro();
};
