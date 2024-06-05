#pragma once
#include <iostream>
#include <vector>

#include "Fecha.h"
#include "MembresiaArchivo.h"
#include "PagoArchivo.h"
#include "UsuarioArchivo.h"

using namespace std;

class MembresiaManager {
private:
    MembresiaArchivo _membresiaArchivo;
    PagoArchivo _pagoArchivo;

public:
    void menuAdministrarMembresias();
    void agregarTipoMembresia();
    void guardarMembresia(const Membresia &membresia);
    void eliminarTipoMembresia();
    void verTiposMembresia();
    int getNuevoID();
    //usuario
    void realizarPago(int idUsuario);
    void cambiarTipoMembresia(int idUsuario, int nuevoTipo);
    void verEstadoMembresia(int idUsuario);
};
