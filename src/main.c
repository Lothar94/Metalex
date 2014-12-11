#include <expr.h>
#include <genc.h>
#include <rexpr.h>

int main(){

	//-------------------------Declaraciones------------------------
	char archivo[1024], palabra[1024], opcion[6]="";
   char * funcionalidad;
   char ** exprs;
	int ex,n = 0;
	//--------------------------------------------------------------	

	//-----------------------Inicio de interfaz de usuario----------	
	printf("Introduzca el nombre del archivo a analizar: ");
	do{
	scanf("%s",archivo);
	if((ex = comprobarFichero(archivo))==0)
		printf("El archivo introducido no existe.\n");
	}while(ex == 0);
	
	printf("fexpr; Busca una expresion regular.\n");
   printf("rexpr; Reemplaza ocurrencias a partir de una expresion regular.\n");
	printf("genPDF; Generar PDF con enfasis.\n");
	printf("chfile; Cambiar el archivo analizado.\n");
	printf("exit; Salir.\n");
	//--------------------------------------------------------------	

	while(strcmp("exit", opcion)){
		printf("> ");
		scanf("%s", opcion);
		if(!strcmp("fexpr", opcion)){
         if(n != 0){
            for(int i=0; i<n; i++)
	            delete [] exprs[i];
            delete [] exprs;
         }
         printf("Numero de expresiones regulares a buscar: \n > ");
         scanf("%d",&n);
         exprs = new char*[n];
         for(int i=0; i<n; i++)
            exprs[i] = new char[256]; 
         for(int i = 0; i<n; i++){
			   printf("Escribe a continuacion la expresion regular: \n > ");
            scanf("%s",exprs[i]);
         }
			generarCodigo(exprs,n);
			compilarCodigo();
			ejecutarCodigo(archivo);
		}
		if(!strcmp("genPDF", opcion)){
         funcionalidad = new char[1024];
         if(n != 0){
            printf("(N) Negrita o (C) cursiva?");
            scanf("%s", opcion);
            if(!strcmp(opcion,"N"))
               strcpy(funcionalidad,"{ negrita((char*)yytext); }\n");
            else
               strcpy(funcionalidad,"{ cursiva((char*)yytext); }\n");
            generarPlantillaPDF(exprs,n,funcionalidad);
            compilarCodigo();
            crearPDF(archivo);
         }
         delete [] funcionalidad;
		}
  		if(!strcmp("rexpr", opcion)){
         if(n != 0){
            printf("Reemplazar por: ");
            scanf("%s",palabra);
			   reemplazar(exprs,n,palabra);
            compilarCodigo();
			   exModCodigo(archivo);
         }
         else
            printf("No se han buscado expresiones regulares.");
		}
		if(!strcmp("chfile", opcion)){
			printf("Escribe el nuevo fichero a analizar: \n > ");
				do{
					scanf("%s",archivo);
					if((ex = comprobarFichero(archivo))==0)
						printf("El archivo introducido no existe.\n");
				}while(ex == 0);
		}

	}
	return 0;
}
