#include "TipoMembresia.h"

TipoMembresia::TipoMembresia(){
    tipoMembresia = 0; /// 1- Membresia Basica 2- Membresia Premium  ...
    strcpy(nombre, "");
    //vigencia = 0;
    librosAlaVez = 0;
    librosXMes = 0;
    precio = 0.0f;
    estado = false;
}

TipoMembresia::TipoMembresia(int _tipoMembresia, const string &_nombre,/*int _vigencia,*/int _librosAlaVez, int _librosXMes, float _precio, bool _estado){
    tipoMembresia = _tipoMembresia;
    strcpy(nombre, _nombre.c_str());
    //vigencia = _vigencia;
    librosAlaVez = _librosAlaVez;
    librosXMes = _librosXMes;
    precio = _precio;
    estado = _estado;
}

int TipoMembresia::getTipoMembresia() const{
    return tipoMembresia;
}
void TipoMembresia::setTipoMembresia(int _tipoMembresia){
    tipoMembresia = _tipoMembresia;
}

string TipoMembresia::getNombre() const {
    string str = nombre;
    return str;
}
void TipoMembresia::setNombre(const string &_nombre) {
    strcpy(nombre, _nombre.c_str());
}

/*
int TipoMembresia::getVigencia() const{
    return vigencia;
}
void TipoMembresia::setVigencia(int _vigencia){
    vigencia = _vigencia;
}
*/
int TipoMembresia::getLibrosAlaVez() const{
    return librosAlaVez;
}
void TipoMembresia::setLibrosAlaVez(int _librosAlaVez){
    librosAlaVez = _librosAlaVez;
}

int TipoMembresia::getLibrosXMes() const{
    return librosXMes;
}
void TipoMembresia::setLibrosXMes(int _librosXMes){
    librosXMes = _librosXMes;
}

float TipoMembresia::getPrecio() const{
    return precio;
}
void TipoMembresia::setPrecio(float _precio){
    precio = _precio;
}

bool TipoMembresia::getEstado() const{
    return estado;
}
void TipoMembresia::setEstado(bool _estado){
    estado = _estado;
}


