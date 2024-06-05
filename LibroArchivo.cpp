#include "LibroArchivo.h"


/**
   ab -- agrega
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool LibroArchivo::guardar(const Libro &libro){
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "ab");

   if(pFile == nullptr){

      return false;
   }

   bool result = fwrite(&libro, sizeof (Libro), 1, pFile)== 1;

   fclose(pFile);

   return result;
}

bool LibroArchivo::modificar(int index, const Libro &libro){
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb+");

   if(pFile == nullptr){

      return false;
   }

   fseek(pFile, sizeof(Libro) * index, SEEK_SET);

   bool result = fwrite(&libro, sizeof (Libro), 1, pFile) == 1;

   fclose(pFile);

   return result;
}

int LibroArchivo::buscarById(int id){
    Libro libro;
    int pos = 0;
    FILE * pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        if(libro.getIdLibro() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Libro LibroArchivo::leer(int index){
   Libro libro;
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return libro;
   }

   fseek(pFile, index * sizeof (Libro), SEEK_SET);

   fread(&libro, sizeof(Libro), 1, pFile);

   fclose(pFile);

   return libro;
}

vector<Libro> LibroArchivo::leerTodos() {
    vector<Libro> libros;
    Libro libro;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return libros;
    }
    while (fread(&libro, sizeof(Libro), 1, pFile)) {
        libros.push_back(libro);
    }
    fclose(pFile);
    return libros;
}

int LibroArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Libro);
    fclose(pFile);
    return tam;
}

int LibroArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getIdLibro() + 1;
    } else {
        return 10;
    }
}

void LibroArchivo::actualizar(const vector<Libro> &libros) {
    ofstream file(_nombreArchivo, ios::trunc);
    if (file.is_open()) {
        for (const auto &libro : libros) {
            file.write(reinterpret_cast<const char*>(&libro), sizeof(Libro));
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para actualizar." << endl;
    }
}


