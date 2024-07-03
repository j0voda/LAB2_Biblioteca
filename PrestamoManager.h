#ifndef PRESTAMOMANAGER_H
#define PRESTAMOMANAGER_H

#include "Prestamo.h"
#include "PrestamoArchivo.h"

class PrestamoManager
{
    public:
        PrestamoManager();
        listarPrestamos();
        listarPrestamosPorIdCliente(int id);
        mostrarPrestamo(const Prestamo &registro)

    private:
};

#endif // PRESTAMOMANAGER_H
