#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef REXPR_H
#define REXPR_H

/*Funcion que permite reemplazar las ocurrencias dadas.*/
void reemplazar(char ** exprs,int n,char * palabra);

/*Funcion que crea una salida out con el texto modificado.*/
void exModCodigo(char * fichero);

#endif
