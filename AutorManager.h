#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

#include "Autor.h"
#include "AutorArchivo.h"

using namespace std;

class AutorManager {
public:
   void menu();

private:
   Autor agregarAutor();
   void listarAutores();
   void mostrarAutor(const Autor& autor);
   void eliminarAutor();

   AutorArchivo _autorArchivo;

};

/// Crear
/// Listar
/// Eliminar
