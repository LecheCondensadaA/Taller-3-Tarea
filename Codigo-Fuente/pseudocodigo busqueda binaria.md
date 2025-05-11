# pseudocodigo busqueda binaria  
busqueda_binaria(vector<string> a, string arch, path dir){  
	l ← 0;  
	r ← a.size()-1;  
	m ← r/2;  
	while(l<=r) do {  
		if (dir.string()+"/"+arch < a[m]) then {  
			r ← m-1;  
        }  
		else{  
            if (dir.string()+"/"+arch = a[m]) then {  
                print "La busqueda binaria tardo" + duracion + "milisegundos";  
                return m;  
            }  
            else{  
                l ← m+1;  
            }  
        }  
        m ← (l+r)/2;  
    }  
    print "No se encontro el archivo y la busqueda binaria tardo" + duracion + "milisegundos"  
    return -1;  
}
