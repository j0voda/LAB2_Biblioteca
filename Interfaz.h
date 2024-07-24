#pragma once
#include <iostream>

using namespace std;

#include "Bibliotecario.h"
#include "Cliente.h"
#include "UsuarioManager.h"
#include "UsuarioArchivo.h"
#include "BibliotecarioManager.h"
#include "ClienteManager.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"
#include "TipoMembresiaManager.h"
#include "MembresiaManager.h"
#include "PagoArchivo.h"
#include "PrestamoManager.h"
#include "UsuarioLogueado.h"
//#include "Fecha.h"


class Interfaz {
private:
    UsuarioManager _usuarioManager;
	UsuarioArchivo _usuarioArchivo;
    BibliotecarioManager _bibliotecarioManager;
    ClienteManager _clienteManager;
    LibroManager _libroManager;
    AutorManager _autorManager;
    CategoriaManager _categoriaManager;
    TipoMembresiaManager _tipoMembresiaManager;
    MembresiaManager _membresiaManager;
    PrestamoManager _prestamoManager;
    UsuarioLogueado _usuarioLogueado;
    //PagoArchivo _pagoArchivo;

public:
    void menuInicio();
    void iniciarSesion();
    void registrarse();

    ///Bibliotecario
    void menuBibliotecario();
    void menuAdministrarUsuarios();
    void menuAdministrarMembresias();

    ///Cliente
    void menuCliente();
	void menuMiMembresia();


    //void menuCliente();
    //void registro();
};
