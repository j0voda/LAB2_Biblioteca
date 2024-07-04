#include "LibroManager.h"

void LibroManager::menu(){
    int opcion;
    do {
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
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();


        switch(opcion)
        {
            case 1:
                crearLibro();
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
				break;
        }
    } while (opcion != 0);
}


Libro LibroManager::crearLibro(){

    int idLibro, idAutor, idCategoria, anioPublicacion, ejemplares, disponibles;
    string titulo;
    bool estado;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "AGREGAR LIBRO" << endl;
	cout << "-----------------------------" << endl;

    cout << "Ingrese el titulo del Libro: ";
    getline(cin, titulo);
    cout<<endl;

    cout << "Seleccione el Autor o presione 0 para crear uno nuevo: "<<endl;
    _autorManager.mostrarResumenAutor();
    cout<<endl;
    cin >> idAutor;
	cin.ignore();
	while (_autorArchivo.buscarById(idAutor) == -1 && idAutor!=0) {
		cout << "-- Reingrese ID de Autor: ";
		cout<<endl;
		cin >> idAutor;
		cin.ignore();
	}
	Autor autor;
	if (idAutor==0){
		autor =  _autorManager.agregarAutor();
		idAutor = autor.getId();
    }else {
        autor = _autorArchivo.leer(_autorArchivo.buscarById(idAutor));
    }

    cout<<endl;
    cout << "Seleccione la categoria o presione 0 para crear una nueva: ";
    cout<<endl;
    _categoriaManager.listarCategorias();
    cout<<endl;
    cin >> idCategoria;
	cin.ignore();
    while (_categoriaArchivo.buscarById(idCategoria) == -1 && idCategoria!= 0) {
        cout << "-- Reingrese ID de categoria: ";
        cout<<endl;
        cin >> idCategoria;
		cin.ignore();
    }
	Categoria categoria;
    if (idCategoria == 0){
		categoria =  _categoriaManager.agregarCategoria();
		idCategoria = categoria.getId();
    }else {
        categoria = _categoriaArchivo.leer(_categoriaArchivo.buscarById(idCategoria));
    }
    cout<<endl;
    cout << "Ingrese el anio de publicacion: ";
    cin >> anioPublicacion;
    cin.ignore();
    cout << "Ingrese el numero de ejemplares: ";
    cin >> ejemplares;
    cin.ignore();
    disponibles=ejemplares;

    estado = true; /// EL ESTADO DEBERIA PONERSE AUTOMAT EN 0 CUANDO ESTEN TODOS RESERVADOS
    idLibro = _libroArchivo.getNuevoID();

    Libro nuevoLibro(idLibro, titulo, autor, categoria, anioPublicacion, ejemplares, disponibles, estado);

    if (_libroArchivo.guardar(nuevoLibro)) {
        cout << endl;
        cout << "Libro agregado con exito." << endl;
        return nuevoLibro;
    } else {
        cout << endl;
        cout << "Error al agregar el libro." << endl;
        return Libro();
    }
}

