#include "TipoMembresiaArchivo.h"

bool TipoMembresiaArchivo::guardar(const TipoMembresia& tipoMembresia) {
    FILE* pFile = fopen(this->_nombreArchivo, "ab");
    if (!pFile) {
        return false;
    }
    bool result = fwrite(&tipoMembresia, sizeof(TipoMembresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

bool TipoMembresiaArchivo::modificar(int index, const TipoMembresia& tipoMembresia) {
    FILE* pFile = fopen(this->_nombreArchivo, "rb+");
    if (!pFile) {
        return false;
    }
    fseek(pFile, index * sizeof(TipoMembresia), SEEK_SET);
    bool result = fwrite(&tipoMembresia, sizeof(TipoMembresia), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

int TipoMembresiaArchivo::buscarById(int id) {
    TipoMembresia tipoMembresia;
    int pos = 0;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return -1;
    }
    while (fread(&tipoMembresia, sizeof(TipoMembresia), 1, pFile)) {
        if (tipoMembresia.getTipoMembresia() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

TipoMembresia TipoMembresiaArchivo::leer(int index) {
    TipoMembresia tipoMembresia;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return tipoMembresia;
    }
    fseek(pFile, index * sizeof(TipoMembresia), SEEK_SET);
    fread(&tipoMembresia, sizeof(TipoMembresia), 1, pFile);
    fclose(pFile);
    return tipoMembresia;
}

vector<TipoMembresia> TipoMembresiaArchivo::leerTodas() {
    vector<TipoMembresia> tipoMembresias;
    TipoMembresia tipoMembresia;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return tipoMembresias;
    }
    while (fread(&tipoMembresia, sizeof(TipoMembresia), 1, pFile)) {
        tipoMembresias.push_back(tipoMembresia);
    }
    fclose(pFile);
    return tipoMembresias;
}

int TipoMembresiaArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(TipoMembresia);
    fclose(pFile);
    return tam;
}

int TipoMembresiaArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getTipoMembresia() + 1;
    } else {
        return 1;
    }
}

void TipoMembresiaArchivo::actualizar(const vector<TipoMembresia> &tipoMembresias) {
    FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &tipoMembresia : tipoMembresias) {
        fwrite(&tipoMembresia, sizeof(TipoMembresia), 1, pFile);
    }
    fclose(pFile);
}
