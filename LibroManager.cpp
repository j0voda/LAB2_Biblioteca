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

    int idLibro, idAutor, idCategoria, anioPublicacion, ejemplares, disponibles;
    string titulo;
    bool estado;

    cout << "Ingrese Título del Libro: ";
    getline(cin, titulo);

    // Seleccionar y validar Autor
    cout << "Seleccione el Autor: ";
    cin >> idAutor;
    while (_autorArchivo.buscarById(idAutor) == -1) {
        cout << "-- Reingrese ID de Autor: ";
        cin >> idAutor;
    }
    cin.ignore();

    // Seleccionar y validar Categoria
    cout << "Seleccione la categoria: ";
    cin >> idCategoria;
    while (_categoriaArchivo.buscarById(idCategoria) == -1) {
        cout << "-- Reingrese ID de Categoria: ";
        cin >> idCategoria;
    }
    cin.ignore();
    /// ACA TENGO QUE LISTAR LAS CAT = Q EN AUTOR para q se vea el nro de id y el nomrbe

    cout << "Ingrese Año de Publicación: ";
    cin >> anioPublicacion;

    cout << "Ingrese Número de Ejemplares: ";
    cin >> ejemplares;

    cout << "Ingrese Número de Ejemplares Disponibles: "; ///ESTO DEBERIA CALCULARSE
    cin >> disponibles;

    cout << "Ingrese Estado (1 para disponible, 0 para no disponible): ";
    cin >> estado; /// EL ESTADO DEBERIA PONERSE AUTOMAT EN 0 CUANDO ESTEN TODOS RESERVADOS

    idLibro = _libroArchivo.getNuevoID();

    Autor autor = _autorArchivo.leer(_autorArchivo.buscarById(idAutor));
    Categoria categoria = _categoriaArchivo.leer(_categoriaArchivo.buscarById(idCategoria));

    Libro nuevoLibro(idLibro, titulo, autor, categoria, anioPublicacion, ejemplares, disponibles, estado);

    return nuevoLibro;
}

void LibroManager::agregarLibro() {
    Libro nuevoLibro = crearLibro();
    if (_libroArchivo.guardar(nuevoLibro)) {
        cout << "Libro agregado con exito." << endl;
    } else {
        cout << "Error al agregar el libro." << endl;
    }
}

void LibroManager::modificarLibro() {
    int idLibro;
    cout << "Ingrese el ID del libro a modificar: "; /// Aca deberia listar los libros para tener los id
    cin >> idLibro;
    cin.ignore();

    vector<Libro> libros = _libroArchivo.leerTodos();
    for (auto &libro : libros) {
        if (libro.getIdLibro() == idLibro) {
            libro = crearLibro();
            _libroArchivo.actualizar(libros);
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
    cout << "-----------------------------" << endl;
    cout << "Listar libros por: " << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Categoria" << endl;
    cout << "3. Autor" << endl;
    cout << "4. ID" << endl;
    cout << "-----------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "-----------------------------" << endl;
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
    vector<Libro> libros = _libroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getTitulo() < b.getTitulo();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorCategoria() {
    vector<Libro> libros = _libroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getIdCategoria().getNombre() < b.getIdCategoria().getNombre();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorAutor() {
    vector<Libro> libros = _libroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getIdAutor().getNombre() < b.getIdAutor().getNombre();
    });
    for (const auto &libro : libros) {
        mostrarLibro(libro);
    }
}

void LibroManager::listarLibrosPorID() {
    vector<Libro> libros = _libroArchivo.leerTodos();
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

    vector<Libro> libros = _libroArchivo.leerTodos();
    auto it = remove_if(libros.begin(), libros.end(), [idLibro](const Libro &libro) {
        return libro.getIdLibro() == idLibro;
    });

    if (it != libros.end()) {
        libros.erase(it, libros.end());
        _libroArchivo.actualizar(libros);
        cout << "Libro eliminado exitosamente." << endl;
    } else {
        cout << "Libro no encontrado." << endl;
    }
}

void LibroManager::listarLibrosAlquilados() {

}

