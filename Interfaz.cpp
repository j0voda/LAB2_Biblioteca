#include <string>

using namespace std;

#include "Interfaz.h"

void Interfaz::menuInicio() {
    int opcion;

    do {
        system("cls");
        cout << "-----------------------------------------------" << endl;
        cout << "------------------BIBLIOTECA-------------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|    1. Iniciar sesion                        |" << endl;
        cout << "|    2. Registrarse                           |" << endl;
        cout << "|    0. Salir                                 |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|   Seleccione una opcion:                    |" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                registrarse();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
				cin.ignore();
                return menuInicio();
        }
    } while (opcion != 0);
}

void Interfaz::iniciarSesion() {
    string email, clave;
    int tipoUsuario;
	do
    {
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "---------------INICIAR SESION------------------" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "| 1. Iniciar Sesion como Bibliotecario        |" << endl;
		cout << "| 2. Iniciar Sesion como Cliente              |" << endl;
		cout << "| 3. Iniciar Sesion como Admin                |" << endl;
        cout << "| 0. Salir                                    |" << endl;
		cout << "-----------------------------------------------" << endl;
        cout << "| Seleccione una opcion:                      |" << endl;
        cout << "-----------------------------------------------" << endl;
		cin >> tipoUsuario;
		cin.ignore();

		switch(tipoUsuario)
        {
        	case 1:
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(1)> 0) {
					//_bibliotecarioManager.listarBibliotecarios();
					cout << "Ingrese email: ";
					getline(cin, email);
					while(validarMail(email)<1){
                        cout << "-- Reingrese el mail: ";
                        cout<<endl;
                        getline(cin, email);
                    }

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario bibliotecario = _usuarioManager.validarLogin(email, clave, 1);

					if (bibliotecario.getMail() != "") {
						cout << "Usuario validado"<<endl;
						_usuarioLogueado.guardar(bibliotecario);
						menuBibliotecario();
					} else {
						cout<<endl;
						cout <<"Credenciales incorrectas."<<endl;
						cout <<"Ingrese 1 para intentar de nuevo | 0 para registrarse: ";
						int respuesta;
						cin >> respuesta;
						cin.ignore();
						bool valid = false;
						do
                        {
                            if(cin.good() && (respuesta == 0 || respuesta == 1)){
                                valid = true;
                            } else {
                                cout << "Ingrese un numero válido." << endl;
                                cin >> respuesta;
                                cin.ignore();
                            }

						}while(valid == false);
						if (respuesta == 0) {
							_bibliotecarioManager.crearBibliotecario();
							return iniciarSesion();
						} else if(respuesta == 1){
							return iniciarSesion();
						}
					}

				} else {
					cout << "Aun no hay bibliotecarios registrados. Desea registrarse? (s/n): ";
					char respuesta;
					cin >> respuesta;
					cin.ignore();
					if (respuesta == 's' || respuesta == 'S') {
						_bibliotecarioManager.crearBibliotecario();
						return iniciarSesion();
					} else {
						cout << "Volviendo al menu principal." << endl;
						return menuInicio();
					}
				}
                system("pause");
                break;

            case 2:
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(2) > 0) {
					//_clienteManager.listarClientes();
					cout << "Ingrese email: ";
					getline(cin, email);
					while(validarMail(email)<1){
                        cout << "-- Reingrese el mail: ";
                        cout<<endl;
                        getline(cin, email);
                    }

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario cliente = _usuarioManager.validarLogin(email, clave,2);
					if(cliente.getMail() != ""){
						cout << "Usuario validado"<<endl;
						_usuarioLogueado.guardar(cliente);
						menuCliente();
					}else {
						cout <<"Credenciales incorrectas."<<endl;
						cout <<"Ingrese 1 para intentar de nuevo | 0 para registrarse: ";
						int respuesta;
						cin >> respuesta;
						cin.ignore();
						bool valid = false;
						do
                        {
                            if(cin.good() && (respuesta == 0 || respuesta == 1)){
                                valid = true;
                            } else {
                                cout << "Ingrese un numero válido." << endl;
                                cin >> respuesta;
                                cin.ignore();
                            }

						}while(valid == false);

						if (respuesta == 0) {
							_clienteManager.crearCliente();
							return iniciarSesion();
						} else if(respuesta == 1){
							return iniciarSesion();
						}
					}
				} else {
					cout << "Aun no hay clientes registrados. Desea registrarse? (s/n): ";
					char respuesta;
					cin >> respuesta;
					cin.ignore();

					if (respuesta == 's' || respuesta == 'S') {
						_clienteManager.crearCliente();
						return iniciarSesion();
					} else {
						cout << "Volviendo al menu principal." << endl;
						return menuInicio();
					}
				}
                system("pause");
                break;

            case 3:
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(3) > 0) {
					cout << "Ingrese email: ";
					getline(cin, email);
                    while(validarMail(email)<1){
                        cout << "-- Reingrese el mail: ";
                        cout<<endl;
                        getline(cin, email);
                    }

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario admin = _usuarioManager.validarLogin(email, clave, 3);
					if(admin.getMail() != ""){
						cout << "Usuario validado"<<endl;
						_usuarioLogueado.guardar(admin);
						menuAdmin();
					}else {
						cout <<"Credenciales incorrectas."<<endl;
						cout <<"Ingrese 1 para intentar de nuevo | 0 para salir";
						int respuesta;
						cin >> respuesta;
						cin.ignore();
						bool valid = false;
						do
                        {
                            if(cin.good() && (respuesta == 0 || respuesta == 1)){
                                valid = true;
                            } else {
                                cout << "Ingrese un numero válido." << endl;
                                cin >> respuesta;
                                cin.ignore();
                            }

						}while(valid == false);

						if(respuesta == 1) {
                            return iniciarSesion();
						}

                        cout << "Volviendo al menu principal." << endl;
						return menuInicio();
					}
				} else {
					cout << "No hay usuarios admin. Presione una tecla para volver al menu. ";
                    cin.ignore();
                    cout << "Volviendo al menu principal." << endl;
                    return menuInicio();
				}
                system("pause");
                break;

			case 0:
				cout << "Saliendo..." << endl;
				return;

			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
				cin.ignore();
				return iniciarSesion();
		}
	} while (tipoUsuario != 0);
}

