#include <iostream>
#include<cstdlib>
#include<cstring>
#include <vector>

using namespace std;

#include "AutorManager.h"


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
    string nombreAutor;

    cout << "Ingrese el nombre del nuevo autor: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el apellido: ";
    cin.ignore();
    getline(cin, apellido);

    cout << "Ingrese la nacionalidad: ";
    cin.ignore();
    getline(cin, nacionalidad);

    cout << "Ingrese su BestSeller: ";
    cin.ignore();
    getline(cin, sellers);

    int id = _autorArchivo.getNuevoID();
    Autor nuevoAutor(nombre, apellido, id, nacionalidad, sellers);

    if (_autorArchivo.guardar(nuevoAutor)) {
        cout << "Autor agregada con exito." << endl;
    } else {
        cout << "Error al agregar la categoria." << endl;
    }
}

void AutorManager::listarAutores() {

    vector<Autores> autores = _autorArchivo.leerTodos();
    sort(autores.begin(), autores.end(), [](const Autor &a, const Autor &b) {
        return a.getIdAutor() < b.getIdAutor();
    });
    for (const auto &autor : autores) {
        listarAutores(autor);
    }
}

void AutorManager::eliminarLibro() {
    int idAutor;
    cout << "Ingrese el ID del autor a eliminar: ";
    cin >> idAutor;
    cin.ignore(Autor);

    vector<Autores> autores = _autorArchivo.leerTodos();
    auto it = remove_if(autores.begin(), autores.end(), [idAutor](const Autor &autores) {
        return autor.getIdCategoria() == idAutor;
    });

    if (it != autores.end()) {
        autores.erase(it, autores.end());
        _autorArchivo.actualizar(autores);
        cout << "Autor eliminado exitosamente." << endl;
    } else {
        cout << "Autor no encontrado." << endl;
    }
}
