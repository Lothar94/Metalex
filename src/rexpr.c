#include<rexpr.h>

void reemplazar(char ** exprs,int n,char * palabra){

   FILE *fp1,*fp2,*fp3;
   int bytesLeidos;
   char buffer[2048];
   char ** cadena = new char*[n];
   char funcionalidad[1024];
   
   memset(buffer,'\0',2048);
   memset(funcionalidad,'\0',1024);
   
   if(remove("./Plantilla/Plantilla.l") != 0){
      printf("No se puede borrar la plantilla.");
      exit(-1);
   }

   strcpy(funcionalidad, "{ printf(\"%s\",\" ");
   strcat(funcionalidad , palabra);
   strcat(funcionalidad , " \"); }\n");   

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
   while((bytesLeidos = fread(buffer, 1, 2048, fp3)))
         fputs( buffer, fp2 );


   fclose ( fp1 );
   fclose ( fp2 );
   fclose ( fp3 );
   
   for(int i=0; i<n; i++)
      delete [] cadena[i];
   delete [] cadena;
}

void exModCodigo(char * fichero){
   char arg[1024];  
   sprintf(arg, "./bin/prog %s", fichero);
   strcat(arg, "> out");
   system(arg);
}
