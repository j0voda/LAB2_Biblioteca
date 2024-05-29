#pragma once
#include <vector>
#include <iostream>

#include "Libro.h"
#include "LibroArchivo.h"
#include "CategoriaArchivo.h"

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


   LibroArchivo _LibrosArchivo;
   CategoriaArchivo _categoriaArchivo;
   ///ver
};

/// Crear Libro
/// Listar libros por nombre
/// Mostrar libro
/// Modificar libro
/// Eliminar libro

