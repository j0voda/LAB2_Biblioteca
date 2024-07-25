#include "PrestamoManager.h"

PrestamoManager::PrestamoManager(){}

Prestamo PrestamoManager::crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente, bool devuelto){
	Fecha fechaPrestamo = fechaPrestamo.obtenerFechaActual();
    Fecha fechaDevolucion = fechaPrestamo.sumarMes(1);

    Prestamo prestamo(idPrestamo, fechaPrestamo, fechaDevolucion, libro, cliente, devuelto);
    return prestamo;
}

int PrestamoManager::validarPrestamo(const Usuario &cliente) {
    int idCliente = cliente.getId();
    Membresia membresiaCliente = _membresiaArchivo.leer(_membresiaArchivo.buscarPorIdUsuario(idCliente));
    Cliente cl(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), cliente.getPermisos(), membresiaCliente); // Agrega Membresia según sea necesario
    TipoMembresia tipoMembresiaCliente = membresiaCliente.getTipoMembresia();

    int prestamosActivos = contarPrestamosActivos(idCliente);
    int prestamosActivosMax = tipoMembresiaCliente.getLibrosAlaVez();
    int prestamosPorMesMax = tipoMembresiaCliente.getLibrosXMes();

    // Obtener la fecha actual
    Fecha fechaActual = Fecha::obtenerFechaActual();

    // Calcular el inicio y fin del mes actual
    Fecha fechaInicioMes(fechaActual.getDia(), fechaActual.getMes(), fechaActual.getAnio());
    fechaInicioMes.setDia(1); // Primer día del mes actual
    Fecha fechaFinMes = fechaInicioMes.sumarMes(1);
    fechaFinMes.setDia(0); // Último día del mes actual

    int prestamosEnElMes = _prestamoArchivo.buscarPorRangoFecha(fechaInicioMes, fechaFinMes);

    if(prestamosActivos < prestamosActivosMax && prestamosEnElMes < prestamosPorMesMax) {
        return 1; // Prestamo permitido
    }
    if(prestamosEnElMes == prestamosPorMesMax) {
        return -1; // Máximo de prestamos por mes alcanzado
    } else if (prestamosActivos == prestamosActivosMax && prestamosEnElMes < prestamosPorMesMax) {
        return 0; // Máximo de prestamos simultáneos alcanzado
    }

    return 0; // Condición por defecto, aunque no debería llegar aquí
}

void PrestamoManager::solicitarPrestamo() {
    int idLibro;//idCliente, ;
    string clave;
	//vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2);
	Usuario clienteActivo = _usuarioManager.clienteActivo();
	int validacion;

	system("cls");

    cout << "-----------------------------" << endl;
	cout << "SOLICITAR PRESTAMO" << endl;
	cout << "-----------------------------" << endl;
	validacion = validarPrestamo(clienteActivo);

	if(validacion == -1){
		cout<<"Alcanzaste el maximo de prestamos en el mes";
		return;
	}
	if(validacion == 0){
		cout<<"Para solicitar otro libro debes realizar una devolucion";
		return;
	}



	cout << "Ingrese el ID del libro a solicitar | ";
	cout << "Ingrese 0 si desea listar los libros disponibles"<<endl;
	cin >> idLibro;

	while(idLibro == 0){
		_libroManager.listarLibrosDisponibles();
		if(_libroManager.contarLibrosDisponibles()<=0){
			return;
		}
		cout << "Ingrese el ID del libro a solicitar: ";
		cin >> idLibro;
	}

	int posLibro = _libroArchivo.buscarById(idLibro);

	if (posLibro < 0) {
		cout << "Libro no encontrado." << endl;
		return;
	}

	Libro libro = _libroArchivo.leer(posLibro);


    system("cls");
    cout<<"Solicitar prestamo del libro:"<<endl;
    _libroManager.mostrarLibro(libro);

    if (libro.getDisponibles() > 0) {
		cout << "Para reservar ingrese nuevamente su clave: ";
		cin >> clave;

		if(_usuarioManager.dobleValidacion(clave)){
			clienteActivo = _usuarioManager.clienteActivo();

			int nuevoId = _prestamoArchivo.getNuevoID();
			Prestamo prestamo = crearPrestamo(nuevoId, libro, clienteActivo,false);

			_prestamoArchivo.guardar(prestamo);
			libro.setDisponibles(libro.getDisponibles() - 1);
			_libroArchivo.modificar(posLibro,libro);

			cout << "Prestamo realizado con exito!" << endl;
		} else {
			cout << "El libro no esta disponible para prestamo en este momento." << endl;
		}

	}

}

int PrestamoManager::contarPrestamosActivos(int idCliente){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();
	int contador = 0;
    for (const auto &prestamo : prestamos) {
        if (prestamo.getDevuelto()== false && prestamo.getCliente().getId() == idCliente){
			contador++;
        }
    }
    return contador;
}

void PrestamoManager::listarPrestamos(){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();
	sort(prestamos.begin(), prestamos.end(), [](const Prestamo &a, const Prestamo &b) {
        return a.getIdPrestamo() < b.getIdPrestamo();
    });
    for (const Prestamo &prestamo : prestamos) {
        Prestamo p = Prestamo(prestamo.getIdPrestamo(),prestamo.getFechaPrestamo(),prestamo.getFechaDevolucion(),prestamo.getLibro(),prestamo.getCliente(),prestamo.getDevuelto());
        this->mostrarPrestamo(p);
    }
}

void PrestamoManager::listarPrestamosPorIdCliente(int idCliente){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        if (prestamo.getCliente().getId() == idCliente) {
            mostrarPrestamo(prestamo);
        }
    }

}

