#include "PagoArchivo.h"

bool PagoArchivo::guardar(const Pago& pago) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (!pFile) {
        return false;
    }
    bool result = fwrite(&pago, sizeof(Pago), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

Pago PagoArchivo::leer(int index) {
    Pago pago;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return pago;
    }
    fseek(pFile, index * sizeof(Pago), SEEK_SET);
    fread(&pago, sizeof(Pago), 1, pFile);
    fclose(pFile);
    return pago;
}

vector<Pago> PagoArchivo::leerTodos() {
    vector<Pago> pagos;
    Pago pago;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return pagos;
    }
    while (fread(&pago, sizeof(Pago), 1, pFile)) {
        pagos.push_back(pago);
    }
    fclose(pFile);
    return pagos;
}

vector<Pago> PagoArchivo::leerPorIdUsuario(int idUsuario) {
    vector<Pago> pagos;
    Pago pago;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return pagos;
    }
    while (fread(&pago, sizeof(Pago), 1, pFile)) {
        if(pago.getIdUsuario() == idUsuario) {
            pagos.push_back(pago);
        }
    }
    fclose(pFile);
    return pagos;
}

int PagoArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Pago);
    fclose(pFile);
    return tam;
}

int PagoArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    return cantidad > 0 ? leer(cantidad - 1).getIdPago() + 1 : 1;
}
