#ifndef PRESTAMOARCHIVO_H
#define PRESTAMOARCHIVO_H

#include "Prestamo.h"

class PrestamoArchivo
{
    private:
        const string _nombreArchivo = "prestamos.dat";

    public:
        bool guardar(const Prestamo &prestamo);
        bool modificar(int index, const Prestamo &prestamos);
        int buscarById(int id);
        Prestamo leer(int index);
        vector<Prestamo> leerTodos();
        int getCantidadRegistros();
        int getNuevoID();
        void actualizar(const vector<Prestamo> &prestamos);
};

#endif // PRESTAMOARCHIVO_H
