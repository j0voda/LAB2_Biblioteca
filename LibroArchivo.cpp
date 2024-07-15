#include "LibroArchivo.h"

bool LibroArchivo::guardar(const Libro &libro){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "ab");
   if(pFile == nullptr){
      return false;
   }
   bool result = fwrite(&libro, sizeof (Libro), 1, pFile)== 1;
   fclose(pFile);
   return result;
}

bool LibroArchivo::modificar(int index, const Libro &libro){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "rb+");
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
    pFile = fopen(this->_nombreArchivo, "rb");
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
   pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE *pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &libro : libros) {
        fwrite(&libro, sizeof(Libro), 1, pFile);
    }
    fclose(pFile);
}


