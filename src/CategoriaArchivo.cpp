#include <iostream>
#include<cstdlib>
#include<cstring>
#include <cstdio>


using namespace std;

#include "CategoriaArchivo.h"


/**
   ab -- agrega
   wb -- borra todo y te permite agregar
   rb -- lee

   rb+ -- lee y modifica (no agrega)
   ab+ -- agrega y lee
*/

bool CategoriaArchivo::guardar(const Categoria &categoria){
   FILE *pFile;
   pFile = fopen(_nombreArchivo.c_str(), "ab");

   if(pFile == nullptr){
      return false;
   }

   bool result = fwrite(&categoria, sizeof (Categoria), 1, pFile) == 1; //result ser� true solo si se escribi� exactamente un elemento

   fclose(pFile);

   return result;
}

bool CategoriaArchivo::modificar(int index, const Categoria &categoria){
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb+");

   if(pFile == nullptr){
      return false;
   }

   fseek(pFile, sizeof(Categoria) * index, SEEK_SET);

   bool result = fwrite(&categoria, sizeof (Categoria), 1, pFile)== 1;

   fclose(pFile);

   return result;
}

int CategoriaArchivo::buscarByID(int id){
    Categoria categoria;
    int pos = 0;
    FILE * pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&categoria, sizeof(Categoria), 1, pFile)){
        if(categoria.getID() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Categoria CategoriaArchivo::leer(int index){
   Categoria categoria;
   FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if(pFile == nullptr){
      return categoria;
   }

   fseek(pFile, index * sizeof (Categoria), SEEK_SET);

   fread(&categoria, sizeof(Categoria), 1, pFile);

   fclose(pFile);

   return categoria;
}

vector<Categoria> CategoriaArchivo::leerTodos() {
    vector<Categoria> categorias;
    Categoria categoria;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return categorias;
    }
    while (fread(&categoria, sizeof(Categoria), 1, pFile)) {
        categorias.push_back(categoria);
    }
    fclose(pFile);
    return categorias;
}

int CategoriaArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Categoria);
    fclose(pFile);
    return tam;
}

int CategoriaArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leer(cantidad - 1).getIdCategoria() + 1;
    } else {
        return 1;
    }
}

