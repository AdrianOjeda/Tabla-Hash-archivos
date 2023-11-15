#pragma once
#include <iostream>
using namespace std;

class Registro
{
private:
    int clave;
    string nombre;
    int edad;

public:

    Registro();
    void serializar(std::ostream& os) const;
    void deserializar(std::istream& is);
    

    // Métodos Get y Set
    int getClave() const {
        return clave;
    }

    void setClave(int nuevaClave) {
        clave = nuevaClave;
    }

    const std::string& getDato1() const {
        return nombre;
    }

    void setDato1(const std::string& nuevoDato1) {
        nombre = nuevoDato1;
    }

    int getDato2() const {
        return edad;
    }

    void setDato2(int nuevoDato2) {
        edad = nuevoDato2;
    }
};

