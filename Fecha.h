#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    static Fecha obtenerFechaActual();
    Fecha sumarMes(int meses) const;
    string toString() const;

    ///sobrecarga para comparacion
    bool operator>(const Fecha &otra) const;
    bool operator<(const Fecha &otra) const;
    bool operator==(const Fecha &otra) const;
    bool operator!=(const Fecha &otra) const;
    bool operator<=(const Fecha &otra) const;
    bool operator>=(const Fecha &otra) const;
};
