#include <string.h>
#include <stdio.h>



int main(){

    char velha[10];
    int i,j;

    printf ("\n\n       Jogo da Velha: edicao 0.0 da Berti\n\nJOGUE X OU O:\n\n\n");


    for (i=0;i<9;i++)
        gets(velha);

    printf ("\n\n\n   %c   |   %c   |   %c   \n\n\n   %c   |   %c   |   %c   \n\n\n   %c   |   %c   |   %c   \n\n\n",velha[0],velha[1],velha[2],velha[3],velha[4],velha[5],velha[6],velha[7],velha[8]);
    printf ("Alguem venceu, parabens alguem!!!\n\n\n\n\n");
}
