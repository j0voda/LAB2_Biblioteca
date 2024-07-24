#include "AutorArchivo.h"

bool AutorArchivo::guardar(const Autor &autor){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "ab");
   if(pFile == nullptr){
      return false;
   }
   bool result = fwrite(&autor, sizeof (Autor), 1, pFile)== 1;
   fclose(pFile);
   return result;
}

bool AutorArchivo::modificar(int index, const Autor &autor){
   FILE *pFile;
   pFile = fopen(this->_nombreArchivo, "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Autor) * index, SEEK_SET);
   bool result = fwrite(&autor, sizeof (Autor), 1, pFile) == 1;
   fclose(pFile);
   return result;
}

int AutorArchivo::buscarById(int id){
    Autor autor;
    int pos = 0;
    FILE * pFile;
    pFile = fopen(this->_nombreArchivo, "rb");
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
	Autor autor;
	FILE *pFile;
	pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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
    FILE* pFile = fopen(this->_nombreArchivo, "rb");
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

void AutorArchivo::actualizar(const vector<Autor>& autores) {
    FILE* pFile = fopen(this->_nombreArchivo, "wb");
    if (!pFile) {
        cerr << "Error al abrir el archivo para actualizar." << endl;
        return;
    }
    for (const auto& autor : autores) {
        fwrite(&autor, sizeof(Autor), 1, pFile);
    }
    fclose(pFile);
}
