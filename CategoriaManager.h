#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

#include "Categoria.h"
#include "CategoriaArchivo.h"

using namespace std;

class CategoriaManager {
public:
   void menu();

private:
   Categoria agregarCategoria();
   void listarCategorias();
   void mostrarCategoria(const Categoria& categoria);
   void eliminarCategoria();

   CategoriaArchivo _categoriaArchivo;
};

/// Crear
/// Listar
/// Eliminar
