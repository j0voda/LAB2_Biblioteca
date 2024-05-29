#include <iostream>
#include<cstdlib>
#include<cstring>
#include <vector>

using namespace std;

#include "UsuarioManager.h"

   void listarUsuariosPorNombre();
   void listarUsuariosPorApellido(); ///desarrollar


void UsuarioManager::menu(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR USUARIOS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Modificar Usuario" << endl;
        cout << "3. Listar Usuarios" << endl;
        cout << "4. Eliminar Usuario" << endl;
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
                listarUsuarios();
                system("pause");
                break;

            case 4:
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

Usuario UsuarioManager::crearUsuario(){

    string nombre, apellido, telefono, mail, clave;
    int permisos;

    cout << "Ingrese el nombre del nuevo usuario: ";
    getline(cin, nombre); //uso getLine para obtener los espacios tambien
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese teléfono: ";
    getline(cin, telefono);
    cout << "Ingrese email: ";
    cin >> mail;
    getline(cin, mail);
    cout << "Ingrese una nueva clave: ";
    getline(cin, clave);
    cout << "Ingrese permisos (1 para Bibliotecario, 2 para Cliente): ";
    cin >> permisos;
    cin.ignore();

    int id = _UsuariosArchivo.getNuevoID();
    Usuario usuario(id, nombre, apellido, telefono, mail, clave, permisos);

    return usuario;
}

void UsuarioManager::agregarUsuario() {
    Usuario usuario = crearUsuario();

    if (_UsuariosArchivo.guardar(usuario)) {
        cout << "Usuario agregado con éxito." << endl;
    } else {
        cout << "Error al agregar el usuario." << endl;
    }
}

void UsuarioManager::modificarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario a modificar: "; //Aca deberia listar los usuarios
    cin >> id;

    int index = _UsuariosArchivo.buscarPorID(id);
    if (index == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    Usuario usuario = _UsuariosArchivo.leer(index);
    mostrarUsuario(usuario);

    cout << "Ingrese los nuevos datos del usuario." << endl;
    Usuario nuevoUsuario = crearUsuario();
    nuevoUsuario.setID(id);

    if (_UsuariosArchivo.modificar(index, nuevoUsuario)) {
        cout << "Usuario modificado con éxito." << endl;
    } else {
        cout << "Error al modificar el usuario." << endl;
    }
}

void UsuarioManager::listarUsuarios() {
    vector<Usuario> usuarios = _UsuariosArchivo.cargarUsuarios();
    for (const Usuario &usuario : usuarios) {
        mostrarUsuario(usuario);
    }
}
///Aca se podria hacer un "Listar" que lleve a un submenu con "Listar por Nombre, apellido..."

void UsuarioManager::listarUsuariosPorPermiso() {
    vector<Usuario> usuarios = _UsuariosArchivo.cargarUsuarios();
    for (const Usuario &usuario : usuarios) {
        if (usuario.getPermisos() == 1) { // Asumiendo que 1 representa bibliotecarios
            mostrarUsuario(usuario);
        } if (usuario.getPermisos() == 2) { // Asumiendo que 2 representa clientes
            mostrarUsuario(usuario);
        }
    } ///CHEQUEAR
}

void UsuarioManager::eliminarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;

    int index = _UsuariosArchivo.buscarPorID(id);
    if (index == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    // Aquí falta implementar una lógica para marcar al usuario como eliminado
    // o reescribir todos los usuarios excepto el eliminado.
}

void UsuarioManager::mostrarUsuario(const Usuario &registro) {
    cout << "ID: " << registro.getID() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Teléfono: " << registro.getTelefono() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "Clave: " << registro.getClave() << endl; //Solo va a mostrarse en el acceso del bibliotecario
    cout << "Permisos: " << registro.getPermisos() << endl; //Aca deberia aparecer biblio o cliente, no el num
    cout << "-----" << endl;
}
