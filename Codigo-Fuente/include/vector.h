#include <vector>
#include <string>
#include<filesystem> // la libreria para poder ver y leer los archivos que hay en el directorio
using namespace std;

int busqueda_secuencial(vector<string> a, string arch, filesystem::path dir);
int busqueda_binaria(vector<string> a, string x, filesystem::path dir);
vector<string> eliminar_elementos(vector<string>& a, int num);
int insertar(vector<string>& a, vector<string> arch, int len);