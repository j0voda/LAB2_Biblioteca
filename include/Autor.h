#pragma once
#include <string>

using namespace std;

class Autor : public Persona
{
    private:
        int _id;
        string _nacionalidad;
        string _bestSellers;

    public:
        Autor();
        Autor(const string& nombre, const string& apellido, int id, const string &nacionalidad, const string &sellers);

        string getNacionalidad();
        void setNacionalidad(const string &nacionalidad);

        string getBestSellers();
        void setBestSellers(const string &sellers);

};
