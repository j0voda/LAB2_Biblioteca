#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Prestamo.h"

class PrestamoArchivo{
private:
	char _nombreArchivo[50] = "prestamos.dat";

public:
	bool guardar(const Prestamo &prestamo);
	bool modificar(int index, const Prestamo &prestamo);
	int buscarById(int id);
	Prestamo leer(int index);
	vector<Prestamo> leerTodos();
	int getCantidadRegistros();
	int getNuevoID();
	void actualizar(const vector<Prestamo> &prestamos);
	int buscarPorRangoFecha(const Fecha& fechaInicio, const Fecha& fechaFin);
};

