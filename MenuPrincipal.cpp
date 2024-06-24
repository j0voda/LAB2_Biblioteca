#include <string>

using namespace std;

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
                registrarse();
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opci�n no v�lida. Intente nuevamente." << endl;
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

    if (tipoUsuario == 1) {
        _bibliotecarioManager.listarBibliotecarios();
    } else if(tipoUsuario == 2) {
        _clienteManager.listarClientes();
    }

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese clave: ";
    getline(cin, clave);

    if (tipoUsuario == 1) {
        Usuario bibliotecario = _usuarioManager.validarLogin(email, clave, tipoUsuario);
        if (bibliotecario.getMail() != "") {
            cout << "Usuario validado"<<endl;
            _bibliotecarioManager.menuBibliotecario();
        } else {
            cout << "Credenciales incorrectas. Intente nuevamente." << endl;
            cin.ignore();
        }
    } else if(tipoUsuario == 2) {
        Usuario cliente = _usuarioManager.validarLogin(email, clave, tipoUsuario);
        if(cliente.getMail() != ""){
            cout << "Usuario validado"<<endl;
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
