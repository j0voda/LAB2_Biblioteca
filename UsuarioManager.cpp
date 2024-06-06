#include <iostream>
#include<cstdlib>
#include<cstring>
#include <vector>

using namespace std;

#include "UsuarioManager.h"

void listarUsuariosPorNombre();
void listarUsuariosPorApellido(); ///desarrollar


Usuario UsuarioManager::crearUsuario(int permisos){ //crear una instancia de Usuario (Cliente o un Bibliotecario)

    string nombre, apellido, telefono, mail, clave;
    bool membresia;

    cout << "Ingrese el nombre del nuevo usuario: ";
    getline(cin, nombre); //uso getLine para obtener los espacios tambien
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese email: ";
    getline(cin, mail);
    cout << "Ingrese una nueva clave: ";
    getline(cin, clave);

    int id = _usuarioArchivo.getNuevoID();

    if (permisos == 1) {

        Bibliotecario bibliotecario(nombre, apellido, telefono, mail, id, clave, permisos);

        if(bibliotecario.ingresarClave()== false){
            return Usuario(); //clave incorrecta
        }
        if (_usuarioArchivo.guardar(bibliotecario)) {
            cout << "Bibliotecario agregado con éxito." << endl;
            return bibliotecario;

        } else {
            cout << "Error al agregar el bibliotecario." << endl;
            return Usuario();
        }

    } else if (permisos == 2) {

        Cliente cliente(nombre, apellido, telefono, mail, id, clave, permisos, false);

        if (_usuarioArchivo.guardar(cliente)) {
            cliente.asignarMembresia(_membresiaManager);
            return cliente;
        } else {
            cout << "Error al agregar el cliente." << endl;
            return Usuario();
        }
    }
    cout << "Permisos inválidos." << endl;
    return Usuario(); // En caso de un permiso no válido, me devuelve un usuario vacío
}

void UsuarioManager::modificarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario a modificar: "; //Aca deberia listar los usuarios
    cin >> id;

    int index = _usuarioArchivo.buscarById(id);
    if (index == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    Usuario usuario = _usuarioArchivo.leer(index);
    mostrarUsuario(usuario);

    cout << "Ingrese los nuevos datos del usuario." << endl;

    int permisos = usuario.getPermisos();
    Usuario nuevoUsuario = crearUsuario(permisos);
    nuevoUsuario.setId(id);

    if (_usuarioArchivo.modificar(index, nuevoUsuario)) {
        cout << "Usuario modificado con éxito." << endl;
    } else {
        cout << "Error al modificar el usuario." << endl;
    }
}

void UsuarioManager::mostrarUsuario(const Usuario &registro) {
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Teléfono: " << registro.getTelefono() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "Clave: " << registro.getClave() << endl; //Solo va a mostrarse en el acceso del bibliotecario
    cout << "Permisos: " << registro.getPermisos() << endl; //Aca deberia aparecer biblio o cliente, no el num
    cout << "-----" << endl;
}

void UsuarioManager::eliminarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;

    int index = _usuarioArchivo.buscarById(id);
    if (index == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    //  falta implementar una lógica para marcar al usuario como eliminado
    // o reescribir todos los usuarios excepto el eliminado.
}


Usuario UsuarioManager::validarLogin(const string &mail, const string &clave, int permisos) {
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    for (const auto &usuario : usuarios) {
        if (usuario.getMail() == mail && usuario.getClave() == clave) {
            return usuario;
        }
    }
    return Usuario(); // Retornar un usuario vacío si no se encuentra
}



/*void UsuarioManager::listarUsuarios() {
    vector<Usuario> usuarios = _usuarioArchivo.cargarUsuarios();
    for (const Usuario &usuario : usuarios) {
        mostrarUsuario(usuario);
    }
}*/

void UsuarioManager::agregarUsuario() { //Solicita los permisos antes de llamar a crearUsuario

    int permisos;

    cout << "Ingrese permisos (1 para Bibliotecario, 2 para Cliente): ";
    cin >> permisos;
    cin.ignore();

    Usuario usuario = crearUsuario(permisos);
}

void UsuarioManager::listarBibliotecarios() {
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1); // 1 permisos de bibliotecario
    for (const Usuario &bibliotecario : bibliotecarios) {
        mostrarUsuario(bibliotecario);
    }
}

void UsuarioManager::listarClientes() {
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    for (const Usuario &cliente : clientes) {
        mostrarUsuario(cliente);
    }
}

void UsuarioManager::menuAdministrarUsuarios(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR USUARIOS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Modificar Usuario" << endl;
        cout << "3. Listar Clientes" << endl;
        cout << "4. Listar Bibliotecarios" << endl;
        cout << "5. Eliminar Usuario" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
                agregarUsuario();
                system("pause");
                break;

            case 2:
                modificarUsuario();
                system("pause");
                break;

            case 3:
                listarClientes();
                system("pause");
                break;

            case 4:
                listarBibliotecarios();
                system("pause");
                break;

            case 5:
                eliminarUsuario();
                system("pause");
                break;

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;

        }
    } while (opcion != 0);
}

void UsuarioManager::menuClienteMembresia(int idUsuario) {
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





