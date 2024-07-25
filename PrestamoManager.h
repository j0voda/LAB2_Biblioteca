#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "Prestamo.h"
#include "PrestamoArchivo.h"
#include "MembresiaArchivo.h"
#include "LibroArchivo.h"
#include "UsuarioArchivo.h"
#include "LibroManager.h"
#include "UsuarioManager.h"


class PrestamoManager{
public:
	PrestamoManager();

    void solicitarPrestamo();
    void realizarDevolucion();
    bool puedePedirPrestamo(int idCliente);

    int contarPrestamosActivos(int idCliente);

    void listarPrestamos();
    void listarPrestamosActivos(int idCliente);
    void listarPrestamosPorIdCliente(int idCliente);
    void mostrarPrestamo(const Prestamo &registro);
    void listarPrestamosCliente();

    int validarPrestamo(const Usuario &cliente);

private:
    Prestamo crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente, bool devuelto);
    bool estaVencido(const Prestamo &prestamo);

    PrestamoArchivo _prestamoArchivo;
    LibroManager _libroManager;
    MembresiaArchivo _membresiaArchivo;
    LibroArchivo _libroArchivo;
    UsuarioArchivo _usuarioArchivo;
    UsuarioManager _usuarioManager;
};
