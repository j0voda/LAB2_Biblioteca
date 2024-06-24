#pragma once
#include <algorithm> // sort y transform
#include <cctype>    // tolower
#include <string>

using namespace std;

#include "Bibliotecario.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"
//#include "UsuarioManager.h"
#include "MembresiaManager.h"

class BibliotecarioManager
{
    private:
        UsuarioArchivo _usuarioArchivo;
        MembresiaManager _membresiaManager;
        LibroManager _libroManager;
        AutorManager _autorManager;
        CategoriaManager _categoriaManager;

    public:
        BibliotecarioManager();

        bool ingresarClave();
        void menuBibliotecario();
        void menuAdministrarClientes();

        void mostrarBibliotecario(const Usuario &registro);
        void listarBibliotecarios();
        void listarBibliotecariosPorNombre();
        void listarBibliotecariosPorApellido();


        //Bibliotecario validarLoginBibliotecario(const string &mail, const string &clave,int permisos);

};

