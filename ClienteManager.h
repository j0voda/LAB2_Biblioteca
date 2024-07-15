#pragma once
#include <algorithm> // sort y transform
#include <cctype>    // tolower
#include <string>
#include <vector>
#include <regex>

using namespace std;

#include "Cliente.h"
#include "MembresiaManager.h"
#include "LibroManager.h"
#include "UsuarioArchivo.h"
#include "PrestamoManager.h"


class ClienteManager{
    private:
        MembresiaManager _membresiaManager;
        UsuarioArchivo _usuarioArchivo;
        LibroManager _libroManager;
        PrestamoManager _prestamoManager;

    public:
        ClienteManager();

		Cliente crearCliente();
		void asignarMembresia();
		int validarTel(const string &tel);
		int validarMail(const string &mail);

        void mostrarCliente(const Usuario &registro);
        void listarClientes();
        void listarClientesPorNombre();
        void listarClientesPorApellido();

        void verLibros();
};
