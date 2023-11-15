
#include <iostream>
#include "HashTable.h"
using namespace std;
const size_t MAX_TAMANO_ESPERADO = 1000;


void escribirRegistroBinario(const std::string& nombreArchivo, const Registro& registro) {
    std::ofstream archivo(nombreArchivo, std::ios::binary | std::ios::app);

    if (archivo.is_open()) {
        registro.serializar(archivo);
        archivo.close();
    }
    else {
        std::cerr << "Error al abrir el archivo para escritura binaria." << std::endl;
    }
}

void leerRegistrosBinarios(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (archivo.is_open()) {
        Registro registroLeido;
        while (!archivo.eof()) {
            registroLeido.deserializar(archivo);
            std::cout << "Clave: " << registroLeido.getClave() << ", edad: " << registroLeido.getDato2()
                << ", Nombre: " << registroLeido.getDato1() << std::endl;
        }

        archivo.close();
    }
    else {
        std::cerr << "Error al abrir el archivo para lectura binaria." << std::endl;
    }
}


int main() {
    using namespace std;

    HashTable tabla;
    int opcion;
    do {
   
        cout << "\n------ Menu ------\n";
        cout << "1. Insertar Registro\n";
        cout << "2. Eliminar Registro\n";
        cout << "3. Mostrar Datos del Archivo en Consola\n";
        cout << "4. Mostrar Tabla Hash\n";
        cout << "5. Salir\n";
        cout << "-------------------\n";
        cout << "Ingrese su opcion: ";

        int clave, edad;
        char nombre[30];
        cin >> opcion;

        switch (opcion) {
        case 1: {
         
            Registro nuevoRegistro;
            cout << "Ingrese la clave: ";
            cin >> clave;
            nuevoRegistro.setClave(clave);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese el nombre: ";
            cin.ignore(); 
            cin.getline(nombre, 30);
            nuevoRegistro.setDato1(nombre);
            cout << "Ingrese la edad: ";
            cin >> edad;
    

            nuevoRegistro.setDato2(edad);

            tabla.insertarRegistro(nuevoRegistro);
            escribirRegistroBinario("registros.bin", nuevoRegistro);
            cout << "Registro insertado con exito.\n";
            break;
        }
        case 2: {
            
            int claveEliminar;
            cout << "Ingrese la clave del registro a eliminar: ";
            cin >> claveEliminar;

            if (tabla.eliminarRegistro(claveEliminar)) {
                cout << "Registro eliminado con éxito.\n";
            }
            else {
                cout << "Registro no encontrado.\n";
            }
            break;
        }
        case 3: {
           
            leerRegistrosBinarios("registros.bin");
            break;
        }
        case 4: {
           
            tabla.mostrar();
            break;
        }
        case 5: {

            cout << "Saliendo del programa.\n";
            break;
        }
        default: {
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }
        }
    } while (opcion != 5);

    return 0;
}
