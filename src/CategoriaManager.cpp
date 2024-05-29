#include <iostream>
#include<cstdlib>
#include<cstring>
#include <vector>

using namespace std;

#include "CategoriaManager.h"


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
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
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
    cin.ignore();

    int id = _categoriaArchivo.getNuevoID();
    Categoria nuevaCategoria(id, nombre);

    if (_categoriaArchivo.guardar(nuevaCategoria)) {
        cout << "Categoria agregada con exito." << endl;
    } else {
        cout << "Error al agregar la categoria." << endl;
    }
}

void CategoriaManager::listarCategorias() {

    vector<Categorias> categorias = _categoriaArchivo.leerTodos();
    sort(categorias.begin(), categorias.end(), [](const Categoria &a, const Categoria &b) {
        return a.getIdCategoria() < b.getIdCategoria();
    });
    for (const auto &categoria : categorias) {
        mostrarCategoria(categoria);
    }
}

void CategoriaManager::mostrarCategoria(const Categoria& categoria) {
    cout << "ID: " << categoria.getId();
    cout << " | Nombre: " << categoria.getNombre() << endl;
}

void CategoriaManager::eliminarLibro() {
    int idCategoria;
    cout << "Ingrese el ID de la categoria a eliminar: ";
    cin >> idCategoria;
    cin.ignore(Categoria);

    vector<Categorias> categorias = _categoriaArchivo.leerTodos();
    auto it = remove_if(categorias.begin(), categorias.end(), [idCategoria](const Categoria &libro) {
        return categoria.getIdCategoria() == idCategoria;
    });

    if (it != categorias.end()) {
        categorias.erase(it, categorias.end());
        _categoriaArchivo.actualizar(categorias);
        cout << "Categoria eliminado exitosamente." << endl;
    } else {
        cout << "Categoria no encontrado." << endl;
    }
}
