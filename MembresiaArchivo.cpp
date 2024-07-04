#include <vector>

using namespace std;

#include "MembresiaArchivo.h"

bool MembresiaArchivo::guardar(const Membresia& membresia) {
    FILE* pFile = fopen(this->_nombreArchivo, "ab");
    if (!pFile) {
        return false;
    }
    bool result = fwrite(&membresia, sizeof(Membresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

bool MembresiaArchivo::modificar(int index, const Membresia& membresia) {
    FILE* pFile = fopen(this->_nombreArchivo, "rb+");
    if (!pFile) {
        return false;
    }
    fseek(pFile, index * sizeof(Membresia), SEEK_SET);
    bool result = fwrite(&membresia, sizeof(Membresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

int MembresiaArchivo::buscarById(int id) {
    Membresia membresia;
    int pos = 0;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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

Membresia MembresiaArchivo::leer(int index) {
    Membresia membresia;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return membresia;
    }
    fseek(pFile, index * sizeof(Membresia), SEEK_SET);
    fread(&membresia, sizeof(Membresia), 1, pFile);
    fclose(pFile);
    return membresia;
}

vector<Membresia> MembresiaArchivo::leerTodas() {
    vector<Membresia> membresias;
    Membresia membresia;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return membresias;
    }
    while (fread(&membresia, sizeof(Membresia), 1, pFile)) {
        membresias.push_back(membresia);
    }
    fclose(pFile);
    return membresias;
}

int MembresiaArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Membresia);
    fclose(pFile);
    return tam;
}

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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return -1; // Si no se puede abrir el archivo, devuelve -1
    }
    int index = 0;
    while (fread(&membresia, sizeof(Membresia), 1, pFile)) {
        if (membresia.getIdCliente() == idUsuario) {
            fclose(pFile);
            return index; // Si encuentra la membresía con el ID de usuario, devuelve el índice
        }
        index++;
    }
    fclose(pFile);
    return -1; // Si no se encuentra la membresía con el ID de usuario, devuelve -1
}

void MembresiaArchivo::actualizar(const vector<Membresia> &membresias) {
    FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &membresia : membresias) {
        fwrite(&membresia, sizeof(Membresia), 1, pFile);
    }
    fclose(pFile);
}
