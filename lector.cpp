#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    int id_registro;
    char nombre[50];
    int cedula;
    int edad;
    float peso;
    float altura;
    char genero;
};

void leerRegistro(const string& nombreArchivo, int idBuscado) {
    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Persona persona;
    while (archivo.read(reinterpret_cast<char*>(&persona), sizeof(Persona))) {
    if (persona.id_registro == idBuscado) {
        cout << "Datos de la persona con ID " << idBuscado << endl;
        cout << "Nombre: " << persona.nombre << endl;
        cout << "Cedula: " << persona.cedula << endl;
        cout << "Edad: " << persona.edad << endl;
        cout << "Peso: " << persona.peso << endl;
        cout << "Altura: " << persona.altura << endl;
        cout << "Genero: " << persona.genero << endl;
        return;
        }
    }

    cerr << "Registro no encontrado." << endl;
    archivo.close();
}

int main() {
    string nombreArchivo = "personas.dat";
    int idBuscado;

    cout << "Ingrese el ID del registro a buscar: ";
    cin >> idBuscado;

    leerRegistro(nombreArchivo, idBuscado);

    return 0;
}