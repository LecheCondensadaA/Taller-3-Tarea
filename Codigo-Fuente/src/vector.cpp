#include "vector.h"
#include <iostream>
#include <cstdlib> //en evaluacion
#include<filesystem> // la libreria para poder ver y leer los archivos que hay en el directorio
using namespace std;

int busqueda_secuencial(vector <string> a, string arch, filesystem::path dir){
    int i;
    for (i=0; i < a.size(); i++) {
        if (a[i] == dir.string() + "/" + arch ){
            return i;
        }
    }
    return -1;
}

int busqueda_binaria(vector<string> a, string x, filesystem::path dir){
    int l,m,r;
    //Inicio búsqueda binaria:
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
                return m;
                //
            }
            else{
                l=m+1;
            }
        }
        m=(l+r)/2;
    }
    return -1;
}

vector<string> eliminar_elementos(vector<string> &a, int num){
    int puesto;
    vector<string> eliminado;
    if (a.size() < num){
        cout << "El directorio no tiene suficientes elementos para realizar la eliminacion." <<endl;
        return {};
    }

    for (int i = 0; i<num; i++){
        puesto = rand() % a.size();
        eliminado.push_back(a[puesto]);
        a.erase(a.begin()+puesto);
    }
    return eliminado;
}

int insertar(vector<string> &a, vector<string> arch, int len){
    int i, j, l, r, m;
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
                }
                else{
                    l=m+1;
                }
            }
            m=(l+r)/2;
        }
    }
    return 0;
}
