#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "Bibliotecario.h"
#include "Cliente.h"
//#include "BibliotecarioManager.h"
//#include "ClienteManager.h"
#include "Fecha.h"
#include "UsuarioLogueado.h"



class UsuarioManager {
private:
    UsuarioArchivo _usuarioArchivo;
    UsuarioLogueado _usuarioLogueado;
    //ClienteManager _clienteManager;
    //BibliotecarioManager _bibliotecarioManager;

public:
    Usuario crearUsuario(int permisos);
    Usuario validarLogin(const string &mail, const string &clave,int permisos);
    int validarTel(const string &tel);
    int validarMail(const string& mail);
    bool ingresarClaveMaestra();

	void menuAdministrarUsuarios();

    void agregarUsuario();
    void modificarUsuario();
    void eliminarUsuario();

    bool dobleValidacion(string clave);
    Usuario clienteActivo();

    void mostrarUsuario(const Usuario &registro);
    void listarUsuarios();
    void listarUsuariosPorPermisos(int permiso);

    void listarUsuariosPorNombre();
    void listarUsuariosPorApellido();
    void listarBibliotecarios();
};
