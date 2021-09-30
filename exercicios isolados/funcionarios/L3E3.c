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
    char nomeFuncionario[MAX_STRING];
    int modificado=0;
    int posicao=0;
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
        do
        {
            rewind(arq);
            posicao=0;
            fflush(stdin);
            printf("\n\nNome do funcionario para alteracao de salario: ");
            fgets(nomeFuncionario, MAX_STRING, stdin);
            fflush(stdin);
            if (nomeFuncionario[strlen(nomeFuncionario)-1]=='\n')
                nomeFuncionario[strlen(nomeFuncionario)-1]='\0';
            while(!(feof(arq)))
            {
                if(fread(&funcionario, sizeof(struct func), 1, arq)==1)
                {
                    if(strcmp(funcionario.nome,nomeFuncionario)==0 && modificado==0)
                    {
                        printf("\nNovo salario: ");
                        scanf("%d", &(funcionario.salario));
                        modificado=1;
                        fseek(arq, posicao*sizeof(struct func), 0);
                        fwrite(&funcionario, sizeof(struct func), 1, arq);
                        fseek(arq, sizeof(struct func), 2);
                    }
                }
                posicao++;
            }
            if(modificado==0)
                printf("\n\nNao foi possivel achar o nome desejado, digite novamente");
        }
        while(modificado==0);
        printf("\n\nDados com o salario modificado");
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
    return fopen(nome, "r+b");
}

