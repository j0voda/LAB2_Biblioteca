#include <iostream>
#include<cstdlib>
#include<cstring>
#include <cstdio>


using namespace std;

#include "CategoriaArchivo.h"

bool CategoriaArchivo::guardar(const Categoria &categoria){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "ab");
   if(pFile == nullptr){
      return false;
   }
   bool result = fwrite(&categoria, sizeof (Categoria), 1, pFile) == 1; //result será true solo si se escribió exactamente un elemento
   fclose(pFile);
   return result;
}

bool CategoriaArchivo::modificar(int index, const Categoria &categoria){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Categoria) * index, SEEK_SET);
   bool result = fwrite(&categoria, sizeof (Categoria), 1, pFile)== 1;
   fclose(pFile);
   return result;
}

int CategoriaArchivo::buscarById(int id){
    Categoria categoria;
    int pos = 0;
    FILE * pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&categoria, sizeof(Categoria), 1, pFile)){
        if(categoria.getId() == id){
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
   pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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
        return leer(cantidad - 1).getId() + 1;
    } else {
        return 1;
    }
}

void CategoriaArchivo::actualizar(const vector<Categoria> &categorias) {
	FILE *pFile = fopen(this->_nombreArchivo, "wb");
	if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto &categoria : categorias) {
        fwrite(&categoria, sizeof(Categoria), 1, pFile);
    }
    fclose(pFile);
}

