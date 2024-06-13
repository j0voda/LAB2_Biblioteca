#ifndef BIBLIOTECARIOMANAGER_H
#define BIBLIOTECARIOMANAGER_H

#include "Bibliotecario.h"

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
        void menuBibliotecario();
        void menuAdministrarClientes();
        void listarBibliotecarios();
        Bibliotecario validarLoginBibliotecario(const string &mail, const string &clave,int permisos);
        void mostrarBibliotecario(Bibliotecario b);
};

#endif // BIBLIOTECARIOMANAGER_H
