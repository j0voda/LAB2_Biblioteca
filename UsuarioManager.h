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



class UsuarioManager {
private:
    UsuarioArchivo _usuarioArchivo;
    //ClienteManager _clienteManager;
    //BibliotecarioManager _bibliotecarioManager;

public:
    Usuario crearUsuario(int permisos);
    Usuario validarLogin(const string &mail, const string &clave,int permisos);
    int validarMail(const string& mail);
    bool ingresarClaveMaestra();

	void menuAdministrarUsuarios();

    void agregarUsuario();
    void modificarUsuario();
    void eliminarUsuario();

    void mostrarUsuario(const Usuario &registro);
    void listarUsuarios();
    void listarUsuariosPorPermisos(int permiso);

    void listarUsuariosPorNombre();
    void listarUsuariosPorApellido();
    void listarBibliotecarios();
};
