#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 80
FILE *arq;
FILE *abrearquivo(int);
int apdados(int, FILE *);
int main()
{
    if(!(arq=abrearquivo(MAX)))
    {
       printf("\nErro na abertura");
       printf("\n\n");
       system("pause");
    }
    else
    {
        printf("\n\nLinhas lidas: %d", apdados(MAX, arq));
        fclose(arq);
        printf("\n\n");
        return 0;
    }
}
FILE *abrearquivo(int maximo)
{
     char nome[maximo];
     printf("\nNome do arquivo: ");
     fflush(stdin);
     fgets(nome, maximo, stdin);
     if(nome[strlen(nome)-1]=='\n')
        nome[strlen(nome)-1]='\0';
     fflush(stdin);
     return fopen(nome, "r");
}
int apdados(int maximo, FILE *arq)
{
    int cont=0;
    char caract;
    while(!(feof(arq)))
    {
       caract=getc(arq);
       if(caract=='\n')
          cont++;
       caract=tolower(caract);
       switch(caract)
       {
            case 'a':
                caract='z';
                break;
            case 'e':
                caract='y';
                break;
            case 'i':
                caract='x';
                break;
            case 'o':
                caract='w';
                break;
            case 'u':
                caract='v';
                break;
            case 'v':
                caract='u';
                break;
            case 'w':
                caract='o';
                break;
            case 'x':
                caract='i';
                break;
            case 'y':
                caract='e';
                break;
            case 'z':
                caract='a';
                break;

       }
       putc(caract, stdout);
    }
    return cont;
}