void LibroManager::modificarLibro() {
	system("cls");
	cout<<endl;
	cout << "MODIFICAR LIBRO" << endl;
	cout << "-----------------------------" << endl;

    int idLibro;
    cout << "Ingrese el ID del libro a modificar: ";
    cin >> idLibro;
    cin.ignore();

    int pos = _libroArchivo.buscarById(idLibro);
    if (pos < 0) {
        cout << "Libro no encontrado." << endl;
        return;
    }

    Libro libroActual = _libroArchivo.leer(pos);
    mostrarLibro(libroActual);
    cout << endl;

    char opcion;
    do {
        cout << "1. Modificar Titulo" << endl;
        cout << "2. Modificar Autor" << endl;
        cout << "3. Modificar Categoria" << endl;
        cout << "4. Modificar Anio de Publicacion" << endl;
        cout << "5. Modificar Numero de Ejemplares" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. Finalizar Modificaciones" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
		switch (opcion) {
            case '1': {
                string nuevoTitulo;
                cout << "Ingrese el nuevo titulo: ";
                getline(cin, nuevoTitulo);
                libroActual.setTitulo(nuevoTitulo);
                break;
            }
            case '2': {
                int nuevoIdAutor;
                cout << "Seleccione el nuevo Autor o presione 0 para crear uno nuevo: ";
                cout << endl;
                _autorManager.mostrarResumenAutor();
                cin >> nuevoIdAutor;
                cin.ignore();
                while (_autorArchivo.buscarById(nuevoIdAutor) == -1 && nuevoIdAutor != 0) {
                    cout << "-- Reingrese ID de Autor: ";
                    cin >> nuevoIdAutor;
                    cin.ignore();
                }
                Autor nuevoAutor;
                if (nuevoIdAutor == 0) {
                    nuevoAutor = _autorManager.agregarAutor();
                    nuevoIdAutor = nuevoAutor.getId();
                    cout << "Nuevo autor creado con ID: " << nuevoIdAutor << endl;
                }
                libroActual.setAutor(nuevoAutor);
                break;
            }
            case '3': {
                int nuevoIdCategoria;
                cout << "Seleccione la nueva categoria o presione 0 para crear una nueva: ";
                cout << endl;
                _categoriaManager.listarCategorias();
                cin >> nuevoIdCategoria;
                cin.ignore();
                while (_categoriaArchivo.buscarById(nuevoIdCategoria) == -1 && nuevoIdCategoria != 0) {
                    cout << "-- Reingrese ID de categoria: ";
                    cin >> nuevoIdCategoria;
                    cin.ignore();
                }
                Categoria nuevaCategoria;
                if (nuevoIdCategoria == 0) {
                    nuevaCategoria = _categoriaManager.agregarCategoria();
                    nuevoIdCategoria = nuevaCategoria.getId();
                    cout << "Nueva categoria creada con ID: " << nuevoIdCategoria << endl;
                }
                libroActual.setCategoria(nuevaCategoria);
                break;
            }
            case '4': {
                int nuevoAnioPublicacion;
                cout << "Ingrese el nuevo anio de publicacion: ";
                cin >> nuevoAnioPublicacion;
                cin.ignore();
                libroActual.setAnioPublicacion(nuevoAnioPublicacion);
                break;
            }
            case '5': {
                int nuevosEjemplares;
                cout << "Ingrese el nuevo numero de ejemplares: ";
                cin >> nuevosEjemplares;
                cin.ignore();
                int diferencia = nuevosEjemplares - libroActual.getEjemplares();
                libroActual.setEjemplares(nuevosEjemplares);
                libroActual.setDisponibles(libroActual.getDisponibles() + diferencia);
                break;
            }
            case '0':
                cout << "Finalizando modificaciones." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
        if (opcion != '0') {
            cout << endl << "Desea modificar otro dato? (s/n): ";
            char continuar;
            cin >> continuar;
            cin.ignore();
            if (continuar == 'n' || continuar == 'N') {
                opcion = '0'; // Salir del bucle
            }
        }
    } while (opcion != '0');

    if (_libroArchivo.modificar(pos, libroActual)) {
        cout << "Libro modificado exitosamente." << endl;
    } else {
        cout << "Error al modificar el libro." << endl;
    }
}

void LibroManager::mostrarLibro(const Libro &registro) {
	cout<<endl;
    cout << "ID Libro: " << registro.getIdLibro() << endl;
    cout << "Titulo: " << registro.getTitulo() << endl;
    cout << "Autor: " << registro.getAutor().getNombre()<< endl;
    cout << "Categoria: " << registro.getCategoria().getNombre() << endl;
    cout << "Anio de Publicacion: " << registro.getAnioPublicacion() << endl;
    cout << "Ejemplares: " << registro.getEjemplares() << endl;
    cout << "Disponibles: " << registro.getDisponibles() << endl;
    cout << "Estado: " << (registro.getEstado() ? "Disponible" : "No Disponible") << endl;
	cout<<endl;
    cout << "-----------------------------" << endl;
}

void LibroManager::listarLibros() {
	system("cls");
    int opcion;
    cout << "Listar libros por: " << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Categoria" << endl;
    cout << "3. Autor" << endl;
    cout << "4. ID" << endl;
    cout << "-----------------------------" << endl;
    cout << "0. Salir" << endl;
    cout<<endl;
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
    for (const auto &registro : libros) {
        mostrarLibro(registro);
    }
}

void LibroManager::listarLibrosPorCategoria() {
    vector<Libro> libros = _libroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getCategoria().getNombre() < b.getCategoria().getNombre();
    });
    for (const auto &registro : libros) {
        mostrarLibro(registro);
    }
}

void LibroManager::listarLibrosPorAutor() {
    vector<Libro> libros = _libroArchivo.leerTodos();
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.getAutor().getNombre() < b.getAutor().getNombre();
    });
    for (const auto &registro : libros) {
        mostrarLibro(registro);
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
    system("cls");
    cout << "-----------------------------" << endl;
	cout << "ELIMINAR LIBRO" << endl;
	cout << "-----------------------------" << endl;
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

