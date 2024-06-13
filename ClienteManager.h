#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "MembresiaManager.h"
#include "UsuarioArchivo.h"


class ClienteManager
{
    private:
        MembresiaManager _membresiaManager;
        UsuarioArchivo _usuarioArchivo;

    public:
        ClienteManager();
        Cliente validarLoginCliente(const string &mail, const string &clave,int permisos);
        void menuCliente();
        void menuClienteMembresia(int idUsuario);
        void listarClientes();
        void mostrarCliente(Cliente c);

};

#endif // CLIENTEMANAGER_H
