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
#include "MembresiaManager.h"
#include "MembresiaArchivo.h"


class PrestamoManager{
public:
	PrestamoManager();

    void solicitarPrestamo();
    void realizarDevolucion();
    bool puedePedirPrestamo(int idCliente);
    int contarPrestamosActivos(int idCliente);
    int validarPrestamo(const Usuario &cliente);

    void listarPrestamos();
    void listarPrestamosActivos(int idCliente);
    void listarPrestamosPorIdCliente(int idCliente);
    void mostrarPrestamo(const Prestamo &registro);
    void listarPrestamosCliente();

private:
    Prestamo crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente, bool devuelto);
    bool estaVencido(const Prestamo &prestamo);

    PrestamoArchivo _prestamoArchivo;
    LibroManager _libroManager;
    LibroArchivo _libroArchivo;
    UsuarioArchivo _usuarioArchivo;
    UsuarioManager _usuarioManager;
    MembresiaManager _membresiaManager;
    MembresiaArchivo _membresiaArchivo;
};
