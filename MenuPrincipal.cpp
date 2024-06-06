#include "MenuPrincipal.h"

void MenuPrincipal::menuInicio() {
    int opcion;

    do {
        system("cls");
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                registrarse();// Lógica para registrarse (puedes implementar esta función similar a iniciarSesion)
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);
}

void MenuPrincipal::iniciarSesion() {
    string email, clave;
    int tipoUsuario;

    system("cls");

    cout << "INICIAR SESION" << endl;
    cout << "-----------------------------" << endl;
    cout << "Ingrese tipo de usuario (1: Bibliotecario, 2: Cliente): ";
    cin >> tipoUsuario;
    cin.ignore();

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese clave: ";
    getline(cin, clave);

    Usuario usuario = _usuarioManager.validarLogin(email, clave, tipoUsuario);
    if (usuario.getMail() != "") {
        if (tipoUsuario == 1) {
            _bibliotecario.menuBibliotecario();
        } else {
            _cliente.menuCliente();
        }
    } else {
        cout << "Credenciales incorrectas. Intente nuevamente." << endl;
        cin.ignore();

    }
}

void MenuPrincipal::registrarse(){

    int permiso,opcion;

    //UsuarioManager _usuarioManager;

    system("cls");
    do {
        cout << "1. Registrarme como bibliotecario" << endl;
        cout << "2. Registrarme como cliente" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        permiso = opcion;

        switch (opcion) {
            case 1:
                _usuarioManager.crearUsuario(permiso);
                return;
                break;
            case 2:
                _usuarioManager.crearUsuario(permiso);
                return;
                break;
            case 0:
                cout << "Saliendo..." << endl;
                return;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
            }
    } while (opcion != 0);
}


/*void MenuPrincipal::menuCliente() {
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
*/