void Interfaz::registrarse(){

    int permiso,opcion;

    do {
		system("cls");
        cout << "-----------------------------------------------" << endl;
		cout << "--------------REGISTRAR USUARIOS---------------" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|  1. Registrar Bibliotecario                 |" << endl;
		cout << "|  2. Registrar Cliente                       |" << endl;
        cout << "|  0. Salir                                   |" << endl;
		cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> opcion;
        cin.ignore();

        permiso = opcion;

        switch (opcion) {
            case 1:
                _bibliotecarioManager.crearBibliotecario();
                return;
                break;
            case 2:
                _clienteManager.crearCliente();
                return;
                break;
            case 3:
                _adminManager.crearAdmin();
                return;
                break;
            case 0:
                cout << "Saliendo..." << endl;
                return;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                system("pause");
            }
    } while (opcion != 0);
}

void Interfaz::menuBibliotecario() {
    int opcion;
    do {
		system("cls");
		cout << "-----------------------------------------------" << endl;
        cout << "--------------MENU BIBLIOTECARIO---------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Administrar libros                      |" << endl;
        cout << "|  2. Administrar autores                     |" << endl;
        cout << "|  3. Administrar categorias                  |" << endl;
        cout << "|  4. Administrar clientes                    |" << endl;
        cout << "|  5. Administrar membresias                  |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
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
                menuAdministrarMembresias();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 0);
}

void Interfaz::menuAdmin() {
    int opcion;
    do {
		system("cls");
		cout << "-----------------------------------------------" << endl;
        cout << "------------------MENU ADMIN-------------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Administrar libros                      |" << endl;
        cout << "|  2. Administrar autores                     |" << endl;
        cout << "|  3. Administrar categorias                  |" << endl;
        cout << "|  4. Administrar usuarios                    |" << endl;
        cout << "|  5. Administrar membresias                  |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
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
                menuAdministrarUsuarios();
                break;
            case 5:
                menuAdministrarMembresias();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 0);
}

void Interfaz::menuAdministrarUsuarios(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------------------------" << endl;
        cout << "-------------ADMINISTRAR USUARIOS--------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Agregar Usuario                         |" << endl;
        cout << "|  2. Modificar Usuario                       |" << endl;
        cout << "|  3. Listar Clientes                         |" << endl;
        cout << "|  4. Listar Bibliotecarios                   |" << endl;
        cout << "|  5. Eliminar Usuario                        |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
            	registrarse();
                system("pause");
                break;

            case 2:
                _usuarioManager.modificarUsuario();
                system("pause");
                break;

            case 3:
                _usuarioManager.listarUsuariosPorPermisos(2);
                system("pause");
                break;

            case 4:
                _usuarioManager.listarUsuariosPorPermisos(1);
                system("pause");
                break;

            case 5:
                _usuarioManager.eliminarUsuario();
                system("pause");
                break;

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;

        }
    } while (opcion != 0);
}

