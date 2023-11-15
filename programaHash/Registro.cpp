#include "Registro.h"
#include <string>
#include <vector>
#include <cstring> 
using namespace std;
Registro::Registro() : clave(0), edad(0), nombre("") {}

void Registro::serializar(std::ostream& os) const {
    os.write(reinterpret_cast<const char*>(&clave), sizeof(clave));
    os.write(nombre.c_str(), nombre.size() + 1);  // Escribir la cadena incluyendo el carácter nulo
    os.write(reinterpret_cast<const char*>(&edad), sizeof(edad));
}


void Registro::deserializar(std::istream& is) {
    // Leer la clave directamente en la variable miembro
    is.read(reinterpret_cast<char*>(&clave), sizeof(clave));

    // Usar getline para leer la cadena de caracteres
    getline(is, nombre, '\0');

    // Leer la edad directamente en la variable miembro
    is.read(reinterpret_cast<char*>(&edad), sizeof(edad));
}
