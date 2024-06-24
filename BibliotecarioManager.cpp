#include "BibliotecarioManager.h"

BibliotecarioManager::BibliotecarioManager(){
    //ctor
}

bool BibliotecarioManager::ingresarClave() {
    string claveMaestra;
    cout << "Ingrese la clave maestra para registrar un bibliotecario: ";
    getline(cin, claveMaestra);

    if (claveMaestra != "4321") {
        cout << "Clave maestra incorrecta. No se puede registrar como bibliotecario." << endl;
        cin.ignore();

        return false;
    }

    cout << "Clave maestra ingresada con exito.";
    cin.ignore();

    return true;
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

void BibliotecarioManager::mostrarBibliotecario(const Usuario &registro) {
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "-----" << endl;
}

void BibliotecarioManager::listarBibliotecarios() {
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1); // 1 permisos de bibliotecario
    sort(bibliotecarios.begin(), bibliotecarios.end(), [](const Usuario &a, const Usuario &b) {
        return a.getId() < b.getId();
    });
    cout << "Bibliotecarios disponibles: "<<endl;
    for (const Usuario &bibliotecario : bibliotecarios) {
        Bibliotecario ub = Bibliotecario(bibliotecario.getNombre(), bibliotecario.getApellido(), bibliotecario.getTelefono(), bibliotecario.getMail(), bibliotecario.getId(), bibliotecario.getClave(), 1);
        this->mostrarBibliotecario(ub);
    }
}

void BibliotecarioManager::listarBibliotecariosPorNombre() {
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1); // 1 permisos de bibliotecario
    sort(bibliotecarios.begin(), bibliotecarios.end(), [](const Usuario &a, const Usuario &b) {
        string nombreA = a.getNombre();
        string nombreB = b.getNombre();
        //convierto en minusc para poder hacer la comparacion
        transform(nombreA.begin(),nombreA.end(),nombreA.begin(),::tolower);
        transform(nombreB.begin(),nombreB.end(),nombreB.begin(),::tolower);
        return  nombreA < nombreB;
    });
    cout << "Bibliotecarios disponibles por nombre: "<<endl;
    for (const Usuario &bibliotecario : bibliotecarios) {
        Bibliotecario ub = Bibliotecario(bibliotecario.getNombre(), bibliotecario.getApellido(), bibliotecario.getTelefono(), bibliotecario.getMail(), bibliotecario.getId(), bibliotecario.getClave(), 1);
        this->mostrarBibliotecario(ub);
    }
}

void BibliotecarioManager::listarBibliotecariosPorApellido() {
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1); // 1 permisos de bibliotecario
    sort(bibliotecarios.begin(), bibliotecarios.end(), [](const Usuario &a, const Usuario &b) {
        string apA = a.getApellido();
        string apB = b.getApellido();
        //convierto en minusc para poder hacer la comparacion
        transform(apA.begin(),apA.end(),apA.begin(),::tolower);
        transform(apB.begin(),apB.end(),apB.begin(),::tolower);
        return  apA < apB;
	});
    cout << "Bibliotecarios disponibles por apellido: "<<endl;
    for (const Usuario &bibliotecario : bibliotecarios) {
        Bibliotecario ub = Bibliotecario(bibliotecario.getNombre(), bibliotecario.getApellido(), bibliotecario.getTelefono(), bibliotecario.getMail(), bibliotecario.getId(), bibliotecario.getClave(), 1);
        this->mostrarBibliotecario(ub);
    }
}

void BibliotecarioManager::menuAdministrarClientes(){
}


/*Bibliotecario BibliotecarioManager::validarLoginBibliotecario(const string& mail, const string& clave, int permisos) {
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
}*/

