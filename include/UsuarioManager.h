#pragma once
#include <fstream> //para trabajar con archivos

#include "UsuarioArchivo.h"

using namespace std;

class UsuarioManager {
private:
   void agregarUsuario();
   void modificarUsuario();
   void listarUsuarios();
   void listarUsuariosPorNombre();
   void listarUsuariosPorApellido();
   void listarUsuariosPorPermisos();
   void eliminarUsuario();
   Usuario crearUsuario();
   void mostrarUsuario(const Usuario &registro);

   UsuarioArchivo _UsuariosArchivo;

public:
   void menu();

};
