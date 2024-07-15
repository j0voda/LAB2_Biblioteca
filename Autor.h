#pragma once
#include <string>

using namespace std;

#include "Persona.h"

class Autor : public Persona {
private:
    int _id;
    char _nacionalidad[50];
    char _bestSellers[50];

public:
    Autor();
    Autor(const string &nombre, const string &apellido, int id, const string &nacionalidad, const string &sellers);

    int getId() const;
    void setId(int id);

    string getNacionalidad() const;
    void setNacionalidad(const string &nacionalidad);

    string getBestSellers() const;
    void setBestSellers(const string &sellers);
};
