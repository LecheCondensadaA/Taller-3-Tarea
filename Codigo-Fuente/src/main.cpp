#include "experimentacion.h"
#include <vector>
#include <filesystem>
#include <string>
#include <chrono>

using namespace std;
namespace fs = std::filesystem;
using namespace fs;
#include <iostream>

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./tarea k" << endl;
        exit(EXIT_FAILURE);
    }
    int num_files=atoi(argv[1]);
    int i;
    string name, ext;
    path dir1 = "/home/flowerpot-vt/Progra/Tarea-INFO088-2025S1/direc";
    if (!exists(dir1)) { 

    }
    else{
        cout << "papu papu, existe el papu directorio papu" <<endl;
    }
    cout << "Creacion del vector..." <<endl;
    chrono::high_resolution_clock::time_point ini = chrono::high_resolution_clock::now();
    vector <string> v(num_files);
    if (exists(dir1) && is_directory(dir1)) {
        i=0;
        for (const auto& entry : directory_iterator(dir1)) {
           v[i] = entry.path().string(); 
           cout << v[i] << endl;
           i=i+1;
        } 
    } 
    else { 
        // Handle the case where the directory doesn't exist 
        cerr << "Directory not found." << endl; 
        create_directory(dir1); 
        chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
        cout << "directorio creado! " << dir1;
        cout <<endl;
        // Calculamos duracion en segudos
        auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - ini);

        // Imprimimos el tiempo de duracion
        printf("La creacion y ordenamiento del vector llevo %.4f segundos\n", static_cast<double>(duration_creation.count()));
    }
    cout << "Vector creado!" <<endl;
    return 0;
}