#include<expr.h>

void generarCodigo(char ** exprs,int n){

   FILE *fp1,*fp2,*fp3;
   int bytesLeidos,m;
   char buffer[2048];
   char ** cadena = new char*[n];
   char funcionalidad[]="{ ECHO; printf(\"\\n\"); }\n";
   
   memset(buffer,'\0',2048);
   
   if(remove("./Plantilla/Plantilla.l") != 0){
      printf("No se puede borrar la plantilla.");
      exit(-1);
   }
   for(int i =0; i<n; i++){
      cadena[i] = new char[256];
      strcpy(cadena[i] , exprs[i]);
      strcat(cadena[i] , "\t");
      strcat(cadena[i], funcionalidad);
   }

   fp2 = fopen ("./Plantilla/Plantilla.l","a");
   fp1 = fopen ( "./Plantilla/cabecera", "r" );
   fp3 = fopen ("./Plantilla/cuerpo","r");

   while((bytesLeidos = fread(buffer, 1, 2048, fp1)))
         fputs( buffer, fp2 );
   for(int i = 0; i<n; i++)
      fputs(cadena[i], fp2);
   fputs("(.|\\n)   {;}",fp2);
   while((bytesLeidos = fread(buffer, 1, 2048, fp3)))
         fputs( buffer, fp2 );


   fclose ( fp1 );
   fclose ( fp2 );
   fclose ( fp3 );
   
   for(int i=0; i<n; i++)
      delete [] cadena[i];
   delete [] cadena;
}

void compilarCodigo(){
   system("lex ./Plantilla/Plantilla.l");
   system("gcc lex.yy.c -o ./bin/prog -lfl");
}

void ejecutarCodigo(char * fichero){
   char arg[1024];
   sprintf(arg,"./bin/prog %s", fichero);
   system(arg);
}

int comprobarFichero(char * archivo){
	int existe;
	FILE * fa;
	fa = fopen (archivo, "r");
	if (fa == NULL)
		existe = 0;
	else{
		existe = 1;
		fclose ( fa );
	}
	return existe;
}
