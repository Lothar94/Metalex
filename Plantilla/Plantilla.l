%{
#include <stdio.h>
FILE *fp;

void negrita(char* texto);
void cursiva(char* texto);
%}

%%
[[:blank:]]e[a-z]*m[[:blank:]]	{ negrita((char*)yytext); }
\n {printf("\\\\");}
%%

int main (int argc, char *argv[])
{

  if (argc == 2)   
  {     
    yyin = fopen (argv[1], "rt"); 

    if (yyin == NULL)     
    {       
      printf ("El fichero %s no se puede abrir\n", argv[1]);       
      exit (-1);     
    }   
  }   
  else yyin = stdin;   

  yylex ();   

  return 0; 
}

void negrita(char* texto){
   printf("\\textbf{");
   printf("%s", texto);
   printf("}");
}

void cursiva(char* texto){
   printf("\\textit{");
   printf("%s", texto);
   printf("}");
}
