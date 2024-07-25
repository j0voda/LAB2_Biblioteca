#include "PrestamoArchivo.h"

bool PrestamoArchivo::guardar(const Prestamo &prestamo){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "ab");
   if(pFile == nullptr){
      return false;
   }
   bool result = fwrite(&prestamo, sizeof (Prestamo), 1, pFile)== 1;
   fclose(pFile);
   return result;
}

bool PrestamoArchivo::modificar(int index, const Prestamo &prestamo){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Prestamo) * index, SEEK_SET);
   bool result = fwrite(&prestamo, sizeof (Prestamo), 1, pFile) == 1;
   fclose(pFile);
   return result;
}

int PrestamoArchivo::buscarById(int id){
    Prestamo prestamo;
    int pos = 0;
    FILE * pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&prestamo, sizeof(Prestamo), 1, pFile)){
        if(prestamo.getIdPrestamo() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Prestamo PrestamoArchivo::leer(int index){
   Prestamo prestamo;
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "rb");
   if(pFile == nullptr){
      return prestamo;
   }
   fseek(pFile, index * sizeof (Prestamo), SEEK_SET);
   fread(&prestamo, sizeof(Prestamo), 1, pFile);
   fclose(pFile);
   return prestamo;
}

vector<Prestamo> PrestamoArchivo::leerTodos() {
    vector<Prestamo> prestamos;
    Prestamo prestamo;
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return prestamos;
    }
    while (fread(&prestamo, sizeof(Prestamo), 1, pFile)) {
        prestamos.push_back(prestamo);
    }
    fclose(pFile);
    return prestamos;
}

int PrestamoArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Prestamo);
    fclose(pFile);
    return tam;
}

int PrestamoArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getIdPrestamo() + 1;
    } else {
        return 10;
    }
}

void PrestamoArchivo::actualizar(const vector<Prestamo> &prestamos) {
    FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &prestamo : prestamos) {
        fwrite(&prestamo, sizeof(Prestamo), 1, pFile);
    }
    fclose(pFile);
}

int PrestamoArchivo::buscarPorRangoFecha(const Fecha& fechaInicio, const Fecha& fechaFin) {
    vector<Prestamo> prestamos = leerTodos();
    int conteo = 0;

    for (const auto& prestamo : prestamos) {

		Fecha fechaPrestamo = prestamo.getFechaPrestamo();
        if (fechaInicio<=fechaPrestamo && fechaPrestamo <= fechaFin) {
            conteo++;
        }
    }

    return conteo;
}


/*
PrestamoArchivo::PrestamoArchivo()
{
    //ctor
}*/
