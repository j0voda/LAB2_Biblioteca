#pragma once
#include <algorithm> // sort y transform
#include <cctype>    // tolower
#include <string>
#include <vector>
#include <regex>

using namespace std;

#include "Bibliotecario.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"
#include "MembresiaManager.h"
//#include "UsuarioManager.h"

class BibliotecarioManager{
private:
	//UsuarioManager _usuarioManager;
	UsuarioArchivo _usuarioArchivo;
	MembresiaManager _membresiaManager;
	LibroManager _libroManager;
	AutorManager _autorManager;
	CategoriaManager _categoriaManager;

public:
	BibliotecarioManager();

	void menuBibliotecario();
	void menuAdministrarClientes();

	Bibliotecario crearBibliotecario();
	bool ingresarClaveMaestra();
	int validarTel(const string &tel);
	int validarMail(const string &mail);

	void mostrarBibliotecario(const Usuario &registro);
	void listarBibliotecarios();
	void listarBibliotecariosPorNombre();
	void listarBibliotecariosPorApellido();
};

