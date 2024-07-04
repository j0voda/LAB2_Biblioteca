#include <string>

using namespace std;

#include "Interfaz.h"

void Interfaz::menuInicio() {
    int opcion;

    do {
        system("cls");
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
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
		cout << "INICIAR SESION" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "1. Iniciar Sesion como Bibliotecario" << endl;
		cout << "2. Iniciar Sesion como Cliente" << endl;
		cout << "-----------------------------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
		cin >> tipoUsuario;
		cin.ignore();

		switch(tipoUsuario)
        {
        	case 1:
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(1)> 0) {
					_bibliotecarioManager.listarBibliotecarios();
					cout << "Ingrese email: ";
					getline(cin, email);

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario bibliotecario = _usuarioManager.validarLogin(email, clave, 1);

					if (bibliotecario.getMail() != "") {
						cout << "Usuario validado"<<endl;
						menuBibliotecario();
					} else {
						cout<<endl;
						cout <<"Credenciales incorrectas."<<endl;
						cout <<"Ingrese 1 para intentar de nuevo | 0 para registrarse: ";
						int respuesta;
						cin >> respuesta;
						cin.ignore();
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
					_clienteManager.listarClientes();
					cout << "Ingrese email: ";
					getline(cin, email);

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario cliente = _usuarioManager.validarLogin(email, clave,2);
					if(cliente.getMail() != ""){
						cout << "Usuario validado"<<endl;
						menuCliente(cliente.getId());
					}else {
						cout <<"Credenciales incorrectas."<<endl;
						cout <<"Ingrese 1 para intentar de nuevo | 0 para registrarse: ";
						int respuesta;
						cin >> respuesta;
						cin.ignore();
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
        cout << "-----------------------------" << endl;
		cout << "REGISTRAR USUARIOS" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Registrar Bibliotecario" << endl;
		cout << "2. Registrar Cliente" << endl;
		cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
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
		cout << "-----------------------------" << endl;
        cout << "MENU BIBLIOTECARIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Administrar libros" << endl;
        cout << "2. Administrar autores" << endl;
        cout << "3. Administrar categorias" << endl;
        cout << "4. Administrar usuarios" << endl;
        cout << "5. Administrar membresias" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
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

        }
    } while (opcion != 0);
}

void Interfaz::menuAdministrarMembresias() {
        int opcion;
        do {
            cout << "-----------------------------" << endl;
            cout << "ADMINISTRAR MEMBRESIAS" << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Ver tipos de membresia" << endl;
            cout << "2. Agregar tipo de membresia" << endl;
            cout << "3. Eliminar tipo de membresia" << endl;
            cout << "-----------------------------" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1:
                    _membresiaManager.verTiposMembresia();
                    break;
                case 2:
                    _membresiaManager.agregarTipoMembresia();
                    break;
                case 3:
                    _membresiaManager.eliminarTipoMembresia();
                    break;
                case 0:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo." << endl;
            }
        } while (opcion != 0);
}


void Interfaz::menuCliente(int idCliente) {
    int opcion;
    do {
		system("cls");
		cout << "-----------------------------" << endl;
        cout << "MENU CLIENTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Ver todos los libros" << endl;
        cout << "2. Ver libros disponibles" << endl;
        cout << "3. Solicitar prestamo" << endl;
        cout << "4. Realizar devolucion" << endl;
        cout << "5. Ver historial de prestamos" << endl;
        cout << "6. Mi membresia" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                _libroManager.listarLibros();
                system("pause");
                break;
            case 2:
                //_prestamoManager.listarPrestamosPorIdCliente(cliente.getId());
                cout << "Aca devolvemos libros";//
                break;
            case 3:
                _prestamoManager.solicitarPrestamo();
                system("pause");
                break;
            case 4:
                cout << "Aca vemos los pagos";//pagoArchivo.mostrarPagos();
                break;
            case 5:
                cout << "Aca vemos los prestamos";// Función para ver el historial de préstamos
                break;
            case 6:
                menuMiMembresia(idCliente);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 0);
}

void Interfaz::menuMiMembresia(int idUsuario) {
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
                cout << "Ingrese nuevo tipo de membresia (1 para Basica, 2 para Premium): ";
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



