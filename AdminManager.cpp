#include "AdminManager.h"

AdminManager::AdminManager()
{
    //ctor
}

Admin AdminManager::crearAdmin() {
	string nombre, apellido, telefono, mail, clave;
	system("cls");

	cout << "-----------------------------------------------" << endl;
	cout << "----------------REGISTRO ADMIN-----------------" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << endl;

	cout << "Ingrese el nombre del nuevo usuario: ";
    getline(cin, nombre);
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    cout << "Ingrese mail: ";
    getline(cin, mail);
    while(validarTel(telefono)<1){
		cout << "-- Reingrese el telefono: ";
		cout<<endl;
		getline(cin, telefono);
    }
    while(validarMail(mail)<1){
		cout << "-- Reingrese el mail: ";
		cout<<endl;
		getline(cin, mail);
    }
    cout << "Ingrese la clave: ";
    getline(cin, clave);

    int id = _usuarioArchivo.getNuevoID();

    Admin admin(nombre, apellido, telefono, mail, id, clave, 3);

	if(!ingresarClaveMaestra()){
		return Admin(); //clave incorrecta
	}
	if (_usuarioArchivo.guardar(admin)) {
		cout << "Admin agregado con exito con ID "<<id << endl;
		return admin;
		cin.ignore();
	} else {
		cout << "Error al agregar el admin." << endl;
		return Admin();
		cin.ignore();
	}

}

bool AdminManager::ingresarClaveMaestra() {
    string claveMaestra;
    cout << "Ingrese la clave maestra para registrar un admin: ";
    getline(cin, claveMaestra);

    if (claveMaestra != "4321") {
        cout << "Clave maestra incorrecta. No se puede registrar como admin." << endl;
        cin.ignore();

        return false;
    }

    cout << "Clave maestra ingresada con exito.";
    cin.ignore();

    return true;
}

int AdminManager::validarTel(const string &tel){
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

int AdminManager::validarMail(const string &mail){
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
