#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 50
FILE *arq;
FILE *abrearquivo(int);
struct func
{
    char nome[MAX_STRING];
    char endereco[MAX_STRING];
    int salario;
    char funcao[MAX_STRING];
};

void apdados(struct func);
void arquivoLido(struct func);

int main()
{
    struct func funcionario;
    if(!(arq=abrearquivo(MAX_STRING)))
    {
       printf("Erro na abertura");
       printf("\n\n");
       system("pause");
    }
    else
    {
        arquivoLido(funcionario);
        apdados(funcionario);
        fclose(arq);
    }
    printf("\n\n");
    return 0;
}

void arquivoLido(struct func funcionario)
{
    printf("\n\nArquivo Lido:");
    rewind(arq);
    while(!(feof(arq)))
    {
        if(fread(&funcionario, sizeof(struct func), 1, arq)==1)
        {
            printf("\n\n    Nome: %s", funcionario.nome);
            printf("\n      Endereco: %s", funcionario.endereco);
            printf("\n      Salario: %d", funcionario.salario);
            printf("\n      Funcao: %s", funcionario.funcao);
        }
    }
}

void apdados(struct func funcionario)
{
    printf("\n\nGerentes:");
    rewind(arq);
    while(!(feof(arq)))
    {
        if(fread(&funcionario, sizeof(struct func), 1, arq)==1)
        {
            if(strcmp(funcionario.funcao,"gerente")==0)
            {
                printf("\n\n    Nome: %s", funcionario.nome);
                printf("\n      Salario: %d", funcionario.salario);
            }
        }
    }
}


FILE *abrearquivo(int max)
{
    char nome[max];
    printf("\nNome do arquivo: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    if (nome[strlen(nome)-1]=='\n')
       nome[strlen(nome)-1]='\0';
    return fopen(nome, "rb");
}