void Interfaz::menuAdministrarClientes(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------------------------" << endl;
        cout << "--------------ADMINISTRAR CLIENTES-------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Agregar Cliente                         |" << endl;
        cout << "|  2. Modificar Cliente                       |" << endl;
        cout << "|  3. Listar Clientes                         |" << endl;
        cout << "|  4. Eliminar Cliente                        |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
            	registrarse();
                system("pause");
                break;

            case 2:
                _usuarioManager.modificarCliente();
                system("pause");
                break;

            case 3:
                _usuarioManager.listarUsuariosPorPermisos(2);
                system("pause");
                break;

            case 4:
                _usuarioManager.eliminarCliente();
                system("pause");
                break;

            case 0:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;

        }
    } while (opcion != 0);
}

void Interfaz::menuAdministrarMembresias() {
	int opcion;
	do {
		system("cls");

		cout << "-----------------------------------------------" << endl;
		cout << "---------ADMINISTRAR TIPOS DE MEMBRESIA--------" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|  1. Agregar Nuevo Tipo de Membresia         |" << endl;
		cout << "|  2. Modificar Tipo de Membresia             |" << endl;
		cout << "|  3. Listar Tipos de Membresias              |" << endl;
		cout << "|  4. Desactivar / Activar Tipo de Membresia  |" << endl;
		cout << "|  5. Eliminar Tipo de Membresia              |" << endl;
		cout << "|  0. Salir                                   |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|  Seleccione una opcion:                     |" << endl;
		cout << "-----------------------------------------------" << endl;
		cin >> opcion;
		cin.ignore();

		switch(opcion)
		{
			case 1:
				_tipoMembresiaManager.crearTipoMembresia();
				system("pause");
				break;

			case 2:
				_tipoMembresiaManager.modificarTipoMembresia();
				system("pause");
				break;

			case 3:
				_tipoMembresiaManager.listarTiposMembresia();
				system("pause");
				break;

			case 4:
				_tipoMembresiaManager.desactivarTipoMembresia();
				system("pause");
				break;

			case 5:
				_tipoMembresiaManager.eliminarTipoMembresia();
				system("pause");
				break;

			case 0:
				cout << "Saliendo del programa." << endl;
				break;

			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
				break;
		}
	} while (opcion != 0);
}

void Interfaz::menuCliente() {
    int opcion;
    do {
		system("cls");
		cout << "-----------------------------------------------" << endl;
        cout << "------------------MENU CLIENTE-----------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Ver todos los libros                    |" << endl;
        cout << "|  2. Ver libros disponibles                  |" << endl;
        cout << "|  3. Solicitar prestamo                      |" << endl;
        cout << "|  4. Realizar devolucion                     |" << endl;
        cout << "|  5. Mi membresia                            |" << endl;
        cout << "|  6. Ver historial de prestamos              |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout<<endl;
        //_usuarioLogueado.mostrarUsuarioLogueado();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                _libroManager.listarLibros();
                system("pause");
                break;
            case 2:
                _libroManager.listarLibrosDisponibles();
                system("pause");
                break;
            case 3:
                _prestamoManager.solicitarPrestamo();
                system("pause");
                break;
            case 4:
                _prestamoManager.realizarDevolucion();
                system("pause");
                break;
            case 5:
                menuMiMembresia();
                system("pause");
                break;
            case 6:
                _prestamoManager.listarPrestamosCliente();
                system("pause");
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
}

void Interfaz::menuMiMembresia() {
    int opcion;
    bool valid = false;
    do {
        system("cls");

        cout << "-----------------------------------------------" << endl;
        cout << "-----------ADMINISTRAR MI MEMBRESIA------------" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  1. Ver Estado de Membresía                 |" << endl;
        cout << "|  2. Realizar Pago                           |" << endl;
        cout << "|  3. Cambiar Tipo de Membresía               |" << endl;
        cout << "|  0. Salir                                   |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "|  Seleccione una opcion:                     |" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        if(cin.good()) {
          valid = true;
        }
        switch (opcion) {
            case 1:
                _membresiaManager.verEstadoMembresia();
                system("pause");
                break;
            case 2:
                _membresiaManager.realizarPago();
                system("pause");
                break;
            case 3:
                _membresiaManager.cambiarTipoMembresia();
                system("pause");
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción invalida." << endl;
                system("pause");
                break;
        }
    } while (valid == false);
}

int Interfaz::validarMail(const string &mail){
	regex pattern(R"(([^@]+)@([\w-]+\.(com|org|net|ar|com\.ar)))");
	if(!regex_match(mail,pattern)){
		cout << "Formato de correo invalido." <<endl;
        return -1;
	}

    return 1;
}


