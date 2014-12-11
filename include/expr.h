#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef EXPR_H
#define EXPR_H

/*Funcion que permite generar la plantilla de Lex para realizar la busqueda de la expresion regular.*/

void generarCodigo(char ** exprs,int n);

/*Funcion que compila la plantilla de Lex crea dos procesos hijo con fork() de manera secuencial que ejecutan las ordenes de lex y gcc.*/

void compilarCodigo();

/*Funcion que permite la ejecución del programa generado por la funcion anterior.*/

void ejecutarCodigo(char * fichero);

/*Función que permite comprobar la existencia de un fichero.*/
int comprobarFichero(char * archivo);

#endif
