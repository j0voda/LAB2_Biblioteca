#include "MembresiaManager.h"

void MembresiaManager::menuAdministrarMiMembresia(){
    int opcion;
    Usuario clienteActivo;
    do {
        system("cls");

        clienteActivo = _usuarioManager.clienteActivo();

        cout << "------------------------------------------" << endl;
        cout << "ADMINISTRAR MI MEMBRESIA" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Ver el Estado de mi Membresia" << endl;
        cout << "2. Realizar Pago" << endl;
        cout << "3. Ver el Historial de Pagos" << endl;
        cout << "4. Modificar Membresia" << endl;
        cout << "------------------------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
                verEstadoMembresia();
                system("pause");
                break;

            case 2:
                realizarPago();
                system("pause");
                break;

            case 3:
                //listarTiposMembresia();
                system("pause");
                break;

            case 4:
                cambiarTipoMembresia();
                system("pause");
                break;

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
				break;
        }
    } while (opcion != 0);
}

Membresia MembresiaManager::asignarMembresia() {
    int id, idTipo, tipo;
    bool estado;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "SELECCIONAR MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;

	_tipoMembresiaManager.listarMembresiasActivas();

    cout << "Seleccione el tipo de membresia (ID): ";
    cin>> idTipo;
    cin.ignore();
    cout<<endl;
	while (_tipoMembresiaArchivo.buscarById(idTipo) == -1) {
		cout << "-- Reingrese ID: ";
		cout<<endl;
		cin >> idTipo;
		cin.ignore();
	}
    TipoMembresia tipoMembresiaActual = _tipoMembresiaArchivo.leer(_tipoMembresiaArchivo.buscarById(idTipo));

    Usuario clienteActual = _usuarioManager.clienteActivo();
    Fecha fechaActual = Fecha();
    Fecha fechaInicio = fechaActual.obtenerFechaActual();
    Fecha fechaFin = fechaInicio.sumarMes(1);
    id = _membresiaArchivo.getNuevoID();

    cout << fechaInicio.toString() << endl;
    cout << fechaFin.toString() << endl;
    cout << id << endl;
    cin.ignore();

    // Se registra el pago
    if(_pagoManager.registrarPago(id, tipoMembresiaActual.getPrecio())){
        estado = true; //se pondria en true luego de hacer el pago ok
        Membresia membresiaActual(id,clienteActual.getId(),tipoMembresiaActual,fechaInicio,fechaFin,estado);
        if (_membresiaArchivo.guardar(membresiaActual)) {
            cout << endl;
            cout << "Membresia asignada con exito." << endl;
            return membresiaActual;
        }
    } else {
        cout << endl;
        cout << "Error al asignar membresia." << endl;
        return Membresia();
    }
}

void MembresiaManager::verEstadoMembresia() {
	Usuario clienteActivo = _usuarioManager.clienteActivo();
	int idUsuario = clienteActivo.getId();
    int pos = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (pos == -1) {
        cout << "Membresia no encontrada." << endl;
        cin.ignore();
        return;
    }

    //actualizarEstadoMembresia(pos);
    Membresia membresia = _membresiaArchivo.leer(pos);
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "MI MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;
    cout << "Tipo: " << membresia.getTipoMembresia().getTipoMembresia() << " - " << membresia.getTipoMembresia().getNombre() << endl;
    cout << "Fecha de inicio: " << membresia.getFechaInicio().toString() << endl;
    cout << "Fecha de fin: " << membresia.getFechaFin().toString() << endl;
    cout << "Estado: " << (membresia.getEstado() ? "Activa" : "Vencida") << endl;
    cout << endl;
}

void MembresiaManager::cambiarTipoMembresia() {
	int idUsuario;
	Usuario clienteActivo = _usuarioManager.clienteActivo();
	idUsuario = clienteActivo.getId();

    int pos = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    Membresia membresiaActual = _membresiaArchivo.leer(pos);

    verEstadoMembresia();
    system("cls");

    int membresiaAnterior = membresiaActual.getTipoMembresia().getTipoMembresia();

    cout << endl;
    cout << "-----------------------------" << endl;
	cout << "MEMBRESIAS DISPONIBLES" << endl;
	cout << "-----------------------------" << endl;
    _tipoMembresiaManager.listarOtrasMembresias(membresiaAnterior);

    cout << endl;
    cout << endl;
    int nuevaMembresiaId;
	cout << "Seleccione el ID de su nueva membresia: ";
	cin >> nuevaMembresiaId;
	cout << endl;
	cin.ignore();

	while (_tipoMembresiaArchivo.buscarById(nuevaMembresiaId) == -1 || nuevaMembresiaId != membresiaAnterior) {
		cout << "-- Reingrese ID: ";
		cin >> nuevaMembresiaId;
		cin.ignore();
	}
	TipoMembresia nuevaMembresia = _tipoMembresiaArchivo.leer(_tipoMembresiaArchivo.buscarById(nuevaMembresiaId));
    membresiaActual.setTipoMembresia(nuevaMembresia);

    system("cls");

    cout << endl << "MEMBRESIA SELECCIONADA: "<<endl;
    _tipoMembresiaManager.mostrarTipoMembresia(nuevaMembresia);


	cout << endl << "Esta seguro de modificar su membresia? (s/n): ";
	char continuar;
	cin >> continuar;
	cin.ignore();
	if (continuar == 'n' || continuar == 'N') {
		return; // Salir del bucle
	}

    if (_membresiaArchivo.modificar(pos, membresiaActual)) {
		system("cls");
        cout << "Membresia modificada exitosamente." << endl;
        cout << endl;
        verEstadoMembresia();
    } else {
        cout << "Error al modificar la membresia." << endl;
        return;
    }
}

void MembresiaManager::realizarPago() {
	int idUsuario;
	Usuario clienteActivo = _usuarioManager.clienteActivo();
	idUsuario = clienteActivo.getId();

    int index = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (index == -1) {
        cout << "Membresia no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(index);
    if (membresia.getEstado()) {
        cout << "La membresia ya esta activa." << endl;
        return;
    }

    Fecha fechaActual = Fecha::obtenerFechaActual();
    // Realizar pago
    if(_pagoManager.registrarPago(membresia.getId(), membresia.getTipoMembresia().getPrecio())) {
        // Actualizar membres�a
        membresia.setEstado(true);
        membresia.setFechaFin(fechaActual.sumarMes(1));
        _membresiaArchivo.modificar(index, membresia);
        cout << "Pago realizado con exito. Membresia actualizada." << endl;
    } else {
        cout << "Error al realizar el pago. La membresia no ha sido actualizada." << endl;
    }
}

void MembresiaManager::actualizarEstadoMembresia(int idMembresia) {
    Membresia membresia = _membresiaArchivo.leer(idMembresia);
    Fecha fechaActual = Fecha::obtenerFechaActual();

    // Si la fecha actual es mayor que la fecha de fin de la membresia, quiere decir que venci� la membresia
    if(membresia.getFechaFin() < fechaActual) {
        membresia.setEstado(false);
    } else {
        membresia.setEstado(true);
    }

    //Guardamos
    _membresiaArchivo.modificar(idMembresia, membresia);
}

