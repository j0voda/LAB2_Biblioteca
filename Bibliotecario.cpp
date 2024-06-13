#include "Bibliotecario.h"
#include<string>

using namespace std;

Bibliotecario::Bibliotecario() : Usuario() {}

Bibliotecario::Bibliotecario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos)
    : Usuario(nombre, apellido, telefono, mail, id, clave, permisos) {
}

bool Bibliotecario::ingresarClave() {
    string claveMaestra;
    cout << "Ingrese la clave maestra para registrar un bibliotecario: ";
    getline(cin, claveMaestra);

    if (claveMaestra != "4321") {
        cout << "Clave maestra incorrecta. No se puede registrar como bibliotecario." << endl;
        return false;
    }

    cout << "Clave maestra ingresada con exito.";
    return true;
}

