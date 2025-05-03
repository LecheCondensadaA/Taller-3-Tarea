#include "experimentacion.h"
#include <vector>
#include <filesystem>
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
    cout << "CreaciÃ³n del vector..." <<endl;
    vector <string> v(num_files);
    if (exists(dir1) && is_directory(dir1)) { 
        for (const auto& entry : directory_iterator(dir1)) { 
            // Output the path of the file or subdirectory 
            cout << "File: " << entry.path() << endl;
        } 
    } 
    else { 
        // Handle the case where the directory doesn't exist 
        cerr << "Directory not found." << endl; 
        create_directory(dir1); 
        cout << "directorio creado! " << dir1;
        cout <<endl;
    }
    cout << "Vector creado!" <<endl;
    return 0;
}