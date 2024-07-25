#include "BibliotecarioManager.h"

BibliotecarioManager::BibliotecarioManager(){
    //ctor
}

Bibliotecario BibliotecarioManager::crearBibliotecario() {
	string nombre, apellido, telefono, mail, clave;
	system("cls");

	cout << "-----------------------------" << endl;
	cout << "REGISTRO BIBLIOTECARIO" << endl;
	cout << "-----------------------------" << endl;

	cout << "Ingrese el nombre del nuevo usuario: ";
    getline(cin, nombre);
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    while(validarTel(telefono)<1){
		cout << "-- Reingrese el telefono: ";
		cout<<endl;
		getline(cin, telefono);
    }
    cout << "Ingrese mail: ";
    getline(cin, mail);
    while(validarMail(mail)<1){
		cout << "-- Reingrese el mail: ";
		cout<<endl;
		getline(cin, mail);
    }
    cout << "Ingrese la clave: ";
    getline(cin, clave);

    int id = _usuarioArchivo.getNuevoID();

    Bibliotecario bibliotecario(nombre, apellido, telefono, mail, id, clave, 1);

	if(!ingresarClaveMaestra()){
		return Bibliotecario(); //clave incorrecta
	}
	if (_usuarioArchivo.guardar(bibliotecario)) {
		cout << "Bibliotecario agregado con exito con ID "<<id << endl;
		return bibliotecario;
		cin.ignore();
	} else {
		cout << "Error al agregar el bibliotecario." << endl;
		return Bibliotecario();
		cin.ignore();
	}

}

bool BibliotecarioManager::ingresarClaveMaestra() {
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

int BibliotecarioManager::validarTel(const string &tel){
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

int BibliotecarioManager::validarMail(const string &mail){
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

void BibliotecarioManager::mostrarBibliotecario(const Usuario &registro) {
	cout<<endl;
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout<<endl;
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
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1);
    sort(bibliotecarios.begin(), bibliotecarios.end(), [](const Usuario &a, const Usuario &b) {
        string nombreA = a.getNombre();
        string nombreB = b.getNombre();
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
    vector<Usuario> bibliotecarios = _usuarioArchivo.leerPorPermisos(1);
    sort(bibliotecarios.begin(), bibliotecarios.end(), [](const Usuario &a, const Usuario &b) {
        string apA = a.getApellido();
        string apB = b.getApellido();
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

