#include "ClienteManager.h"

ClienteManager::ClienteManager()
{
    //ctor
}

Cliente ClienteManager::validarLoginCliente(const string& mail, const string& clave, int permisos) {
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


void ClienteManager::listarClientes() {
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, false);
        this->mostrarCliente(c);
    }
}

void ClienteManager::menuClienteMembresia(int idUsuario) {
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
                cout << "Ingrese nuevo tipo de membresía (1 para Básica, 2 para Premium): ";
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

void ClienteManager::menuCliente() {
    int opcion;
    LibroManager libroManager;
    MembresiaManager membresiaManager;
    PagoArchivo pagoArchivo;

    do {
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

void ClienteManager::mostrarCliente(Cliente c){
}
