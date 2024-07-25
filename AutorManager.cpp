#include "AutorManager.h"

#include <algorithm>


void AutorManager::menu(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR AUTORES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Agregar Autor" << endl;
        cout << "2. Listar Autores" << endl;
        cout << "3. Eliminar Autor" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
            case 1:
            	system("cls");
				cout << "-----------------------------" << endl;
				cout << "AGREGAR AUTOR" << endl;
				cout << "-----------------------------" << endl;
                agregarAutor();
                system("pause");
                break;

            case 2:
                listarAutores();
                system("pause");
                break;

            case 3:
                eliminarAutor();
                system("pause");
                break;

            case 0:
                cout << "Saliendo." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);
}

Autor AutorManager::agregarAutor(){
    string nombre, apellido, nacionalidad, sellers;

    cout << "Ingrese el nombre del nuevo autor: ";
    getline(cin, nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, apellido);

    cout << "Ingrese la nacionalidad: ";
    getline(cin, nacionalidad);

    cout << "Ingrese su BestSeller: ";
    getline(cin, sellers);

    int id = _autorArchivo.getNuevoID();
    Autor nuevoAutor(nombre, apellido, id, nacionalidad, sellers);

    if (_autorArchivo.guardar(nuevoAutor)) {
		cout<<endl;
        cout << "Autor agregado con exito con ID: " << id<< endl;
        system("pause");
        cout<<endl;
    } else {
		cout<<endl;
        cout << "Error al agregar el autor." << endl;
        system("pause");
        cout<<endl;
    }
    return nuevoAutor;
}

void AutorManager::listarAutores() {
	system("cls");
	cout << "-----------------------------" << endl;
	cout << "LISTAR AUTORES" << endl;
	cout << "-----------------------------" << endl;
	cout<< endl;
    vector<Autor> autores = _autorArchivo.leerTodos();
    sort(autores.begin(), autores.end(), [](const Autor& a, const Autor& b) {
        return a.getId() < b.getId();
    });
    for (const auto& autor : autores) {
        mostrarAutor(autor);
    }
}

void AutorManager::mostrarAutor(const Autor& autor) {
	cout<<endl;
    cout << "ID: " << autor.getId() << endl;
    cout << "Nombre: " << autor.getNombre() << " " << autor.getApellido() << endl;
    cout << "Nacionalidad: " << autor.getNacionalidad() << endl;
    cout << "Best Seller: " << autor.getBestSellers() << endl;
    cout<<endl;
    cout << "-----------------------------" << endl;
}

void AutorManager::mostrarResumenAutor() {
    vector<Autor> autores = _autorArchivo.leerTodos();
    sort(autores.begin(), autores.end(), [](const Autor& a, const Autor& b) {
        return a.getId() < b.getId();
    });
    for (const auto&autor : autores) {
		cout << "-----" << endl;
        cout << "ID: " << autor.getId() << " | "<< "Nombre: " << autor.getNombre() << " " << autor.getApellido() << endl;
    }
}

void AutorManager::eliminarAutor() {
    int idAutor;
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "ELIMINAR AUTOR" << endl;
	cout << "-----------------------------" << endl;
    cout << "Ingrese el ID del autor a eliminar | Ingrese 0 si desea listar los autores existentes"<<endl;
    cin >> idAutor;
    cin.ignore();

    while(idAutor == 0){
		listarAutores();
		cout<< endl;
		cout << "Ingrese el ID del autor a eliminar: ";
		cin >> idAutor;
    }
    int posAutor = _autorArchivo.buscarById(idAutor);

    if (posAutor < 0) {
        cout << "Autor no encontrado." << endl;
        return;
    }

    system("cls");
    Autor autor = _autorArchivo.leer(posAutor);

    mostrarAutor(autor);
    cout << "Esta seguro que desea eliminar este autor? S/N"<< endl;
    char respuesta;
    cin>>respuesta;

    if(respuesta == 's'||respuesta == 'S'){

		vector<Autor> autores = _autorArchivo.leerTodos();
		auto it = remove_if(autores.begin(), autores.end(), [idAutor](const Autor &autor) {
			return autor.getId() == idAutor;
		});

		if (it != autores.end()) {
			autores.erase(it, autores.end());
			_autorArchivo.actualizar(autores);
			cout << "Autor eliminado exitosamente." << endl;
		} else {
			cout << "Autor no encontrado." << endl;
		}
    } else{return;}
}
