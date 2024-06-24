#pragma once
#include <algorithm> // sort y transform
#include <cctype>    // tolower
#include <string>

using namespace std;

#include "Cliente.h"
#include "MembresiaManager.h"
//#include "UsuarioArchivo.h"


class ClienteManager
{
    private:
        MembresiaManager _membresiaManager;
        UsuarioArchivo _usuarioArchivo;

    public:
        ClienteManager();

		void asignarMembresia();
        void menuCliente();
        void menuMiMembresia(int idUsuario);

        void mostrarCliente(const Usuario &registro);
        void listarClientes();
        void listarClientesPorNombre();
        void listarClientesPorApellido();



        //Cliente validarLoginCliente(const string &mail, const string &clave,int permisos);

};
