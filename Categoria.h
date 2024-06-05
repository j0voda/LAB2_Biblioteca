#pragma once
#include <string>

using namespace std;

class Categoria {
private:
    int _id;
    string _nombre;

public:
    Categoria();
    Categoria(int id, const string &nombre);

    int getId() const;
    void setId(int id);

    string getNombre() const;
    void setNombre(const string &nombre);
};
