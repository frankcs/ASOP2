#!/bin/bash
#este archivo es un scrip que compila el trabajo 2 y luego ejecuta Ej2
#gcc esto y lo otro
#./Trabajo2/Ej2

mkdir -p output

gcc Trabajo2/fuente1.c -o output/Ej1
chmod 777 output/Ej1

./output/Ej1