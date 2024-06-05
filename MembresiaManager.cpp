#include "MembresiaManager.h"


void MembresiaManager::menuAdministrarMembresias() {
        int opcion;
        do {
            cout << "-----------------------------" << endl;
            cout << "ADMINISTRAR MEMBRES�AS" << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Ver tipos de membres�a" << endl;
            cout << "2. Agregar tipo de membres�a" << endl;
            cout << "3. Eliminar tipo de membres�a" << endl;
            cout << "-----------------------------" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opci�n: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1:
                    verTiposMembresia();
                    break;
                case 2:
                    agregarTipoMembresia();
                    break;
                case 3:
                    eliminarTipoMembresia();
                    break;
                case 0:
                    cout << "Saliendo del men� de administraci�n de membres�as." << endl;
                    break;
                default:
                    cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            }
        } while (opcion != 0);
    }

void MembresiaManager::agregarTipoMembresia() {
    // permitir al usuario (bibliotecario) agregar un nuevo tipo de membres�a
    cout << "Funcionalidad de agregar tipo de membres�a no implementada." << endl;
}

void MembresiaManager::guardarMembresia(const Membresia &membresia) {
    _membresiaArchivo.guardar(membresia);
}

void MembresiaManager::eliminarTipoMembresia() {
    // Permitir al usuario (bibliotecario) eliminar un tipo de membres�a existente
    cout << "Funcionalidad de eliminar tipo de membres�a no implementada." << endl;
}

void MembresiaManager::verTiposMembresia() {
    // mostrar los tipos de membres�a desde el archivo con sus caracteristicas
    cout << "Tipos de membres�a disponibles:" << endl;
    cout << "1. B�sica" << endl;
    cout << "2. Premium" << endl;
}

void MembresiaManager::verEstadoMembresia(int idUsuario) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membres�a no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    cout << "Tipo: " << (membresia.getTipo() == 1 ? "B�sica" : "Premium") << endl;
    cout << "Fecha de inicio: " << membresia.getFechaInicio().toString() << endl;
    cout << "Fecha de fin: " << membresia.getFechaFin().toString() << endl;
    cout << "Estado: " << (membresia.getEstado() ? "Activa" : "Vencida") << endl;
}

void MembresiaManager::realizarPago(int idUsuario) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membres�a no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    if (membresia.getEstado()) {
        cout << "La membres�a ya est� activa." << endl;
        return;
    }

    // Realizar pago
    Fecha fechaActual = Fecha::obtenerFechaActual();
    Pago pago(_pagoArchivo.getNuevoID(), idUsuario,0.0f, fechaActual, 1);
    _pagoArchivo.guardar(pago);

    // Actualizar membres�a
    membresia.setEstado(true);
    membresia.setFechaFin(fechaActual.sumarMes(1));
    _membresiaArchivo.modificar(index, membresia);

    cout << "Pago realizado con �xito. Membres�a actualizada." << endl;
}

void MembresiaManager::cambiarTipoMembresia(int idUsuario, int nuevoTipo) {
    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membres�a no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    membresia.setTipo(nuevoTipo);
    _membresiaArchivo.modificar(index, membresia);

    cout << "Tipo de membres�a actualizado a " << (nuevoTipo == 1 ? "B�sica" : "Premium") << "." << endl;
}

int MembresiaManager::getNuevoID() {
    return _membresiaArchivo.getNuevoID();
}

