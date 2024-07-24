#include "MembresiaManager.h"

Membresia MembresiaManager::asignarMembresia() {
    int idTipo;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "SELECCIONAR MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;

	_tipoMembresiaManager.listarMembresiasActivas();

    cout << "Seleccione el tipo de membresia (ID): ";
    cin>> idTipo;
    cin.ignore();
    cout<<endl;

    int posMembresia = _tipoMembresiaArchivo.buscarById(idTipo);

    while(posMembresia == -1 && idTipo < 1) {
		cout << "-- Reingrese ID: ";
		cout<<endl;
		cin >> idTipo;
		cin.ignore();
	}

	TipoMembresia tipoMembresia = _tipoMembresiaArchivo.leer(posMembresia);

	Usuario clienteActual = _usuarioManager.clienteActivo();
    Fecha fechaInicio = fechaInicio.obtenerFechaActual();
    Fecha fechaFin = fechaFin.sumarMes(1);
    int id = _membresiaArchivo.getNuevoID();
    //bool estado = true; //se pondria en true luego de hacer el pago ok

    if(_pagoManager.registrarPago(id, tipoMembresia.getPrecio())){
        bool estado = true; //se pondria en true luego de hacer el pago ok
        Membresia membresiaActual(id,clienteActual,tipoMembresia,fechaInicio,fechaFin,estado);
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
	system("cls");
	int idUsuario;
	Usuario clienteActivo = _usuarioManager.clienteActivo();
	idUsuario = clienteActivo.getId();
    int pos = _membresiaArchivo.buscarPorIdUsuario(idUsuario);
    if (pos == -1) {
        cout << "Membresia no encontrada." << endl;
        return;
    }

    Membresia membresia = _membresiaArchivo.leer(pos);
    if(membresia.getTipoMembresia().getTipoMembresia()<1 && membresia.getTipoMembresia().getEstado()==false){
		cout << "No posee una membresia activa." << endl;
        return;
    }
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

	while (_tipoMembresiaArchivo.buscarById(nuevaMembresiaId) == -1 && nuevaMembresiaId != membresiaAnterior) {
		cout << "-- Reingrese ID: ";
		cin >> nuevaMembresiaId;
		cin.ignore();
	}
	TipoMembresia nuevaMembresia = _tipoMembresiaArchivo.leer(_tipoMembresiaArchivo.buscarById(nuevaMembresiaId));

    Fecha fechaInicio = fechaInicio.obtenerFechaActual();
    Fecha fechaFin = fechaFin.sumarMes(1);

	membresiaActual.setTipoMembresia(nuevaMembresia);
	membresiaActual.setFechaInicio(fechaInicio);
	membresiaActual.setFechaFin(fechaFin);
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

    // Realizar pago
    Fecha fechaActual = Fecha::obtenerFechaActual();

    // Realizar pago
    if(_pagoManager.registrarPago(membresia.getId(), membresia.getTipoMembresia().getPrecio())) {
        // Actualizar membresía
        membresia.setEstado(true);
        membresia.setFechaFin(fechaActual.sumarMes(1));
        _membresiaArchivo.modificar(index, membresia);
        cout << "Pago realizado con exito. Membresia actualizada." << endl;
    } else {
        cout << "Error al realizar el pago. La membresia no ha sido actualizada." << endl;
    }
}

int MembresiaManager::contarMembresiasDisponibles(){
	vector<TipoMembresia> membresias = _tipoMembresiaArchivo.leerTodas();
	int contador = 0;

		for (const auto &membresia : membresias) {
			if(membresia.getEstado()){
				contador++;
			}
		}
		return contador;
}

void MembresiaManager::actualizarEstadoMembresia(int idMembresia) {
    Membresia membresia = _membresiaArchivo.leer(idMembresia);
    Fecha fechaActual = Fecha::obtenerFechaActual();

    // Si la fecha actual es mayor que la fecha de fin de la membresia, quiere decir que venció la membresia
    if(membresia.getFechaFin() < fechaActual) {
        membresia.setEstado(false);
    } else {
        membresia.setEstado(true);
    }

    //Guardamos
    _membresiaArchivo.modificar(idMembresia, membresia);
}
