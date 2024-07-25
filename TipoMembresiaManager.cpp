#include "TipoMembresiaManager.h"


TipoMembresia TipoMembresiaManager::crearTipoMembresia() {
    int tipo, librosAlaVez, librosXMes;
    string nombre;
    float precio;
    bool estado;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "AGREGAR TIPO DE MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;

	tipo = _tipoMembresiaArchivo.getNuevoID();
    cout << "Membresia: "<<tipo<<endl;
    cout << "Seleccione el nombre del nuevo tipo de membresia: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Seleccione la cantidad maxima de libros a retirar por mes: ";
    cin>> librosXMes;
    while (librosXMes < 1) {
		cout << "-- Ingrese un numero valido: ";
		cin >> librosXMes;
		cin.ignore();
	}
    cout << "Seleccione la cantidad maxima de libros a retirar en simultaneo: ";
    cin>> librosAlaVez;
    while (librosAlaVez < 1) {
		cout << "-- Ingrese un numero valido: ";
		cin >> librosAlaVez;
		cin.ignore();
	}
	while (librosAlaVez>librosXMes){
		cout << "-- El numero de libros en simultaneo no debe ser mayor al maximo por mes: ";
		cin >> librosAlaVez;
		cin.ignore();
	}

    cout << "Seleccione el valor de esta membresia: ";
    cin>> precio;
    while (precio < 0) {
		cout << "-- Ingrese un precio valido: ";
		cin >> precio;
		cin.ignore();
	}
    estado = true;


    TipoMembresia nuevoTipoMembresia(tipo,nombre,librosAlaVez,librosXMes,precio,estado);
	if (_tipoMembresiaArchivo.guardar(nuevoTipoMembresia)) {
        cout << endl;
        cout << "Tipo de membresia agregado con exito." << endl;
        return nuevoTipoMembresia;
    } else {
        cout << endl;
        cout << "Error al agregar el tipo de membresia." << endl;
        return TipoMembresia();
    }

}

void TipoMembresiaManager::mostrarTipoMembresia(const TipoMembresia &registro) {
	cout<<endl;
    cout << "Tipo: " << registro.getTipoMembresia()<< " - " << registro.getNombre() << endl;
    cout << "Cantidad maxima de libros en simultaneo: " << registro.getLibrosAlaVez()<< endl;
    cout << "Cantidad maxima de libros por mes: " << registro.getLibrosXMes() << endl;
    cout << "Valor mensual: " << registro.getPrecio() << endl;
    cout << "Estado: " << (registro.getEstado() ? "Activa" : "Inactiva") << endl;
	cout<<endl;
    cout << "-----------------------------" << endl;
}

void TipoMembresiaManager::mostrarTipoMembresiaACliente(const TipoMembresia &registro) {
	cout<<endl;
    cout << "Tipo: " << registro.getTipoMembresia()<< " - " << registro.getNombre() << endl;
    cout << "Cantidad maxima de libros en simultaneo: " << registro.getLibrosAlaVez()<< endl;
    cout << "Cantidad maxima de libros por mes: " << registro.getLibrosXMes() << endl;
    cout << "Valor mensual: " << registro.getPrecio() << endl;
	cout<<endl;
    cout << "-----------------------------" << endl;
}

