#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define ESQUERDA 0
#define DIREITA 1
#define FRENTE 2
#define MAX 6

int main()
{
    int vetInteiro[MAX] = {FRENTE, FRENTE , FRENTE, FRENTE , DIREITA,
                                    DIREITA };

    Pilha* pilha = criarPilha();

    int i;

    for(i = 0; i<MAX; i++){
        inserirPilha(pilha, vetInteiro[i]);
    }

    printf("Caminho do robo na ida:\n\n");
    caminhoIda(pilha);
    printf("\n\n");
    printf("\nCaminho do Robo na Volta:\n\n");
    caminhoVolta(pilha);
    printf("\n\n");
    
    


    if(apagarPilha(pilha) == 1){
       // printf("PILHA APAGADA !\n");
    }else{
        printf("NAO FOI POSSIVEL APAGAR A PILHA !!!\n");
    }

    
    return 0;
}
