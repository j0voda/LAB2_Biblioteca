#include "Bibliotecario.h"

Bibliotecario::Bibliotecario() : Usuario() {}

Bibliotecario::Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {}

bool Bibliotecario::ingresarClave() {
    string claveMaestra;
    cout << "Ingrese la clave maestra para registrar un bibliotecario: ";
    getline(cin, claveMaestra);

    if (claveMaestra != "4321") {
        cout << "Clave maestra incorrecta. No se puede registrar como bibliotecario." << endl;
        return false;
    }

    return true;
}

void Bibliotecario::menuBibliotecario() {
    UsuarioManager usuarioManager;
    int opcion;
    system("cls");

    do {
        cout << "MENU BIBLIOTECARIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Administrar libros" << endl;
        cout << "2. Administrar autores" << endl;
        cout << "3. Administrar categorías" << endl;
        cout << "4. Administrar usuarios" << endl;
        cout << "5. Administrar membresías" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                libroManager.menu();
                break;
            case 2:
                autorManager.menu();
                break;
            case 3:
                categoriaManager.menu();
                break;
            case 4:
                usuarioManager.menuAdministrarUsuarios();
                break;
            case 5:
                membresiaManager.menuAdministrarMembresias();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);
}