void TipoMembresiaManager::modificarTipoMembresia() {
	system("cls");
	cout<<endl;
	cout << "MODIFICAR TIPO DE MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;

    int idTipoMembresia;

	listarTiposMembresia();
	cout << "Ingrese el ID de la membresia a modificar: ";
	cin >> idTipoMembresia;
	cin.ignore();

    int pos = _tipoMembresiaArchivo.buscarById(idTipoMembresia);
    if (pos < 0) {
        cout << "Membresia no encontrada." << endl;
        return;
    }

	system("cls");
    TipoMembresia membresiaActual = _tipoMembresiaArchivo.leer(pos);
    mostrarTipoMembresia(membresiaActual);
    cout << endl;
    cout<<"Desea modificar esta membresia? S/N"<<endl;
    char respuesta;
    cin>>respuesta;
    if(respuesta == 'n' || respuesta == 'N'){
		return;
    }


    char opcion;
    do {
		system("cls");
		cout << "-----------------------------" << endl;
		cout << "MODIFICAR MEMBRESIA" << endl;
		cout << "-----------------------------" << endl;
        cout << "1. Modificar Nombre" << endl;
        cout << "2. Modificar Libros en Simultaneo" << endl;
        cout << "3. Modificar Libros por Mes" << endl;
        cout << "4. Modificar Precio" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Finalizar Modificaciones" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
		switch (opcion) {
            case '1': {
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevoNombre);
                membresiaActual.setNombre(nuevoNombre);
                break;
            }
            case '2': {
                int nuevoSimultaneo;
                cout << "Seleccione el nuevo maximo de libros en simultaneo: ";
                cin >> nuevoSimultaneo;
                cin.ignore();
                while (nuevoSimultaneo < 1) {
                    cout << "-- Ingrese un numero valido: ";
                    cin >> nuevoSimultaneo;
                    cin.ignore();
                }
                while (nuevoSimultaneo>membresiaActual.getLibrosXMes()){
					cout << "-- El numero de libros en simultaneo no debe ser mayor al maximo por mes: ";
					cin >> nuevoSimultaneo;
					cin.ignore();
				}
                membresiaActual.setLibrosAlaVez(nuevoSimultaneo);
                break;
            }
            case '3': {
                int nuevoXMes;
                cout << "Seleccione el nuevo maximo de libros por mes: ";
                cout << endl;
                while (nuevoXMes < 1) {
                    cout << "-- Ingrese un numero valido: ";
                    cin >> nuevoXMes;
                    cin.ignore();
                }
                membresiaActual.setLibrosXMes(nuevoXMes);
                break;
            }
            case '4': {
                float nuevoPrecio;
                cout << "Ingrese el nuevo valor de la membresia: ";
                cin >> nuevoPrecio;
                cin.ignore();
                while (nuevoPrecio < 0) {
                    cout << "-- Ingrese un precio valido: ";
                    cin >> nuevoPrecio;
                    cin.ignore();
                }
                membresiaActual.setPrecio(nuevoPrecio);
                break;
            }
            case '0':
                cout << "Finalizando modificaciones." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
        if (opcion != '0') {
            cout << endl << "Desea modificar otro dato? (s/n): ";
            char continuar;
            cin >> continuar;
            cin.ignore();
            if (continuar == 'n' || continuar == 'N') {
                opcion = '0'; // Salir del bucle
            }
        }
    } while (opcion != '0');

	if (_tipoMembresiaArchivo.modificar(pos, membresiaActual)) {
		system("cls");
        cout << endl;
        cout << "Tipo de membresia modificado con exito." << endl;
        cout << endl;
        mostrarTipoMembresia(membresiaActual);
    } else {
        cout << endl;
        cout << "Error al modificar el tipo de membresia." << endl;
        return;
    }
}

void TipoMembresiaManager::desactivarTipoMembresia() {

    char opcion;
    do {
		system("cls");
		cout << "-----------------------------" << endl;
		cout << "ALTA / BAJA MEMBRESIA" << endl;
		cout << "-----------------------------" << endl;
        cout << "1. ACTIVAR un Tipo de Membresia" << endl;
        cout << "2. DESACTIVAR un Tipo de Membresia" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

		switch (opcion) {
            case '1': {
            	system("cls");
                int idMembresia;
                cout << "ACTIVAR MEMBRESIAS INACTIVAS"<<endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                listarMembresiasInactivas();
                cout << "Seleccione el ID del tipo que desea ACTIVAR: ";
                cin >> idMembresia;
                int pos = _tipoMembresiaArchivo.buscarById(idMembresia);
                TipoMembresia membresiaActual = _tipoMembresiaArchivo.leer(pos);
                int cantReg = _tipoMembresiaArchivo.getCantidadRegistros();
                while (idMembresia > cantReg+1 && pos == -1 && membresiaActual.getEstado()==false) {
                    cout << "-- Reingrese ID: ";
                    cin >> idMembresia;
                    cin.ignore();
                }
                system("cls");
				membresiaActual = _tipoMembresiaArchivo.leer(pos);
				mostrarTipoMembresia(membresiaActual);
				cout << endl;
				cout<<"Desea ACTIVAR esta membresia? S/N"<<endl;
				char respuesta;
				cin>>respuesta;
				if(respuesta == 'n' || respuesta == 'N'){
					return;
				}
                membresiaActual.setEstado(true);
                _tipoMembresiaArchivo.modificar(pos, membresiaActual);
                break;
            }
            case '2': {
                system("cls");
                int idMembresia;
                cout << "DESACTIVAR MEMBRESIAS ACTIVAS"<<endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                listarMembresiasActivas();
                cout << "Seleccione el ID del tipo que desea DESACTIVAR: ";
                cin >> idMembresia;
                int pos = _tipoMembresiaArchivo.buscarById(idMembresia);
                TipoMembresia membresiaActual = _tipoMembresiaArchivo.leer(pos);
                while (pos == -1 && idMembresia != 0 && membresiaActual.getEstado()==true) {
                    cout << "-- Reingrese ID: ";
                    cin >> idMembresia;
                    cin.ignore();
                }
                system("cls");
				membresiaActual = _tipoMembresiaArchivo.leer(pos);
				mostrarTipoMembresia(membresiaActual);
				cout << endl;
				cout<<"Desea DESACTIVAR esta membresia? S/N"<<endl;
				char respuesta;
				cin>>respuesta;
				if(respuesta == 'n' || respuesta == 'N'){
					return;
				}
                membresiaActual.setEstado(false);
                _tipoMembresiaArchivo.modificar(pos, membresiaActual);
                break;
        }
        if (opcion != '0') {
            cout << endl << "Desea ACTIVAR / DESACTIVAR otra membresia? (s/n): ";
            char continuar;
            cin >> continuar;
            cin.ignore();
            if (continuar == 'n' || continuar == 'N') {
                opcion = '0'; // Salir del bucle
            }
        }
    }
	}while (opcion != '0');
}

