#include "PrestamoArchivo.h"

/**
   ab -- agrega
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool PrestamoArchivo::guardar(const Prestamo &prestamo){
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "ab");

   if(pFile == nullptr){

      return false;
   }

   bool result = fwrite(&prestamo, sizeof (Prestamo), 1, pFile)== 1;

   fclose(pFile);

   return result;
}

bool Prestamo::modificar(int index, const Prestamo &prestamo){
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb+");

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

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&prestamo, sizeof(Prestamo), 1, pFile)){
        if(prestamo.getIdCliente() == id){
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

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return Prestamo;
   }

   fseek(pFile, index * sizeof (Prestamo), SEEK_SET);

   fread(&prestamo, sizeof(Prestamo), 1, pFile);

   fclose(pFile);

   return prestamo;
}

vector<Prestamo> PrestamoArchivo::leerTodos() {
    vector<Prestamo> prestamos;
    Prestamo prestamo;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
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
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
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
    ofstream file(_nombreArchivo, ios::trunc);
    if (file.is_open()) {
        for (const auto &prestamo : prestamos) {
            file.write(reinterpret_cast<const char*>(&prestamo), sizeof(Prestamo));
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para actualizar." << endl;
    }
}

PrestamoArchivo::PrestamoArchivo()
{
    //ctor
}
