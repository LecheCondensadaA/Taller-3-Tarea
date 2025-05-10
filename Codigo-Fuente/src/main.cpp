#include "experimentacion.h"
#include <vector>
#include <filesystem>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
namespace fs = std::filesystem;
using namespace fs;

int busqueda_secuencial(vector <string> a, string arch, path dir);
int busqueda_binaria(vector<string> a, string x, path dir);
int insertar(vector<string> &a, vector<string> arch, int len);
vector<string> eliminar_elementos(vector<string>&a, int num);

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./tarea directorio" << endl;
        exit(EXIT_FAILURE);
    }
    path dir1 = argv[1];

    //Creacion del vector:
    cout << "Creacion del vector..." <<endl;
    vector <string> v; //Crea un vector vacio.

    //Se checa si existe el directorio:
    if (exists(dir1) && is_directory(dir1)) {

        //Se toma el tiempo:
        chrono::high_resolution_clock::time_point ini = chrono::high_resolution_clock::now();

        //Llena el vector con todos los archivos del directorio:
        for (const auto& entry : directory_iterator(dir1)) {
            v.push_back(entry.path().string());
        }
        // Calcula la duracion del proceso:
        chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
        auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - ini);

        // Imprimimos el tiempo de duracion
        printf("La creacion del vector tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));

        //Llamamos al resto de funciones de experimentacion:
        //Busqueda secuencial:
        busqueda_secuencial(v, "1nu0czggbd.xml", dir1);

        //Inicio sort
        chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();
        sort(v.begin(), v.end()); //Por mientras
        fin = chrono::high_resolution_clock::now();
        duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
        printf("El sort tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));
        //Fin sort
        //Busqueda binaria:
        busqueda_binaria(v, "1nu0czggbd.xml", dir1);
        //Eliminar elementos:
        int cant = 100000;
        vector <string> elim = eliminar_elementos(v, cant);
        //Insertar los elementos de vuelta:
        if (elim.empty()==false){
            insertar(v, elim, cant);
        }
    }
    //Si no existe, se avisa al usuario.
    else {
        cout << "El directorio no existe." <<endl;
    }
    return 0;
}

int busqueda_secuencial(vector <string> a, string arch, path dir){
    int i;
    chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();
    for (i=0; i < a.size(); i++) {
        if (a[i] == dir.string() + "/" + arch ){
            chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
            auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
            printf("La busqueda secuencial tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));
            return i;
        }
    }
    chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
    printf("No se encontro el archivo, la busqueda secuencial tardo %.4f milisegundos\n", 			static_cast<double>(duration_creation.count()));
    return -1;
}

int busqueda_binaria(vector<string> a, string x, path dir){
    int l,m,r;
    //Inicio búsqueda binaria:
    chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();
    l=0;
    r=a.size()-1;
    m=r/2;
    while(l<=r){
        if (dir.string()+"/"+x<a[m]){ // nota por si las mañas cambiar el signo por si entrega mal el archivo
            r=m-1;
        }
        else{
            if (dir.string()+"/"+x==a[m]){
                //Fin busqueda binaria:
                chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
                auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
                printf("La busqueda binaria tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));
                return m;
                //
            }
            else{
                l=m+1;
            }
        }
        m=(l+r)/2;
    }
    //Fallo busqueda binaria.
    chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::milliseconds>(fin - sta);
    printf("No se encontro el archivo y la busqueda binaria tardo %.4f milisegundos\n", static_cast<double>(duration_creation.count()));
    //
    return -1;
}

vector<string> eliminar_elementos(vector<string> &a, int num){
    int puesto;
    vector<string> eliminado;
    if (a.size() < num){
        cout << "El directorio no tiene suficientes elementos para realizar la eliminacion." <<endl;
        return {};
    }

    chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();
    for (int i = 0; i<num; i++){
        puesto = rand() % a.size();
        eliminado.push_back(a[puesto]);
        a.erase(a.begin()+puesto);
    }
    chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - sta);
    printf("La eliminacion tardo %.4f segundos\n", static_cast<double>(duration_creation.count()));
    return eliminado;
}

int insertar(vector<string> &a, vector<string> arch, int len){
    int i, j, l, r, m;
    chrono::high_resolution_clock::time_point sta = chrono::high_resolution_clock::now();
    for (i=0; i<len; i++){
        l=0;
        r=a.size()-1;
        m=r/2;
        bool insertado = false;
        while((l<=r) && (insertado==false)){
            if (arch[i]<a[m]){ // nota por si las mañas cambiar el signo por si entrega mal el archivo
                r=m-1;
            }
            else{
                if (arch[i] >= a[m] && arch[i] <= a[m+1]){
                    a.insert(a.begin()+m+1, arch[i]);
                    insertado = true;
                    //
                }
                else{
                    l=m+1;
                }
            }
            m=(l+r)/2;
        }
    }
    chrono::high_resolution_clock::time_point fin = chrono::high_resolution_clock::now();
    auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - sta);
    printf("La insercion tardo %.4f segundos\n", static_cast<double>(duration_creation.count()));
    return 0;
}
