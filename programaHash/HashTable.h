#pragma once
#include <iostream>
#include "Registro.h"
#include <fstream>
#include <string>
#include <list>
using namespace std;

class HashTable
{
public:
    static const int tamanoTablaInicial = 10; 
    int tamanoTablaActual;
    list<Registro>* tabla;
    HashTable();
    int funcionHash(int clave)const;
    bool eliminarRegistro(int clave);
    void insertarRegistro(const Registro& nuevoRegistro);
    Registro* buscarRegistro(int clave);
    void mostrar() const;
};

