#include "MembresiaManager.h"




void MembresiaManager::agregarTipoMembresia() {
    int id, tipo;
    Fecha fechaInicio,fechaFin;
    bool estado;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "AGREGAR MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;

    cout << "Ingrese el tipo de membresia: ";
    cin>> tipo;
    cout<<endl;
}

void MembresiaManager::guardarMembresia(const Membresia &membresia) {
    _membresiaArchivo.guardar(membresia);
}

void MembresiaManager::eliminarTipoMembresia() {
    // Permitir al usuario (bibliotecario) eliminar un tipo de membresía existente
    cout << "Funcionalidad de eliminar tipo de membresía no implementada." << endl;
}

void MembresiaManager::verTiposMembresia() {
    // mostrar los tipos de membresía desde el archivo con sus caracteristicas
    cout << "Tipos de membresía disponibles:" << endl;
    cout << "1. Básica" << endl;
    cout << "2. Premium" << endl;
}

void MembresiaManager::verEstadoMembresia(int idUsuario) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membresía no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    cout << "Tipo: " << (membresia.getTipo() == 1 ? "Básica" : "Premium") << endl;
    cout << "Fecha de inicio: " << membresia.getFechaInicio().toString() << endl;
    cout << "Fecha de fin: " << membresia.getFechaFin().toString() << endl;
    cout << "Estado: " << (membresia.getEstado() ? "Activa" : "Vencida") << endl;
}

void MembresiaManager::realizarPago(int idUsuario) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membresía no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    if (membresia.getEstado()) {
        cout << "La membresía ya está activa." << endl;
        return;
    }

    // Realizar pago
    Fecha fechaActual = Fecha::obtenerFechaActual();
    Pago pago(_pagoArchivo.getNuevoID(), idUsuario,0.0f, fechaActual, 1);
    _pagoArchivo.guardar(pago);

    // Actualizar membresía
    membresia.setEstado(true);
    membresia.setFechaFin(fechaActual.sumarMes(1));
    _membresiaArchivo.modificar(index, membresia);

    cout << "Pago realizado con éxito. Membresía actualizada." << endl;
}

void MembresiaManager::cambiarTipoMembresia(int idUsuario, int nuevoTipo) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membresía no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    membresia.setTipo(nuevoTipo);
    _membresiaArchivo.modificar(index, membresia);

    cout << "Tipo de membresía actualizado a " << (nuevoTipo == 1 ? "Básica" : "Premium") << "." << endl;
}

int MembresiaManager::getNuevoID() {
    return _membresiaArchivo.getNuevoID();
}

