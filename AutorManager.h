#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "Autor.h"
#include "AutorArchivo.h"

class AutorManager {
public:
   void menu();
   Autor agregarAutor();
   void listarAutores();
   void mostrarAutor(const Autor& autor);
   void mostrarResumenAutor();
   void eliminarAutor();
private:
   AutorArchivo _autorArchivo;
};

