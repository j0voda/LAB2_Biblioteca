#include <cctype>    // tolower
#include <string>
#include <vector>
#include <regex>

using namespace std;

#include "Admin.h"
#include "LibroManager.h"
#include "AutorManager.h"
#include "CategoriaManager.h"
#include "MembresiaManager.h"
//#include "UsuarioManager.h"

class AdminManager{
private:
	//UsuarioManager _usuarioManager;
	UsuarioArchivo _usuarioArchivo;
	MembresiaManager _membresiaManager;
	LibroManager _libroManager;
	AutorManager _autorManager;
	CategoriaManager _categoriaManager;

public:
	AdminManagerManager();

	void menuAdmin();
};
