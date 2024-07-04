#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "Libro.h"
#include "LibroArchivo.h"
#include "CategoriaManager.h"
#include "CategoriaArchivo.h"
#include "AutorManager.h"
#include "AutorArchivo.h"

class LibroManager {
public:
   void menu();
   void listarLibros();

private:
   Libro crearLibro();
   void modificarLibro();
   void mostrarLibro(const Libro &registro);

   void listarLibrosPorNombre();
   void listarLibrosPorCategoria();
   void listarLibrosPorAutor();
   void listarLibrosPorID();
   void eliminarLibro();


   LibroArchivo _libroArchivo;
   CategoriaManager _categoriaManager;
   CategoriaArchivo _categoriaArchivo;
   AutorManager _autorManager;
   AutorArchivo _autorArchivo;
};

