#!/bin/bash
#este archivo es un scrip que compila el trabajo 2 y luego ejecuta Ej2
#gcc esto y lo otro
#./Trabajo2/Ej2

mkdir -p output

gcc Trabajo2/fuente1.c -o output/Ej1
gcc Trabajo2/fuente2.c -o output/Ej2
chmod 777 output/Ej1
chmod 777 output/Ej2

./output/Ej2