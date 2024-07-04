#include "PrestamoManager.h"

PrestamoManager::PrestamoManager(){}

Prestamo PrestamoManager::crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente){

}

void PrestamoManager::solicitarPrestamo(int idCliente, int idLibro) {
    Libro libro = _libroArchivo.leer(_libroArchivo.buscarById(idLibro));
    Usuario cliente = _usuarioArchivo.leer(_usuarioArchivo.buscarById(idCliente));

    // Verificar disponibilidad del libro
    if (libro.getDisponibles() > 0) {
        // Crear el pr�stamo
        int nuevoId = _prestamoArchivo.getNuevoID();
        Prestamo prestamo = crearPrestamo(nuevoId, libro, cliente);

        // Agregar el pr�stamo activo al archivo o al contenedor correspondiente
        _prestamoArchivo.guardar(prestamo);

        // Actualizar disponibilidad del libro
        libro.setDisponibles(libro.getDisponibles() - 1);
        _libroArchivo.modificar(_libroArchivo.buscarById(idLibro),libro);

        cout << "�Pr�stamo realizado con �xito!" << endl;
    } else {
        cout << "El libro no est� disponible para pr�stamo en este momento." << endl;
    }
}

void PrestamoManager::listarPrestamos(){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        //mostrarPrestamo(&prestamo);
    }
}

void PrestamoManager::listarPrestamosPorIdCliente(int idCliente){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
		mostrarPrestamo(prestamo);
    }
}

void PrestamoManager::mostrarPrestamo(const Prestamo &registro) {
    //To do
}
