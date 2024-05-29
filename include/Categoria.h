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

    int getIdCategoria() const;
    void setIdCategoria(int id);

    string getNombre() const;
    void setNombre(const string &nombre);
};
