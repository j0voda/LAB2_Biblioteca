#ifndef PAGOMANAGER_H
#define PAGOMANAGER_H

#include "PagoArchivo.h"
#include "UsuarioLogueado.h"
#include "UsuarioManager.h"

class PagoManager
{
    private:
        PagoArchivo _pagoArchivo;

        UsuarioManager _usuarioManager;
        UsuarioLogueado _usuarioLogueado;

    public:
        PagoManager();
        void listarPagosPorUsuario();
        void mostrarPago(const Pago &pago);
        bool registrarPago(int idMembresia, float montoMembresia);
        bool validarNumeroTarjeta(const string &numeroTarjeta);
        bool validarClaveTarjeta(const string &claveTarjeta);

};

#endif // PAGOMANAGER_H
