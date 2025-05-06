#include "experimentacion.h"
#include <vector>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;
using namespace fs;
#include <iostream>
#include <chrono>

int busqueda_secuencial(vector <string> a, string arch, path dir);

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
        auto duration_creation = std::chrono::duration_cast<std::chrono::seconds>(fin - ini);
        busqueda_secuencial(v, "1nu0czggbd.xml", dir1);
        cout << "Vector creado!" <<endl;
        // Imprimimos el tiempo de duracion
    	printf("La creacion y ordenamiento del vector llevo %.4f segundos\n", static_cast<double>(duration_creation.count()));
        
    }
    //Si no existe, se avisa al usuario.
    else { 
        cout << "El directorio no existe." <<endl;
    }
    return 0;
}

int busqueda_secuencial(vector <string> a, string arch, path dir){
	int i;
	for (i=0; i < a.size(); i++) {
		if (a[i] == dir.string() + "/" + arch ){
			cout<< a[i] <<endl;
			return i;
		}
	}
	return -1;
}
int busqueda_binaria(vector<string> a, string x){
	int l,m,r;
	sort(a.begin(), a.end()); //Por mientras
	
	l=0;
	r=a.size()-1;
	m=r/2;
	while(l<=r){
		if (x<a[m]) // nota por si las mañas cambiar el signo por si entrega mal el archivo
			r=m-1;
		else{
			if (x==a[m])
				return m;
			else
				l=m+1;
		}
		m=(l+r)/2;
	}
	return -1;
}