void TipoMembresiaManager::listarTiposMembresia() {
    vector<TipoMembresia> tiposMembresias = _tipoMembresiaArchivo.leerTodas();
    sort(tiposMembresias.begin(), tiposMembresias.end(), [](const TipoMembresia &a, const TipoMembresia &b) {
        return a.getTipoMembresia() < b.getTipoMembresia();
    });
    for (const auto &tipoMembresia : tiposMembresias) {
        mostrarTipoMembresia(tipoMembresia);
    }
}

void TipoMembresiaManager::eliminarTipoMembresia() {
    int idMembresia;
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "ELIMINAR TIPO DE MEMBRESIA" << endl;
	cout << "-----------------------------" << endl;
	listarTiposMembresia();
    cout << "Ingrese el ID del tipo a eliminar: "<<endl;
    cin >> idMembresia;
    cin.ignore();



    while(idMembresia < 0){
		cout << "Ingrese un ID valido: "<<endl;
		cin >> idMembresia;
    }

    int pos = _tipoMembresiaArchivo.buscarById(idMembresia);

    if (pos < 0) {
        cout << "Tipo de membresia no encontrado." << endl;
        return;
    }

	system("cls");

    TipoMembresia membresiaActual = _tipoMembresiaArchivo.leer(pos);

    mostrarTipoMembresia(membresiaActual);
    cout << "Esta seguro que desea eliminar esta membresia? S/N"<< endl;
    char respuesta;
	cin>>respuesta;

    if(respuesta == 's'||respuesta == 'S'){
		vector<TipoMembresia> membresias = _tipoMembresiaArchivo.leerTodas();
		auto it = remove_if(membresias.begin(), membresias.end(), [idMembresia](const TipoMembresia &membresia) {
								return membresia.getTipoMembresia() == idMembresia;
							});
		if (it != membresias.end()) {
			membresias.erase(it, membresias.end());
			_tipoMembresiaArchivo.actualizar(membresias);
			cout << "Tipo de membresia eliminado exitosamente." << endl;
		} else {
			cout << "Tipo de membresia no encontrado." << endl;
		}
    } else{return;}
}

void TipoMembresiaManager::listarMembresiasActivas() {
	vector<TipoMembresia> tiposMembresias = _tipoMembresiaArchivo.leerTodas();
    sort(tiposMembresias.begin(), tiposMembresias.end(), [](const TipoMembresia &a, const TipoMembresia &b) {
        return a.getTipoMembresia() < b.getTipoMembresia();
    });
    for (const auto &tipoMembresia : tiposMembresias) {
		if(tipoMembresia.getEstado()){
			if(tiposMembresias.size()<1){
				cout<<"No hay Membresias activas"<<endl;
			}
			mostrarTipoMembresia(tipoMembresia);
		}
    }
}

void TipoMembresiaManager::listarOtrasMembresias(int id) {
	vector<TipoMembresia> tiposMembresias = _tipoMembresiaArchivo.leerTodas();
    sort(tiposMembresias.begin(), tiposMembresias.end(), [](const TipoMembresia &a, const TipoMembresia &b) {
        return a.getTipoMembresia() < b.getTipoMembresia();
    });
    for (const auto &tipoMembresia : tiposMembresias) {
			if(tipoMembresia.getEstado() == true && tipoMembresia.getTipoMembresia() != id){
				mostrarTipoMembresia(tipoMembresia);
			}
    }
}

void TipoMembresiaManager::listarMembresiasInactivas() {
	vector<TipoMembresia> tiposMembresias = _tipoMembresiaArchivo.leerTodas();
    sort(tiposMembresias.begin(), tiposMembresias.end(), [](const TipoMembresia &a, const TipoMembresia &b) {
        return a.getTipoMembresia() < b.getTipoMembresia();
    });
    for (const auto &tipoMembresia : tiposMembresias) {
		if(tipoMembresia.getEstado()==false){
			if(tiposMembresias.size()<1){
				cout<<"No hay Membresias Inactivas"<<endl;
			}
			mostrarTipoMembresia(tipoMembresia);
		}
    }
}
