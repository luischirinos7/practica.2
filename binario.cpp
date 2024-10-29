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

int main() {
    int numPersonas;

    cout << "Ingrese el numero de personas a registrar: ";
    cin >> numPersonas;

    ofstream archivo("personas.dat", ios::binary);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    for (int i = 0; i < numPersonas; ++i) {
        Persona persona;

        cout << "Ingrese los datos de la persona " << i + 1 << endl;
        cout << "ID: ";
        cin >> persona.id_registro;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(persona.nombre, 50);
        cout << "Cedula: ";
        cin >> persona.cedula;
        cout << "Edad: ";
        cin >> persona.edad;
        cout << "Peso: ";
        cin >> persona.peso;
        cout << "Altura: ";
        cin >> persona.altura;
        cout << "Genero (M o F): ";
        cin >> persona.genero;

        archivo.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
    }

    archivo.close();

    cout << "Datos guardados exitosamente en el archivo personas.dat" << endl;

    return 0;
}