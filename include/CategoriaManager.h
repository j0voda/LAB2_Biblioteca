#pragma once
#include <vector>
#include <iostream>

#include "CategoriaArchivo.h"

class CategoriaManager {
public:
   void menu();

private:
   void agregarCategoria();
   void listarCategorias();
   void mostrarCategoria();
   void eliminarCategoria();

   CategoriaArchivo _categoriaArhivo;
};

/// Crear
/// Listar
/// Eliminar
