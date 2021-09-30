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
    char linha[maximo];
    fgets(linha, maximo, arq);
    while(!(feof(arq)))
    {
       printf("%s", linha);
       cont++;
       fgets(linha, maximo, arq);
    }
    return cont;
}
