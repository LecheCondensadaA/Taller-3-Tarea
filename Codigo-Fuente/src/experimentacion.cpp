#include "experimentacion.h"
#include "vector.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void experimentos(fs::path& dir1) {
    //Creacion del vector:
    cout << "Creacion del vector..." <<endl;
    vector <string> v; //Crea un vector vacio.

    if (exists(dir1) && is_directory(dir1)) {
        //Creacion del vector
        chrono::high_resolution_clock::time_point ini = chrono::high_resolution_clock::now();

        for (const auto& entry : fs::directory_iterator(dir1)) {
            v.push_back(entry.path().string());
        }

        chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
        auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - ini);
        printf("La creacion del vector tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));

        //Busqueda secuencial: //ayuda con esto
        chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();

        busqueda_secuencial(v, "1nu0czggbd.xml", dir1);

        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
        printf("La busqueda secuencial tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));

        //Sort
        sta = chrono::high_resolution_clock::now();

        sort(v.begin(), v.end()); //Por mientras

        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
        printf("El sort tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));

        //Busqueda binaria:
        sta = chrono::high_resolution_clock::now();

        busqueda_binaria(v, "1nu0czggbd.xml", dir1);

        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
        printf("La busqueda binaria tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));
        
        //Eliminar elementos:
        sta = chrono::high_resolution_clock::now();

        int cant = 100000;
        vector<string> elim = eliminar_elementos(v, cant);

        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - sta);
        printf("La eliminacion tardo %.4f segundos\n", static_cast<double>(duration_creation.count()));
    

        //Insertar los elementos de vuelta:
        sta = chrono::high_resolution_clock::now();

        if (!elim.empty()) {
            insertar(v, elim, cant);
        }

        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - sta);
        printf("La insercion tardo %.4f segundos\n", static_cast<double>(duration_creation.count()));
    }
    //Si no existe, se avisa al usuario.
    else {
        cout << "El directorio no existe." << endl;
    }
}
