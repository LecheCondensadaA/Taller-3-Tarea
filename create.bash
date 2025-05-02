#!/bin/bash

# Verificar si se proporcionó el número de directorios a crear
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Uso: $0 <cantidad_de_archivos> <directorio_destino>"
  exit 1
fi

# Número de archivos a crear
num_files=$1

# Directorio donde se guardarán los archivos
output_dir=$2

# Conjunto de extensiones posibles
extensions=(".txt" ".csv" ".cpp" ".c" ".json" ".xml" ".md")

# Función para generar un nombre aleatorio
random_name() {
  tr -dc 'a-z0-9' </dev/urandom | head -c $((RANDOM % 11 + 10))
}

# Crear el directorio si no existe
mkdir -p "$output_dir"

# Crear los archivos
for ((i = 1; i <= num_files; i++)); do
  # Se utiliza la funcion random_name para generar el nombre del archivo
  name=$(random_name) 
  # Despues se elige una de las posibles extenciones nombradas anterior mente
  ext=${extensions[$RANDOM % ${#extensions[@]}]}
  # Finalmente, crea el archivo utilizando el nombre y extencion generada
  touch "$output_dir/${name}${ext}"
done
