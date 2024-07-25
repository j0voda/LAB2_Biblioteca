#pragma once
#include <iostream>
#include <vector>

using namespace std;

#include "Fecha.h"
#include "TipoMembresiaManager.h"
#include "pagomanager.h"
#include "TipoMembresiaArchivo.h"
#include "MembresiaArchivo.h"
#include "PagoArchivo.h"
#include "UsuarioArchivo.h"
#include "UsuarioManager.h"


class MembresiaManager {
private:
	TipoMembresiaManager _tipoMembresiaManager;
	TipoMembresiaArchivo _tipoMembresiaArchivo;
	PagoManager _pagoManager;
    PagoArchivo _pagoArchivo;
    MembresiaArchivo _membresiaArchivo;
    UsuarioArchivo _usuarioArchivo;
    UsuarioManager _usuarioManager;

public:
    void menuAdministrarMiMembresia();

    Membresia asignarMembresia();
	void verEstadoMembresia();
	void cambiarTipoMembresia();
	void actualizarEstadoMembresia(int idMembresia);

    void realizarPago();

/*
    void guardarMembresia(const Membresia &membresia);
    void eliminarTipoMembresia();
    void verTiposMembresia();
    int getNuevoID();
    //usuario

    void cambiarTipoMembresia(int idUsuario, int nuevoTipo);
    void verEstadoMembresia(int idUsuario);
*/
};
