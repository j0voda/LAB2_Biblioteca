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
#include "Fecha.h"


using namespace std;

class UsuarioManager {
private:

    UsuarioArchivo _usuarioArchivo;
    MembresiaArchivo _membresiaArchivo;
    MembresiaManager _membresiaManager;

public:
    void menuClienteMembresia(int idUsuario);
    void menuAdministrarUsuarios();

    Usuario crearUsuario(int permisos);
    void agregarUsuario();
    Usuario validarLogin(const string &mail, const string &clave,int permisos);
    void modificarUsuario();
    //void listarUsuarios();

    void listarUsuariosPorNombre();
    void listarUsuariosPorApellido();
    void listarBibliotecarios();
    void listarClientes();
    void eliminarUsuario();
    void mostrarUsuario(const Usuario &registro);
};
