#include "experimentacion.h"
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;
using namespace fs;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./tarea directorio" << endl;
        exit(EXIT_FAILURE);
    }
    path dir1 = argv[1];

    experimentos(dir1);
    return 0;
}