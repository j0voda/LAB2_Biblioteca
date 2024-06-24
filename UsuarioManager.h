#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "Bibliotecario.h"
#include "BibliotecarioManager.h"
#include "Cliente.h"
#include "ClienteManager.h"

/*#include "MembresiaArchivo.h"
#include "MembresiaManager.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"*/
#include "Fecha.h"



class UsuarioManager {
private:
    UsuarioArchivo _usuarioArchivo;
    BibliotecarioManager _bibliotecarioManager;
    ClienteManager _clienteManager;
    //MembresiaArchivo _membresiaArchivo;
    //MembresiaManager _membresiaManager;
    //LibroManager _libroManager;
    //AutorManager _autorManager;
    //CategoriaManager _categoriaManager;

public:
    Usuario crearUsuario(int permisos);
    Usuario validarLogin(const string &mail, const string &clave,int permisos);

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
