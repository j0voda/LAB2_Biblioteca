#include "PrestamoManager.h"

PrestamoManager::PrestamoManager()
{
    //ctor
}

void PrestamoManager::listarPrestamos(){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        mostrarPrestamo(&prestamo);
    }
}

void PrestamoManager::listarPrestamosPorIdCliente(int idCliente){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        if(&prestamo.getIdCliente() == idCliente){
            mostrarPrestamo(&prestamo);
        }
    }
}

void PrestamoManager::mostrarPrestamo(const Prestamo &registro) {
    //To do
}
