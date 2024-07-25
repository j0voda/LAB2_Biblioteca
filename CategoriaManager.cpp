#include "CategoriaManager.h"
#include <algorithm>



void CategoriaManager::menu(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR CATEGORIAS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Agregar Categoria" << endl;
        cout << "2. Listar Categorias" << endl;
        cout << "3. Eliminar Categoria" << endl;
        cout << "-----------------------------" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
            	system("cls");
				cout << "-----------------------------" << endl;
				cout << "AGREGAR CATEGORIA" << endl;
				cout << "-----------------------------" << endl;
				agregarCategoria();
                system("pause");
                break;

            case 2:
                listarCategorias();
                system("pause");
                break;

            case 3:
                eliminarCategoria();
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


Categoria CategoriaManager::agregarCategoria(){
    string nombre;

    cout << "Ingrese el nombre de la nueva categoria: ";
    getline(cin, nombre);

    int id = _categoriaArchivo.getNuevoID();
    Categoria nuevaCategoria(id, nombre);

    if (_categoriaArchivo.guardar(nuevaCategoria)) {
		cout<<endl;
        cout << "Categoria agregada con exito con ID: " << id << endl;
        system("pause");
        cout<<endl;

    } else {
    	cout<<endl;
        cout << "Error al agregar la categoria." << endl;
        system("pause");
        cout<<endl;
    }

    return nuevaCategoria;
}

void CategoriaManager::listarCategorias() {

	system("cls");
    cout << "-----------------------------" << endl;
	cout << "CATEGORIAS" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

    vector<Categoria> categorias = _categoriaArchivo.leerTodos();
    sort(categorias.begin(), categorias.end(), [](const Categoria &a, const Categoria &b) {
        return a.getId() < b.getId();
    });
    for (const auto &categoria : categorias) {
        mostrarCategoria(categoria);
    }
}

void CategoriaManager::mostrarCategoria(const Categoria& categoria) {
	cout << "-----" << endl;
    cout << "ID: " << categoria.getId()<< " | Nombre: " << categoria.getNombre() << endl;
}

void CategoriaManager::eliminarCategoria() {
    int idCategoria;
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "ELIMINAR CATEGORIA" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
    cout << "Ingrese el ID de la categoria a eliminar: ";
    cin >> idCategoria;
    cin.ignore();

    int posCat = _categoriaArchivo.buscarById(idCategoria);

    if (posCat< 0) {
		cout << endl;
        cout << "Categoria no encontrado." << endl;
        return;
    }

	system("cls");
    Categoria categoria = _categoriaArchivo.leer(posCat);

    mostrarCategoria(categoria);
    cout << "Esta seguro que desea eliminar esta categoria? S/N"<< endl;
    char respuesta;
    cin>>respuesta;

    if(respuesta == 's'||respuesta == 'S'){
		vector<Categoria> categorias = _categoriaArchivo.leerTodos();

		auto it = remove_if(categorias.begin(), categorias.end(), [idCategoria](const Categoria &categoria) {
			return categoria.getId() == idCategoria;
		});

		cout << endl;

		if (it != categorias.end()) {
			categorias.erase(it, categorias.end());
			_categoriaArchivo.actualizar(categorias);
			cout << "Categoria eliminada exitosamente." << endl;
			cout << endl;
		} else {
			cout << "Categoria no encontrado." << endl;
			cout << endl;
		}
    }else{return;}
}
