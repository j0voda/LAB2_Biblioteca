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
        		system("cls");
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(1)> 0) {
					cout<<endl;
					cout<<"INICIAR SESION COMO BIBLIOTECARIO"<<endl;
					cout << "-----------------------------------------------" << endl;
					cout<<"**PRUEBA: Mail 1 - Clave 1**"<<endl;
					cout << "-----------------------------------------------" << endl;
					cout<<endl;
					//_bibliotecarioManager.listarBibliotecarios();
					cout << "Ingrese email: ";
					getline(cin, email);

					cout << "Ingrese clave: ";
					getline(cin, clave);

					Usuario bibliotecario = _usuarioManager.validarLogin(email, clave, 1);

					if (bibliotecario.getMail() != "") {
						cout<<endl;
						cout << "Usuario validado"<<endl;
						_usuarioLogueado.guardar(bibliotecario);
						menuBibliotecario();
					} else {
						cout<<endl;
						cout <<"Credenciales incorrectas."<<endl;
						cout<<endl;
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
            	system("cls");
                if (_usuarioArchivo.getCantidadRegistrosPorPermiso(2) > 0) {
					cout<<endl;
					cout<<"INICIAR SESION COMO CLIENTE"<<endl;
					cout << "-----------------------------------------------" << endl;
					cout<<"**PRUEBA: Mail 1 - Clave 1**"<<endl;
					cout << "-----------------------------------------------" << endl;
					cout<<endl;
					//_clienteManager.listarClientes();
					cout << "Ingrese email: ";
					getline(cin, email);

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
		cout<<endl;
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
		cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
            	system("cls");
            	registrarse();
                system("pause");
                break;

            case 2:
            	system("cls");
                _usuarioManager.modificarUsuario();
                system("pause");
                break;

            case 3:
            	system("cls");
                _usuarioManager.listarUsuariosPorPermisos(2);
                system("pause");
                break;

            case 4:
            	system("cls");
                _usuarioManager.listarUsuariosPorPermisos(1);
                system("pause");
                break;

            case 5:
            	system("cls");
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

void Interfaz::menuAdministrarMembresias() {
	int opcion;
	do {
		system("cls");

		cout << "------------------------------------------" << endl;
		cout << "ADMINISTRAR TIPOS DE MEMBRESIAS" << endl;
		cout << "------------------------------------------" << endl;
		cout << "1. Agregar Nuevo Tipo de Membresia" << endl;
		cout << "2. Modificar Tipo de Membresia" << endl;
		cout << "3. Listar Tipos de Membresias" << endl;
		cout << "4. Desactivar / Activar Tipo de Membresia" << endl;
		cout << "5. Eliminar Tipo de Membresia" << endl;
		cout << "------------------------------------------" << endl;
		cout << "0. Salir" << endl;
		cout<<endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		cin.ignore();

		switch(opcion)
		{
			case 1:
				system("cls");
				_tipoMembresiaManager.crearTipoMembresia();
				system("pause");
				break;

			case 2:
				system("cls");
				_tipoMembresiaManager.modificarTipoMembresia();
				system("pause");
				break;

			case 3:
				system("cls");
				_tipoMembresiaManager.listarTiposMembresia();
				system("pause");
				break;

			case 4:
				system("cls");
				_tipoMembresiaManager.desactivarTipoMembresia();
				system("pause");
				break;

			case 5:
				system("cls");
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
		cout << "-----------------------------" << endl;
        cout << "MENU CLIENTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Ver todos los libros" << endl;
        cout << "2. Ver libros disponibles" << endl;
        cout << "3. Solicitar prestamo" << endl;
        cout << "4. Realizar devolucion" << endl;
        cout << "5. Mi membresia" << endl;
        cout << "6. Ver historial de prestamos" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
        _usuarioLogueado.mostrarUsuarioLogueado();
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
            	system("cls");
                _libroManager.listarLibros();
                system("pause");
                break;
            case 2:
            	system("cls");
                _libroManager.listarLibrosDisponibles();
                system("pause");
                break;
            case 3:
            	system("cls");
                _prestamoManager.solicitarPrestamo();
                system("pause");
                break;
            case 4:
            	system("cls");
                _prestamoManager.realizarDevolucion();
                system("pause");
                break;
            case 5:
            	system("cls");
                menuMiMembresia();
                system("pause");
                break;
            case 6:
            	system("cls");
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
    do {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR MI MEMBRESIA" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Ver Estado de Membresia" << endl;
        cout << "2. Realizar Pago" << endl;
        cout << "3. Cambiar Tipo de Membresia" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
            	system("cls");
                _membresiaManager.verEstadoMembresia();
                system("pause");
                break;
            case 2:
            	system("cls");
                _membresiaManager.realizarPago();
                system("pause");
                break;
            case 3:
            	system("cls");
                _membresiaManager.cambiarTipoMembresia();
                system("pause");
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);
}


