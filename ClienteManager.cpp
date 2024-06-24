#include "ClienteManager.h"

ClienteManager::ClienteManager(){
    //ctor
}

void ClienteManager::asignarMembresia(){
    int tipoMembresia;
    cout << "Ingrese su membresía (1 para Básica, 2 para Premium): ";
    cin >> tipoMembresia;

    /*
    if (tipoMembresia < 1 || tipoMembresia > 2){
        cout << "Membresia incorrecta. No se puede registrar como cliente." << endl;
        return;
    }

    Fecha fechaInicio = Fecha::obtenerFechaActual();
    Fecha fechaFin = fechaInicio.sumarMes(1);

    Membresia membresia(_membresiaManager.getNuevoID(), _cliente.getId(), tipoMembresia, fechaInicio, fechaFin, true);
    _membresiaManager.guardarMembresia(membresia);
    */

    cout << "Membresía asignada con éxito. Cliente registrado" << endl;

}

void ClienteManager::menuCliente() {
    int opcion;
    do {
        cout << "MENU CLIENTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Ver libros" << endl;
        cout << "2. Pedir libro" << endl;
        cout << "3. Devolver libro" << endl;
        cout << "4. Mi membresía" << endl;
        cout << "5. Administrar pagos" << endl;
        cout << "6. Ver historial de préstamos" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Aca vemos libros";//libroManager.listarLibros();
                break;
            case 2:
                cout << "Aca pedimos libros";//libroManager.pedirLibro();
                break;
            case 3:
                cout << "Aca devolvemos libros";//libroManager.devolverLibro();
                break;
            case 4:
                cout << "Aca vemos la membresia";//membresiaManager.verEstadoMembresia();
                break;
            case 5:
                cout << "Aca vemos los pagos";//pagoArchivo.mostrarPagos();
                break;
            case 6:
                cout << "Aca vemos los prestamos";// Función para ver el historial de préstamos
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);
}

void ClienteManager::menuMiMembresia(int idUsuario) {
    int opcion;
    do {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR MI MEMBRESIA" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Ver Estado de Membresía" << endl;
        cout << "2. Realizar Pago" << endl;
        cout << "3. Cambiar Tipo de Membresía" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                _membresiaManager.verEstadoMembresia(idUsuario);
                break;
            case 2:
                _membresiaManager.realizarPago(idUsuario);
                break;
            case 3:
                int nuevoTipo;
                cout << "Ingrese nuevo tipo de membresia (1 para Basica, 2 para Premium): ";
                cin >> nuevoTipo;
                _membresiaManager.cambiarTipoMembresia(idUsuario, nuevoTipo);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);
}

void ClienteManager::mostrarCliente(const Usuario &registro) {
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "-----" << endl;
}

void ClienteManager::listarClientes() {
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        return a.getId() < b.getId();
    });
    cout << "Clientes disponibles: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, false);
        this->mostrarCliente(c);
    }
}

void ClienteManager::listarClientesPorNombre() {
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        string nombreA = a.getNombre();
        string nombreB = b.getNombre();
        //convierto en minusc para poder hacer la comparacion
        transform(nombreA.begin(),nombreA.end(),nombreA.begin(),::tolower);
        transform(nombreB.begin(),nombreB.end(),nombreB.begin(),::tolower);
        return  nombreA < nombreB;
    });
    cout << "Clientes disponibles por nombre: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, false);
        this->mostrarCliente(c);
    }
}

void ClienteManager::listarClientesPorApellido() {
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        string apA = a.getApellido();
        string apB = b.getApellido();
        //convierto en minusc para poder hacer la comparacion
        transform(apA.begin(),apA.end(),apA.begin(),::tolower);
        transform(apB.begin(),apB.end(),apB.begin(),::tolower);
        return  apA < apB;
	});
    cout << "Clientes disponibles por apellido: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, false);
        this->mostrarCliente(c);
    }
}





/*Cliente ClienteManager::validarLoginCliente(const string& mail, const string& clave, int permisos) {
    cout << "Validando usuario";
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    for (const auto &usuario : usuarios) {
        cout << usuario.getMail();
        if (usuario.getMail() == mail && usuario.getClave() == clave) {
            Cliente uc = Cliente(usuario.getNombre(), usuario.getApellido(), usuario.getTelefono(), usuario.getMail(), usuario.getId(), usuario.getClave(), permisos, false);
            return uc;
        }
    }
    return Cliente(); // Retornar un usuario vacío si no se encuentra
}
*/
