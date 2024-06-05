#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

#include "Libro.h"
#include "LibroArchivo.h"
#include "CategoriaArchivo.h"
#include "AutorArchivo.h"

using namespace std;

class LibroManager {
public:
   void menu();

private:
   void agregarLibro();
   void modificarLibro();
   void listarLibros();
   void listarLibrosPorNombre();
   void listarLibrosPorCategoria();
   void listarLibrosPorAutor();
   void listarLibrosPorID();
   void eliminarLibro();
   Libro crearLibro();
   void mostrarLibro(const Libro &registro);


   LibroArchivo _libroArchivo;
   CategoriaArchivo _categoriaArchivo;
   AutorArchivo _autorArchivo;

   ///ver
};

/// Crear Libro
/// Listar libros por nombre
/// Mostrar libro
/// Modificar libro
/// Eliminar libro

