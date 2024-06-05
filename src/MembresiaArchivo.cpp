#include "MembresiaArchivo.h"
#include <vector>

using namespace std;

// Guarda una nueva membresía en el archivo
bool MembresiaArchivo::guardar(const Membresia& membresia) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (!pFile) {
        return false;
    }
    bool result = fwrite(&membresia, sizeof(Membresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

// Modifica una membresía existente en el archivo
bool MembresiaArchivo::modificar(int index, const Membresia& membresia) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (!pFile) {
        return false;
    }
    fseek(pFile, index * sizeof(Membresia), SEEK_SET);
    bool result = fwrite(&membresia, sizeof(Membresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

// Busca una membresía por su ID
int MembresiaArchivo::buscarById(int id) {
    Membresia membresia;
    int pos = 0;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return -1;
    }
    while (fread(&membresia, sizeof(Membresia), 1, pFile)) {
        if (membresia.getId() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

// Lee una membresía desde el archivo
Membresia MembresiaArchivo::leer(int index) {
    Membresia membresia;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return membresia;
    }
    fseek(pFile, index * sizeof(Membresia), SEEK_SET);
    fread(&membresia, sizeof(Membresia), 1, pFile);
    fclose(pFile);
    return membresia;
}

// Lee todas las membresías desde el archivo
vector<Membresia> MembresiaArchivo::leerTodas() {
    vector<Membresia> membresias;
    Membresia membresia;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return membresias;
    }
    while (fread(&membresia, sizeof(Membresia), 1, pFile)) {
        membresias.push_back(membresia);
    }
    fclose(pFile);
    return membresias;
}

// Obtiene la cantidad de registros en el archivo
int MembresiaArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Membresia);
    fclose(pFile);
    return tam;
}

// Obtiene un nuevo ID para una nueva membresía
int MembresiaArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getId() + 1;
    } else {
        return 1;
    }
}

int MembresiaArchivo::buscarPorIdUsuario(int idUsuario) {
    Membresia membresia;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return -1; // Si no se puede abrir el archivo, devuelve -1
    }
    int index = 0;
    while (fread(&membresia, sizeof(Membresia), 1, pFile)) {
        if (membresia.getIdUsuario() == idUsuario) {
            fclose(pFile);
            return index; // Si encuentra la membresía con el ID de usuario, devuelve el índice
        }
        index++;
    }
    fclose(pFile);
    return -1; // Si no se encuentra la membresía con el ID de usuario, devuelve -1
}
