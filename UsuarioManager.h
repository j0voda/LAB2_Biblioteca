#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Usuario.h"
#include "UsuarioArchivo.h"
#include "Bibliotecario.h"
#include "Cliente.h"
#include "MembresiaArchivo.h"
#include "MembresiaManager.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"
#include "Fecha.h"


using namespace std;

class UsuarioManager {
private:
    UsuarioArchivo _usuarioArchivo;
    //MembresiaArchivo _membresiaArchivo;
    MembresiaManager _membresiaManager;
    LibroManager _libroManager;
    AutorManager _autorManager;
    CategoriaManager _categoriaManager;

public:
    Usuario crearUsuario(int permisos);
    void agregarUsuario();
    void modificarUsuario();
    void mostrarUsuario(const Usuario &registro);
    void eliminarUsuario();


    Usuario validarLogin(const string &mail, const string &clave,int permisos);
    //void listarUsuarios();
    void menuAdministrarUsuarios();

    void listarUsuariosPorNombre();
    void listarUsuariosPorApellido();
    void listarClientes();
    void listarBibliotecarios();
};
