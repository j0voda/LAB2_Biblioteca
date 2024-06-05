#pragma once
#include "Persona.h"

class Usuario : public Persona {
private:
    int _id;
    string _telefono;
    string _mail;
    string _clave;
    int _permisos; // 1: Bibliotecario 2: Cliente

public:
    // Constructor por defecto
    Usuario();

    // Constructor parametrizado
    Usuario(const string &nombre, const string &apellido, const string &telefono, const string &mail, int id, const string &clave, int permisos);

    // Getters y Setters
    int getId() const;
    void setId(int id);

    string getTelefono() const;
    void setTelefono(const string& telefono);

    string getMail() const;
    void setMail(const string& mail);

    string getClave() const;
    void setClave(const string &clave);

    int getPermisos() const;
    void setPermisos(int permisos);
};
