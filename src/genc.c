#include<genc.h>

void generarPlantillaPDF(char ** exprs,int n, char* funcionalidad){
   FILE *fp1,*fp2,*fp3;
   int bytesLeidos;
   char buffer[2048];
   char ** cadena = new char*[n];
   //char funcionalidad[]="{ negrita((char*)yytext); }\n";
   
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
   fp1 = fopen ( "./Plantilla/cabeceralatex", "r" );
   fp3 = fopen ("./Plantilla/cuerpolatex","r");

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

void crearPDF(char* fichero){
   int bytesLeidos;

   char arg[1024];
   sprintf(arg, "./bin/prog %s", fichero);
   strcat(arg, ">> salida.tex");

   FILE *fp1, *fp2, *fp;
   char buffer[2048];
   
   memset(buffer,'\0',2048);

   if(remove("./salida.tex") != 0){
      printf("No se puede borrar la plantilla.");
      exit(-1);
   }

   fp = fopen ("salida.tex","a");
   fp1 = fopen ("./Plantilla/doclatex","r");
   fp2 = fopen ("./Plantilla/contlatex","r");
   while((bytesLeidos = fread(buffer, 1, 2048, fp1)))
      fputs( buffer, fp );
   fflush(fp);
   system(arg);
   memset(buffer,'\0',2048);
   while((bytesLeidos = fread(buffer, 1, 2048, fp2)))
      fputs( buffer, fp );

   fclose ( fp1 );
   fclose ( fp2 );
   fclose ( fp );
   
   system("pdflatex salida.tex");
}
