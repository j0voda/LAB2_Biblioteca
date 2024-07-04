#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "Prestamo.h"
#include "PrestamoArchivo.h"
#include "LibroArchivo.h"
#include "UsuarioArchivo.h"
#include "LibroManager.h"
#include "UsuarioManager.h"


class PrestamoManager{
public:
	PrestamoManager();

    void solicitarPrestamo();
    void realizarDevolucion(int idPrestamo);
    bool puedePedirPrestamo(int idCliente);

    void listarPrestamos();
    void listarPrestamosPorIdCliente(int idCliente);
    void mostrarPrestamo(const Prestamo &registro);

private:
    Prestamo crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente);
    bool estaVencido(const Prestamo &prestamo);

    PrestamoArchivo _prestamoArchivo;
    LibroManager _libroManager;
    LibroArchivo _libroArchivo;
    UsuarioArchivo _usuarioArchivo;
    UsuarioManager _usuarioManager;
};
