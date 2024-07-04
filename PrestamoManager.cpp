#include "PrestamoManager.h"

PrestamoManager::PrestamoManager(){}

Prestamo PrestamoManager::crearPrestamo(int idPrestamo, const Libro &libro, const Usuario &cliente){
	Fecha fechaPrestamo;
    Fecha fechaDevolucion = fechaPrestamo.sumarMes(1);

    Prestamo prestamo(idPrestamo, fechaPrestamo, fechaDevolucion, libro, cliente, false);
    return prestamo;
}

void PrestamoManager::solicitarPrestamo() {
    int idCliente, idLibro;
    string mail,clave;
	vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2);
	Usuario clienteActivo;

	system("cls");

    cout << "-----------------------------" << endl;
	cout << "SOLICITAR PRESTAMO" << endl;
	cout << "-----------------------------" << endl;

    cout << "Ingrese el ID del libro a solicitar | ";
    cout << "Ingrese 0 si desea listar los libros disponibles"<<endl;
    cin >> idLibro;

    while(idLibro == 0){
		_libroManager.listarLibrosDisponibles();
		cout << "Ingrese el ID del libro a solicitar";
		cin >> idLibro;
    }

    Libro libro = _libroArchivo.leer(_libroArchivo.buscarById(idLibro));
    if (libro.getIdLibro() == 0) {
        cout << "Libro no encontrado." << endl;
        return;
    }
    _libroManager.mostrarLibro(libro);

    cout << "Para reservar ingrese de nuevo su mail y clave."<<endl;
    cout << "Mail: ";
	cin >> mail;
	cout << "Clave: ";
	cin >> clave;

	clienteActivo = _usuarioManager.validarLogin(mail, clave, 2);

	if (clienteActivo.getMail() != "") {
		idCliente=clienteActivo.getId();
	}

    if (libro.getDisponibles() > 0) {

        int nuevoId = _prestamoArchivo.getNuevoID();
        Prestamo prestamo = crearPrestamo(nuevoId, libro, clienteActivo);

        _prestamoArchivo.guardar(prestamo);

        libro.setDisponibles(libro.getDisponibles() - 1);
        _libroArchivo.modificar(_libroArchivo.buscarById(idLibro),libro);

        cout << "Prestamo realizado con exito!" << endl;
    } else {
        cout << "El libro no esta disponible para prestamo en este momento." << endl;
    }
}

void PrestamoManager::listarPrestamos(){
    vector<Prestamo> prestamos = _prestamoArchivo.leerTodos();

    for (const auto &prestamo : prestamos) {
        mostrarPrestamo(prestamo);
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

void PrestamoManager::realizarDevolucion(int idPrestamo) {
    int index = _prestamoArchivo.buscarById(idPrestamo);
    if (index == -1) {
        cout << "Prestamo no encontrado." << endl;
        return;
    }
    Prestamo prestamo = _prestamoArchivo.leer(index);

    // Actualizar la disponibilidad del libro
    Libro libro = prestamo.getLibro();
    libro.setDisponibles(libro.getDisponibles() + 1);
    _libroArchivo.modificar(_libroArchivo.buscarById(libro.getIdLibro()), libro);

    // Marcar el préstamo como devuelto
    prestamo.setDevuelto(true);
    _prestamoArchivo.modificar(index, prestamo);

    cout << "Devolucion realizada con exito!" << endl;
}

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
}

void PrestamoManager::mostrarPrestamo(const Prestamo &registro) {
    cout << "ID Préstamo: " << registro.getIdPrestamo() << endl;
    cout << "Fecha Préstamo: " << registro.getFechaPrestamo().toString() << endl;
    cout << "Fecha Devolución: " << registro.getFechaDevolucion().toString() << endl;
    cout << "Libro: " << registro.getLibro().getTitulo() << " (ID: " << registro.getLibro().getIdLibro() << ")" << endl;
    cout << "Cliente: " << registro.getCliente().getNombre() << " (ID: " << registro.getCliente().getId() << ")" << endl;
    cout << "Devuelto: " << (registro.getDevuelto() ? "Sí" : "No") << endl;
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
