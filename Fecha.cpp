#include "Fecha.h"

Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 1900;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia() const {
    return _dia;
}
int Fecha::getMes() const {
    return _mes;
}
int Fecha::getAnio() const {
    return _anio;
}

void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}

Fecha Fecha::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return Fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

Fecha Fecha::sumarMes(int meses) const {
    tm fecha = {0};
    fecha.tm_mday = _dia;
    fecha.tm_mon = _mes - 1 + meses;
    fecha.tm_year = _anio - 1900;

    mktime(&fecha);

    return Fecha(fecha.tm_mday, fecha.tm_mon + 1, fecha.tm_year + 1900);
}

string Fecha::toString() const {
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}

bool Fecha::operator>(const Fecha &otra) const {
    if (_anio > otra._anio) return true;
    if (_anio == otra._anio && _mes > otra._mes) return true;
    if (_anio == otra._anio && _mes == otra._mes && _dia > otra._dia) return true;
    return false;
}

bool Fecha::operator<(const Fecha &otra) const {
    if (_anio < otra._anio) return true;
    if (_anio == otra._anio && _mes < otra._mes) return true;
    if (_anio == otra._anio && _mes == otra._mes && _dia < otra._dia) return true;
    return false;
}

bool Fecha::operator==(const Fecha &otra) const {
    return (_anio == otra._anio && _mes == otra._mes && _dia == otra._dia);
}

bool Fecha::operator!=(const Fecha &otra) const {
    return !(*this == otra);
}

bool Fecha::operator<=(const Fecha &otra) const {
    return !(*this > otra);
}

bool Fecha::operator>=(const Fecha &otra) const {
    return !(*this < otra);
}

