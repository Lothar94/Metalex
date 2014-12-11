#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef GENC_H
#define GENC_H

/*Funcion que permite la generacion de una plantilla que servira posteriormente para analizar con lex e imprimir el PDF.*/
void generarPlantillaPDF(char ** exprs,int n,char * funcionalidad);

/*Funcion que permite la creacion del PDF haciendo uso del sistema (PDFLATEX).*/
void crearPDF(char* fichero);

#endif
