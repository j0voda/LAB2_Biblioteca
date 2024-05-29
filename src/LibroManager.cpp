#include <iostream>
#include<cstdlib>
#include<cstring>
#include <vector>

using namespace std;

#include "LibroManager.h"

/// Crear Libro -> Agregar Libro
/// Modificar libro
/// Listar libros -> Mostrar libro
/// Eliminar libro


void LibroManager::menu(){
    int opcion;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "ADMINISTRAR LIBROS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Agregar Libro" << endl;
        cout << "2. Modificar Libros" << endl;
        cout << "3. Listar Libro" << endl;
        cout << "4. Eliminar Libro" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para limpiar el buffer de entrada


        switch(opcion)
        {
            case 1:
                agregarLibro();
                system("pause");
                break;

            case 2:
                modificarLibro();
                system("pause");
                break;

            case 3:
                listarLibros();
                system("pause");
                break;

            case 4:
                eliminarLibro();
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


Libro LibroManager::crearLibro(){
    int idLibro, anioPublicacion, ejemplares, disponibles;
    string titulo, nombreAutor, nombreCategoria;
    bool estado;

    cout << "Ingrese ID del Libro: ";
    cin >> idLibro;
    cin.ignore();

    cout << "Ingrese Título del Libro: ";
    getline(cin, titulo);

    ///cout << "Seleccione el Autor: ";

    cout << "Seleccione la categoria: ";
    cin >> idcategoria;

    while (_categoriaArchivo.buscarByID(idcategoria) == -1){
      cout << "-- Reingrese ID de Categoria: ";
      cin >> idcategoria;
    } /// ACA TENGO QUE LISTAR LAS CAT Y VER QUE EL NRO INGRESADO COINCIDA CON EL ID = Q EN AUTOR

    cout << "Ingrese Año de Publicación: ";
    cin >> anioPublicacion;

    cout << "Ingrese Número de Ejemplares: ";
    cin >> ejemplares;

    ///cout << "Ingrese Número de Ejemplares Disponibles: "; ESTO DEBERIA CALCULARSE
    ///cin >> disponibles;

    cout << "Ingrese Estado (1 para disponible, 0 para no disponible): ";
    cin >> estado; /// EL ESTADO DEBERIA PONERSE AUTOMAT EN 0 CUANDO ESTEN TODOS RESERVADOS

    return Libro(id, nombre, precio, idcategoria, 10, 5, 1, Fecha(4,4,2029), false);
}

void LibroManager::agregarLibro() {
    Libro nuevoLibro = crearLibro();
    _LibroArchivo.guardar(nuevoLibro);
    cout << "Libro agregado exitosamente." << endl;
}

void LibroManager::modificarLibro() {
    int idLibro;
    cout << "Ingrese el ID del libro a modificar: "; /// Aca deberia listar los libros para tener los id
    cin >> idLibro;kinbhj    cin.ignore();

    vector<Libro> libros = _LibroArchivo.leerTodos();
    for (auto &libro : libros) {
        if (libro.getIdLibro() == idLibro) {
            libro = crearLibro();
            _LibroArchivo.actualizar(libros);
            cout << "Libro modificado exitosamente." << endl;
            return;
        }
    }
    cout << "Libro no encontrado." << endl;
}

void LibroManager::mostrarLibro(const Libro &registro) {
    cout << "ID Libro: " << registro.getIdLibro() << endl;
    cout << "Título: " << registro.getTitulo() << endl;
    cout << "Autor: " << registro.getIdAutor().getNombre() << endl; //config
    cout << "Categoría: " << registro.getIdCategoria().getNombre() << endl;  //config
    cout << "Año de Publicación: " << registro.getAnioPublicacion() << endl;
    cout << "Ejemplares: " << registro.getEjemplares() << endl;
    cout << "Disponibles: " << registro.getDisponibles() << endl;
    cout << "Estado: " << (registro.getEstado() ? "Disponible" : "No Disponible") << endl;
}

void LibroManager::listarLibros() {
    int opcion;
    cout << "Listar libros por: " << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Categoria" << endl;
    cout << "3. Autor" << endl;
    cout << "4. ID" << endl;
    cout << "-----------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1:
            listarLibrosPorNombre();
            break;
        case 2:
            listarLibrosPorCategoria();
            break;
        case 3:
            listarLibrosPorAutor();
            break;
        case 4:
            listarLibrosPorID();
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
    }
}

void LibroManager::listarLibrosPorNombre() {
    vector<Libro> libros = _LibroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getTitulo() < b.getTitulo();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorCategoria() {
    vector<Libro> libros = _LibroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getIdCategoria().getNombre() < b.getIdCategoria().getNombre();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorAutor() {
    vector<Libro> libros = _LibroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getIdAutor().getNombre() < b.getIdAutor().getNombre();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorID() {
    vector<Libro> libros = _LibroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getIdLibro() < b.getIdLibro();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::eliminarLibro() {
    int idLibro;
    cout << "Ingrese el ID del libro a eliminar: ";
    cin >> idLibro;
    cin.ignore();

    vector<Libro> libros = _LibroArchivo.leerTodos();
    auto it = remove_if(libros.begin(), libros.end(), [idLibro](const Libro &libro) {
        return libro.getIdLibro() == idLibro;
    });

    if (it != libros.end()) {
        libros.erase(it, libros.end());
        _LibroArchivo.actualizar(libros);
        cout << "Libro eliminado exitosamente." << endl;
    } else {
        cout << "Libro no encontrado." << endl;
    }
}

