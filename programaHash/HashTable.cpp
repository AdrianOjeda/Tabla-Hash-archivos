#include "HashTable.h"

HashTable::HashTable() : tamanoTablaActual(tamanoTablaInicial) {
    tabla = new std::list<Registro>[tamanoTablaActual];
}


int HashTable::funcionHash(int clave) const {
    return clave % tamanoTablaActual;
}


void HashTable::insertarRegistro(const Registro& nuevoRegistro) {
    int indice = funcionHash(nuevoRegistro.getClave());
    tabla[indice].push_back(nuevoRegistro);
}

Registro* HashTable::buscarRegistro(int clave) {
    int indice = funcionHash(clave);
    for (auto& registro : tabla[indice]) {
        if (registro.getClave() == clave) {
            return &registro;
        }
    }
    return nullptr;
}

bool HashTable::eliminarRegistro(int clave) {
    int indice = funcionHash(clave);

    auto& lista = tabla[indice];
    auto it = find_if(lista.begin(), lista.end(), [clave](const Registro& reg) {
        return reg.getClave() == clave;
        });

    if (it != lista.end()) {
        lista.erase(it);
        return true;  
    }

    return false;  
}
void HashTable::mostrar() const {
    for (int i = 0; i < tamanoTablaActual; ++i) {
        std::cout << "Indice " << i << ": ";

        for (const auto& registro : tabla[i]) {
            std::cout << "Clave: " << registro.getClave() << ", Nombre: " << registro.getDato1() << ", Edad: " << registro.getDato2() << " | ";
        }

        std::cout << std::endl;
    }
}