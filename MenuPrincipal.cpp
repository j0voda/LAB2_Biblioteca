#include "MenuPrincipal.h"
#include "Bibliotecario.h"
#include <string>

using namespace std;

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

    if (tipoUsuario == 1) {
        Bibliotecario bibliotecario = _bibliotecarioManager.validarLoginBibliotecario(email, clave, tipoUsuario);
        if (bibliotecario.getMail() != "") {
            cout << "Usuario validado";
            //_usuarioManager.crearUsuario(tipoUsuario);
            _bibliotecarioManager.menuBibliotecario();
        } else {
            cout << "Credenciales incorrectas. Intente nuevamente." << endl;
            cin.ignore();
        }
    } else if(tipoUsuario == 2) {
        Cliente cliente = _clienteManager.validarLoginCliente(email, clave, tipoUsuario);
        if(cliente.getMail() != ""){
            cout << "Usuario validado";
            //_usuarioManager.crearUsuario(tipoUsuario);
            _clienteManager.menuCliente();
        }else {
            cout << "Credenciales incorrectas. Intente nuevamente." << endl;
            cin.ignore();
        }
    } else {
        cout << "Ingrese una de las opciones validas.";
        cin.ignore();
    }
}

void MenuPrincipal::registrarse(){

    int permiso,opcion;

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
