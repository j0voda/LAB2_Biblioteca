#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "Categoria.h"
#include "CategoriaArchivo.h"

class CategoriaManager {
private:
	CategoriaArchivo _categoriaArchivo;

public:
   void menu();
   Categoria agregarCategoria();
   void listarCategorias();
   void mostrarCategoria(const Categoria& categoria);
   void eliminarCategoria();
};

