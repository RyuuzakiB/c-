#include<stdio.h>
#include<stdlib.h>
#define QTDE_PRODUTOS 50
#define DIAS_DA_SEMANA 6

struct prod
{
    int codigo;
    char tipo;
    int quantidade[DIAS_DA_SEMANA];
    double media;
};

void dados(struct prod *);
void media(struct prod *);
void apdados(struct prod *);

int main()
{
    struct prod produto[QTDE_PRODUTOS];
    dados(produto);
    media(produto);
    apdados(produto);
    return 0;
}

void dados(struct prod *produto)
{
    int i, j;
    for(i=0; i<QTDE_PRODUTOS;i++)
    {
        printf("\n\nCodigo do produto: ");
        scanf("%d", &((produto+i)->codigo));
        do
        {
            fflush(stdin);
            printf("\nTipo do produto(P-pequeno, M-medio ou G-grande): ");
            scanf(" %c", &((produto+i)->tipo));
            (produto+i)->tipo=toupper((produto+i)->tipo);
            fflush(stdin);
            if((produto+i)->tipo!='P' && (produto+i)->tipo!='M' && (produto+i)->tipo!='G')
               printf("\nTipo do produto invalido, digite novamente\n");
        }
        while((produto+i)->tipo!='P' && (produto+i)->tipo!='M' && (produto+i)->tipo!='G');
        printf("\nQuantidade referente aos dias da semana:");
        for(j=0; j<DIAS_DA_SEMANA;j++)
        {
            printf("\nDia %d: ", j+1);
            scanf("%d", &((produto +i)->quantidade[j]));
        }
    }
}

void media(struct prod *produto)
{
    int i, j, soma=0;
    for(i=0;i<QTDE_PRODUTOS;i++)
    {
      for(j=0;j<DIAS_DA_SEMANA;j++)
      {
        soma+=(produto+i)->quantidade[j];
      }
      (produto+i)->media=soma/(double)DIAS_DA_SEMANA;
    }
}

void apdados(struct prod *produto)
{
    int i, j;
    for(i=0;i<QTDE_PRODUTOS;i++)
    {
        printf("\n\nCodigo do produto %d: %d", i+1, (produto+i)->codigo);
        printf("\nTipo: %c", (produto+i)->tipo);
        printf("\nQuantidade vendida por dia:");
        for(j=0;j<DIAS_DA_SEMANA;j++)
        {
            printf("\n  Dia %d: %d", (j+1),(produto+i)->quantidade[j]);
        }
        printf("\nMedia Semanal:%.2lf", (produto+i)->media);

    }
}
