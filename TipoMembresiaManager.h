#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "TipoMembresia.h"
#include "TipoMembresiaArchivo.h"

class TipoMembresiaManager {
private:
    TipoMembresiaArchivo _tipoMembresiaArchivo;

public:
    //TipoMembresia menuAdministrarTipoMembresias();
    int getNuevoID();
    TipoMembresia crearTipoMembresia();

    void modificarTipoMembresia();
    void listarTiposMembresia();
    void desactivarTipoMembresia();
    void eliminarTipoMembresia();

    void mostrarTipoMembresia(const TipoMembresia &registro);
    void mostrarTipoMembresiaACliente(const TipoMembresia &registro);
    void listarMembresiasActivas();
    void listarOtrasMembresias(int id);
    void listarMembresiasInactivas();

    void realizarPago(int idUsuario);
    void cambiarTipoMembresia(int idUsuario, int nuevoTipo);
    void verEstadoMembresia(int idUsuario);
};
