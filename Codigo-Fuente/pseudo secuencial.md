# Pseudocodigo de busqueda secuencial  
busqueda_secuencial(vector <string> a, string arch, path dir){  
    for i←0 to a.size()-1 do {  
        if (a[i] = dir.string() + "/" + arch) then {  
            print "La busqueda secuencial tardo" + duracion "milisegundos";  
            return i;  
        }  
    }  
    print "No se encontro el archivo, la busqueda secuencial tardo" + duracion + "milisegundos;  
    return -1;  
}
