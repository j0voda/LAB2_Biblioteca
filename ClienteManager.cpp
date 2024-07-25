#include "ClienteManager.h"

ClienteManager::ClienteManager(){
    //ctor
}

Cliente ClienteManager::crearCliente(){
	string nombre, apellido, telefono, mail, clave;
	Membresia membresia;
    system("cls");

    cout << "-----------------------------" << endl;
	cout << "REGISTRO CLIENTE" << endl;
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

    system("cls");

    membresia = _membresiaManager.asignarMembresia();

	if(membresia.getId() < 1){
		cout << "Error al agregar el cliente." << endl;
		cin.ignore();
		return Cliente();
	}

    Cliente cliente = Cliente(nombre, apellido, telefono, mail, id, clave, 2, membresia);

	if (_usuarioArchivo.guardar(cliente)) {
		cout << "Cliente agregado con exito con ID "<<id << endl;
		cin.ignore();
		return cliente;
	} else {
		cout << "Error al agregar el cliente." << endl;
		cin.ignore();
		return Cliente();
	}
}

int ClienteManager::validarTel(const string &tel){
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

int ClienteManager::validarMail(const string &mail){
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

void ClienteManager::asignarMembresia(){
    int tipoMembresia;
    cout << "Ingrese su membresía (1 para Básica, 2 para Premium): ";
    cin >> tipoMembresia;

    /*
    if (tipoMembresia < 1 || tipoMembresia > 2){
        cout << "Membresia incorrecta. No se puede registrar como cliente." << endl;
        return;
    }

    Fecha fechaInicio = Fecha::obtenerFechaActual();
    Fecha fechaFin = fechaInicio.sumarMes(1);

    Membresia membresia(_membresiaManager.getNuevoID(), _cliente.getId(), tipoMembresia, fechaInicio, fechaFin, true);
    _membresiaManager.guardarMembresia(membresia);
    */

    cout << "Membresía asignada con éxito. Cliente registrado" << endl;

}

void ClienteManager::mostrarCliente(const Usuario &registro) {
	cout<<endl;
    cout << "ID: " << registro.getId() << endl;
    cout << "Nombre: " << registro.getNombre() << endl;
    cout << "Apellido: " << registro.getApellido() << endl;
    cout << "Email: " << registro.getMail() << endl;
    cout<<endl;
    cout << "-----" << endl;
}

void ClienteManager::listarClientes() {
	cout << "-----------------------------" << endl;
	cout << "CLIENTES" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	Cliente cl;
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        return a.getId() < b.getId();
    });
    cout << "Clientes disponibles: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, cl.getMembresia());
        this->mostrarCliente(c);
    }
}

void ClienteManager::listarClientesPorNombre() {
	Cliente cl;
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        string nombreA = a.getNombre();
        string nombreB = b.getNombre();
        transform(nombreA.begin(),nombreA.end(),nombreA.begin(),::tolower);
        transform(nombreB.begin(),nombreB.end(),nombreB.begin(),::tolower);
        return  nombreA < nombreB;
    });
    cout << "Clientes disponibles por nombre: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, cl.getMembresia());
        this->mostrarCliente(c);
    }
}

void ClienteManager::listarClientesPorApellido() {
	Cliente cl;
    vector<Usuario> clientes = _usuarioArchivo.leerPorPermisos(2); // 2 permisos de cliente
    sort(clientes.begin(), clientes.end(), [](const Usuario &a, const Usuario &b) {
        string apA = a.getApellido();
        string apB = b.getApellido();
        transform(apA.begin(),apA.end(),apA.begin(),::tolower);
        transform(apB.begin(),apB.end(),apB.begin(),::tolower);
        return  apA < apB;
	});
    cout << "Clientes disponibles por apellido: "<<endl;
    for (const Usuario &cliente : clientes) {
        Cliente c = Cliente(cliente.getNombre(), cliente.getApellido(), cliente.getTelefono(), cliente.getMail(), cliente.getId(), cliente.getClave(), 2, cl.getMembresia());
        this->mostrarCliente(c);
    }
}

void ClienteManager::verLibros() {
    _libroManager.listarLibros();
}



/*Cliente ClienteManager::validarLoginCliente(const string& mail, const string& clave, int permisos) {
    cout << "Validando usuario";
    vector<Usuario> usuarios = _usuarioArchivo.leerTodos();
    for (const auto &usuario : usuarios) {
        cout << usuario.getMail();
        if (usuario.getMail() == mail && usuario.getClave() == clave) {
            Cliente uc = Cliente(usuario.getNombre(), usuario.getApellido(), usuario.getTelefono(), usuario.getMail(), usuario.getId(), usuario.getClave(), permisos, false);
            return uc;
        }
    }
    return Cliente(); // Retornar un usuario vacío si no se encuentra
}
*/
