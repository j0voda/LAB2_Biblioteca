#include <iostream>
#include<cstdlib>
#include<cstring>
#include <cstdio>


using namespace std;

#include "AutorArchivo.h"


/**
   ab -- agrega
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool AutorArchivo::guardar(const Autor &autor){
   bool result;
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "ab");

   if(pFile == nullptr){

      return false;
   }

   result = fwrite(&autor, sizeof (Autor), 1, pFile);

   fclose(pFile);

   return result;
}

bool AutorArchivo::modificar(int index, const Autor &autor){
   bool result;
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb+");

   if(pFile == nullptr){

      return false;
   }

   fseek(pFile, sizeof(Autor) * index, SEEK_SET);

   result = fwrite(&autor, sizeof (Autor), 1, pFile);

   fclose(pFile);

   return result;
}

int AutorArchivo::buscarById(int id){
    Autor autor;
    int pos = 0;
    FILE * pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&autor, sizeof(Autor), 1, pFile)){
        if(autor.getId() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Autor AutorArchivo::leer(int index){
   bool result;
   Autor autor;
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return autor;
   }

   fseek(pFile, index * sizeof (Autor), SEEK_SET);

   fread(&autor, sizeof(Autor), 1, pFile);

   fclose(pFile);

   return autor;
}

vector<Autor> AutorArchivo::leerTodos() {
    vector<Autor> autores;
    Autor autor;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return autores;
    }
    while (fread(&autor, sizeof(Autor), 1, pFile)) {
        autores.push_back(autor);
    }
    fclose(pFile);
    return autores;
}

int AutorArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Autor);
    fclose(pFile);
    return tam;
}

int AutorArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getId() + 1;
    } else {
        return 10;
    }
}

bool AutorArchivo::actualizar(const vector<Autor>& autores) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "wb");
    if (!pFile) {
        return false;
    }
    for (const auto& autor : autores) {
        if (fwrite(&autor, sizeof(Autor), 1, pFile) != 1) {
            fclose(pFile);
            return false;
        }
    }
    fclose(pFile);
    return true;
}
