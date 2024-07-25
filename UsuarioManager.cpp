#include "UsuarioManager.h"

//void listarUsuariosPorNombre();
//void listarUsuariosPorApellido(); ///desarrollar

void UsuarioManager::modificarUsuario() {
	system("cls");
	cout<<endl;
	cout << "MODIFICAR USUARIO" << endl;
	cout << "-----------------------------" << endl;

    int id;
    cout << "Ingrese el ID del usuario a modificar | ";
    cout << "Ingrese 0 si desea listar los usuarios existentes"<<endl;
    cin >> id;
    cin.ignore();

    while(id == 0){
		listarUsuarios();
		cout << "Ingrese el ID del usuario a modificar: ";
		cin >> id;
    }

    int pos = _usuarioArchivo.buscarById(id);
    if (pos<0) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

	system("cls");
    Usuario usuarioActual = _usuarioArchivo.leer(pos);
    mostrarUsuario(usuarioActual);
    cout << endl;

    cout<<"Desea modificar este usuario? S/N"<<endl;
    char respuesta;
    cin>>respuesta;
    while(respuesta != 'n' && respuesta != 'N' && respuesta != 's' && respuesta != 'S'){
		cout<<"Ingrese una respuesta valida: ";
		cin>>respuesta;
    }
    if(respuesta == 'n' || respuesta == 'N'){
		return;
    }

    char opcion;
    do {
		system("cls");
		cout << "-----------------------------" << endl;
		cout << "MODIFICAR USUARIO" << endl;
		cout << "-----------------------------" << endl;
    	cout << "1. Modificar Nombre" << endl;
        cout << "2. Modificar Apellido" << endl;
        cout << "3. Modificar Telefono" << endl;
        cout << "4. Modificar Mail" << endl;
        cout << "5. Modificar Clave" << endl;
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
                string nuevoTel;
                cout << "Ingrese el nuevo telefono: ";
                getline(cin, nuevoTel);
                while(validarTel(nuevoTel)<1){
					cout << "-- Reingrese el telefono: ";
					cout<<endl;
					getline(cin, nuevoTel);
				}
                usuarioActual.setTelefono(nuevoTel);
                break;
            }
            case '4': {
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
            case '5': {
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
            while(continuar != 'n' && continuar != 'N' && continuar != 's' && continuar != 'S'){
				cout<<"Ingrese una respuesta valida: ";
				cin>>continuar;
			}
            if (continuar == 'n' || continuar == 'N') {
                opcion = '0'; // Salir del bucle
            }
        }
    } while (opcion != '0');

	if (_usuarioArchivo.modificar(pos, usuarioActual)) {
		system("cls");
		mostrarUsuario(usuarioActual);
        cout << "Usuario modificado con exito." << endl;
        cout << endl;
    } else {
        cout << "Error al modificar el usuario." << endl;
		cout << endl;
    }
}

void UsuarioManager::mostrarUsuario(const Usuario &registro) {
	cout << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Telefono: " << registro.getTelefono() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout << "Clave: " << registro.getClave() << endl; //Solo va a mostrarse en el acceso del bibliotecario
    if(registro.getPermisos()==1){
		cout << "Permisos: Bibliotecario"<< endl;
    } else if(registro.getPermisos()==2){
		cout << "Permisos: Cliente"<< endl;
    }
    cout << "ID: " << registro.getId() << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
}

int UsuarioManager::validarTel(const string &tel){
	if (tel.length() != 10) {
        return 0;
    }
    for (char c : tel) {
        if (c < '0' || c > '9') {
            return 0;
        }
    }
	return 1;
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
    cout << "Ingrese el ID del usuario a eliminar | ";
    cout << "Ingrese 0 si desea listar los usuarios existentes"<<endl;
    cin >> id;
    cin.ignore();

    while(id == 0){
		listarUsuarios();
		cout << "Ingrese el ID del usuario a eliminar: ";
		cin >> id;
    }
    int pos = _usuarioArchivo.buscarById(id);

    if (pos < 0) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

	system("cls");
    Usuario usuario = _usuarioArchivo.leer(pos);

    mostrarUsuario(usuario);
    cout << "Esta seguro que desea eliminar este usuario? S/N"<< endl;
    char respuesta;
    cin>>respuesta;

    if(respuesta == 's'||respuesta == 'S'){
		vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
		auto it = remove_if(usuarios.begin(), usuarios.end(), [id](const Usuario &usuario){
							return usuario.getId()==id;
						});
		if (it != usuarios.end()) {
			usuarios.erase(it,usuarios.end());
			_usuarioArchivo.actualizar(usuarios);
			cout<<"Usuario eliminado exitosamente."<<endl;
		} else {
			cout << "Usuario no encontrado."<<endl;
		}
    } else{return;}
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
    for (const Usuario &usuario : usuarios) {
        mostrarUsuario(usuario);
    }
}

void UsuarioManager::listarUsuarios() {
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    sort(usuarios.begin(), usuarios.end(), [](const Usuario &a, const Usuario &b) {
        return a.getId() < b.getId();
    });
    for (const Usuario &usuario : usuarios) {
        mostrarUsuario(usuario);
    }
}

bool UsuarioManager::dobleValidacion(string clave){
	Usuario usuarioActual = _usuarioLogueado.leer();

	if(usuarioActual.getClave()==clave){
		return true;
	}
	return false;
}

Usuario UsuarioManager::clienteActivo(){
	Usuario usuario = _usuarioLogueado.leer();
	if(usuario.getId() > -1){
		return usuario;
	}
	return Usuario();
}





