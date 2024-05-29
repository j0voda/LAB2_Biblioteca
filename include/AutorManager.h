#pragma once
#include <vector>
#include <iostream>

#include "AutorArchivo.h"

class AutorManager {
public:
   void menu();

private:
   void agregarAutor();
   void listarAutores();
   void eliminarAutor();

   AutorArchivo _autorArhivo;

};

/// Crear
/// Listar
/// Eliminar
