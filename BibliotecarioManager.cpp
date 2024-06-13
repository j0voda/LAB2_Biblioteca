#include "BibliotecarioManager.h"

BibliotecarioManager::BibliotecarioManager()
{
    //ctor
}

void BibliotecarioManager::menuBibliotecario() {
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
                _libroManager.menu();
                break;
            case 2:
                _autorManager.menu();
                break;
            case 3:
                _categoriaManager.menu();
                break;
            case 4:
                menuAdministrarClientes();
                break;
            case 5:
                _membresiaManager.menuAdministrarMembresias();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);
}


Bibliotecario BibliotecarioManager::validarLoginBibliotecario(const string& mail, const string& clave, int permisos) {
    cout << "Validando usuario";
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    for (const auto &usuario : usuarios) {
        cout << usuario.getMail();
        if (usuario.getMail() == mail && usuario.getClave() == clave) {
            Bibliotecario ub = Bibliotecario(usuario.getNombre(), usuario.getApellido(), usuario.getTelefono(), usuario.getMail(), usuario.getId(), usuario.getClave(), permisos);
            return ub;
        }
    }
    return Bibliotecario(); // Retornar un usuario vacío si no se encuentra
}

void BibliotecarioManager::listarBibliotecarios() {
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1); // 1 permisos de bibliotecario
    for (const Usuario &bibliotecario : bibliotecarios) {
        Bibliotecario ub = Bibliotecario(bibliotecario.getNombre(), bibliotecario.getApellido(), bibliotecario.getTelefono(), bibliotecario.getMail(), bibliotecario.getId(), bibliotecario.getClave(), 1);
        this->mostrarBibliotecario(ub);
    }
}

void BibliotecarioManager::mostrarBibliotecario(Bibliotecario b){

}

void BibliotecarioManager::menuAdministrarClientes(){
}
