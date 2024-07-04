#include "UsuarioManager.h"

//void listarUsuariosPorNombre();
//void listarUsuariosPorApellido(); ///desarrollar

void UsuarioManager::modificarUsuario() {
	system("cls");
	cout<<endl;
	cout << "MODIFICAR USUARIO" << endl;
	cout << "-----------------------------" << endl;

    int id;
    cout << "Ingrese el ID del usuario a modificar: "; //Aca deberia listar los usuarios
    cin >> id;
    cin.ignore();

    int pos = _usuarioArchivo.buscarById(id);
    if (pos<0) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    Usuario usuarioActual = _usuarioArchivo.leer(pos);
    mostrarUsuario(usuarioActual);
    cout << endl;

    char opcion;
    do {
		cout << "-----------------------------" << endl;
    	cout << "1. Modificar Nombre" << endl;
        cout << "2. Modificar Apellido" << endl;
        cout << "3. Modificar Mail" << endl;
        cout << "4. Modificar Clave" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Finalizar Modificaciones" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case '1': {
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevoNombre);
                usuarioActual.setNombre(nuevoNombre);
                break;
            }
            case '2': {
                string nuevoApellido;
                cout << "Ingrese el nuevo apellido: ";
                getline(cin, nuevoApellido);
                usuarioActual.setApellido(nuevoApellido);
                break;
            }
            case '3': {
                string nuevoMail;
                cout << "Ingrese el nuevo mail: ";
                getline(cin, nuevoMail);
                while(validarMail(nuevoMail)<1){
					cout << "-- Reingrese el mail: ";
					cout<<endl;
					getline(cin, nuevoMail);
				}
                usuarioActual.setMail(nuevoMail);
                break;
            }
            case '4': {
                string nuevaClave;
                string clave;
                cout << "Ingrese la clave anterior: ";
                getline(cin, clave);
                while(usuarioActual.getClave()!=clave){
					cout << "Clave incorrecta. Intente de nuevo.";
					getline(cin, clave);
                }
				cout << "Ingrese la nueva clave: ";
				getline(cin, nuevaClave);
				usuarioActual.setClave(nuevaClave);
				break;
			}
			case '0':
                cout << "Finalizando modificaciones." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
		}
		if (opcion != '0') {
            cout << endl << "Desea modificar otro dato? (s/n): ";
            char continuar;
            cin >> continuar;
            cin.ignore();
            if (continuar == 'n' || continuar == 'N') {
                opcion = '0'; // Salir del bucle
            }
        }
    } while (opcion != '0');

	if (_usuarioArchivo.modificar(pos, usuarioActual)) {
        cout << "Usuario modificado con exito." << endl;
    } else {
        cout << "Error al modificar el usuario." << endl;
    }
}

void UsuarioManager::mostrarUsuario(const Usuario &registro) {
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Telefono: " << registro.getTelefono() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "Clave: " << registro.getClave() << endl; //Solo va a mostrarse en el acceso del bibliotecario
    cout << "Permisos: " << registro.getPermisos() << endl; //Aca deberia aparecer biblio o cliente, no el num
    cout << "-----" << endl;
}

int UsuarioManager::validarMail(const string &mail){
	vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
	regex pattern(R"(([^@]+)@([\w-]+\.(com|org|net|ar|com\.ar)))");
	if(!regex_match(mail,pattern)){
		cout << "Formato de correo invalido." <<endl;
        return -1;
	}
	for (const auto &usuario : usuarios) {
        if (usuario.getMail() == mail) {
            cout << "El correo ya esta registrado." <<endl;
            return 0;
        }
    }
    return 1;
}

void UsuarioManager::eliminarUsuario() {
    int id;
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "ELIMINAR USUARIO" << endl;
	cout << "-----------------------------" << endl;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;
    cin.ignore();

    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    auto it = remove_if(usuarios.begin(), usuarios.end(), [id](const Usuario &usuario){
							return usuario.getId()==id;
						});
	Usuario usuario = _usuarioArchivo.leer(_usuarioArchivo.buscarById(id));
	if (it!=usuarios.end()){
		mostrarUsuario(usuario);
		cout << "Desea borrar este registro? (s/n): ";
		char respuesta;
		cin >> respuesta;
		cin.ignore();
		if (respuesta == 's' || respuesta == 'S') {
			usuarios.erase(it,usuarios.end());
			_usuarioArchivo.actualizar(usuarios);
			cout<<"Usuario eliminado exitosamente."<<endl;
		} else {
			return;
		}
	} else {
		cout << "Usuario no encontrado."<<endl;
	}
}

Usuario UsuarioManager::validarLogin(const string& mail, const string& clave, int permisos) {
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    for (const auto &usuario : usuarios) {
        if (usuario.getMail() == mail && usuario.getClave() == clave && usuario.getPermisos()==permisos) {
            return usuario;
        }
    }
    return Usuario();
}

void UsuarioManager::listarUsuariosPorPermisos(int permiso) {
    vector<Usuario> usuarios = _usuarioArchivo.leerPorPermisos(permiso);
    cout << "Usuarios disponibles con permisos seleccionados: "<<endl;
    for (const Usuario &usuario : usuarios) {
        mostrarUsuario(usuario);
    }
}