void PrestamoManager::listarPrestamosActivos(int idCliente){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        if (prestamo.getCliente().getId() == idCliente && prestamo.getDevuelto() == false) {
            mostrarPrestamo(prestamo);
        }
    }
}

void PrestamoManager::listarPrestamosCliente() {
    string mail, clave;
    Usuario clienteActivo;

    system("cls");

    cout << "-----------------------------" << endl;
    cout << "LISTAR PRESTAMOS DEL CLIENTE" << endl;
    cout << "-----------------------------" << endl;

    cout << "Para listar sus prestamos, ingrese nuevamente su clave: ";
	cin >> clave;

	//bool tienePrestamos = false;
	if(_usuarioManager.dobleValidacion(clave)){
		clienteActivo = _usuarioManager.clienteActivo();
		int idCliente = clienteActivo.getId();
		//tienePrestamos = true;
		listarPrestamosPorIdCliente(idCliente);
	}

	/*if (!tienePrestamos) {
		cout << "El cliente no tiene prestamos registrados." << endl;
	}*/
	else {
		cout << "Credenciales invalidas. Por favor, intente nuevamente." << endl;
	}

}

void PrestamoManager::realizarDevolucion() {
    string clave;
    Usuario clienteActivo;

    system("cls");

    cout << "-----------------------------" << endl;
    cout << "REALIZAR DEVOLUCION" << endl;
    cout << "-----------------------------" << endl;

    cout << "Para realizar una devolucion ingrese nuevamente su clave: ";
	cin >> clave;

	if(_usuarioManager.dobleValidacion(clave)){
		clienteActivo = _usuarioManager.clienteActivo();
		int idCliente, idLibro, posLibro;
		idCliente = clienteActivo.getId();

		//vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();
		//vector<Prestamo> prestamosActivos;


		system("cls");

		cout << "-----------------------------" << endl;
		cout << "REALIZAR DEVOLUCION" << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		cout << "Prestamos activos de " << clienteActivo.getNombre() << ":" << endl;
		cout << endl;
		/*
		for (const auto &prestamo : prestamos) {
			if (prestamo.getCliente().getId() == idCliente && !prestamo.getDevuelto()) {
				//prestamosActivos.push_back(prestamo);
				mostrarPrestamo(prestamo);
			}
		}*/

		listarPrestamosActivos(idCliente);

		//cout << "Cant prestamos Activos: " << contarPrestamosActivos(idCliente) << endl; // Debug
		if (contarPrestamosActivos(idCliente)<1) {
			cout << "No tiene prestamos activos para devolver." << endl;
			return;
		}

		int idPr;
		cout << "Ingrese el ID del prestamo que desea devolver: ";
		cin >> idPr;
		cin.ignore();

		int pos = _prestamoArchivo.buscarById(idPr);
		cout << "Posicion del prestamo: " << pos << endl; // Debug
		if(pos==-1){
			cout << "Prestamo no encontrado o no pertenece a usted." << endl;
			return;
		}

		system("cls");
		Prestamo prestamo = _prestamoArchivo.leer(pos);
		mostrarPrestamo(prestamo);
		cout << endl;
		cout<<"Desea devolver este libro? S/N"<<endl;
		char respuesta;
		cin>>respuesta;
		if(respuesta == 'n' || respuesta == 'N'){
			return;
		}

		idLibro = prestamo.getLibro().getIdLibro();
		posLibro = _libroArchivo.buscarById(idLibro);
		Libro libro = _libroArchivo.leer(posLibro);
		//_libroManager.mostrarLibro(libro);

		Fecha fechaDevolucion = fechaDevolucion.obtenerFechaActual();

		prestamo.setFechaDevolucion(fechaDevolucion);
		prestamo.setDevuelto(true);
		_prestamoArchivo.modificar(pos, prestamo);

		libro.setDisponibles(libro.getDisponibles() + 1);
		_libroArchivo.modificar(posLibro, libro);

		cout << "Devolucion realizada con exito!" << endl;

	}
}


/*
bool PrestamoManager::puedePedirPrestamo(int idCliente) {
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();
    int cantidadPrestamosActivos = 0;

    for (const auto &prestamo : prestamos) {
        if (prestamo.getCliente().getId() == idCliente && !prestamo.getDevuelto()) {
            if (estaVencido(prestamo)) {
                return false; // No puede pedir préstamo si tiene préstamos vencidos
            }
            cantidadPrestamosActivos++;
        }
    }
	//Aca puedo pedir el tipo de membresia, si es 1 el limite de prestamos activos es 2 si la embresia es 2 el limite es 5
    // Supongamos que el límite de préstamos activos es 5
    return cantidadPrestamosActivos < 5;
}*/

void PrestamoManager::mostrarPrestamo(const Prestamo &registro) {
    cout << "ID Prestamo: " << registro.getIdPrestamo() << endl;
    cout << "Fecha Prestamo: " << registro.getFechaPrestamo().toString() << endl;
    cout << "Fecha Devolucion: " << registro.getFechaDevolucion().toString() << endl;
    cout << "Libro: " << registro.getLibro().getTitulo() << " (ID: " << registro.getLibro().getIdLibro() << ")" << endl;
    cout << "Cliente: " << registro.getCliente().getNombre() << " (ID: " << registro.getCliente().getId() << ")" << endl;
    cout << "Devuelto: " << (registro.getDevuelto() ? "Si" : "No") << endl;
    cout << "-------------------------" << endl;
}

bool PrestamoManager::estaVencido(const Prestamo &prestamo) {
    Fecha fechaActual; // Obtener fecha actual
    Fecha fechaDevolucion = prestamo.getFechaDevolucion();

    // Comparar fechas para determinar si el préstamo está vencido
    if (fechaActual > fechaDevolucion) {
        return true;
    }
    return false;
}
