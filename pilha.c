#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define ESQUERDA 0
#define DIREITA 1
#define FRENTE 2
#define TRUE 1
#define FALSE 0

struct tipoNo{
    struct tipoNo *ant;
    int direcao;
    struct tipoNo *prox;
};
typedef struct tipoNo noPilha;

struct tipoPilha{
    struct tipoNo* cabeca;
    struct tipoNo* calda;
};



Pilha* criarPilha(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha != NULL){
       // printf("PILHA CRIADA:\n");
        pilha->cabeca = NULL;
        pilha->calda = NULL;
    }
    return(pilha);
}

int inserirPilha(Pilha* inicio, int direcao){
    if(inicio == NULL){
        return FALSE;
    }

    noPilha* novoNo = (noPilha*) malloc(sizeof(noPilha));
    novoNo->direcao = direcao;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    if(inicio->calda == NULL){
        inicio->cabeca = novoNo;
        inicio->calda = novoNo;
        return TRUE;
    }else{
        inicio->calda->prox = novoNo;
        novoNo->ant = inicio->calda;
        inicio->calda = novoNo;
    	return TRUE;
    }
}

void dadosImpressao(noPilha* aux){
    if(aux->direcao == DIREITA){
        printf("DIREITA|");
    }else if(aux->direcao == ESQUERDA){
        printf("ESQUERDA|");
    }else{
        printf("FRENTE|");
    }
}
void dadosImpressaoVolta(noPilha* aux){
    if(aux->direcao == DIREITA){
        printf("ESQUERDA|");
    }else if(aux->direcao == ESQUERDA){
        printf("DIREITA|");
    }else{
        printf("FRENTE|");
    }
}

int caminhoIda(Pilha* pilha){
    if(pilha == NULL){
        return FALSE;;
    }

    if(pilha->calda == NULL){
        return FALSE;;
    }

    noPilha* aux = pilha->cabeca;

    while(aux != NULL){
        dadosImpressao(aux);
        aux = aux->prox;
    }
    return TRUE;
}

int caminhoVolta(Pilha* pilha){
    if(pilha == NULL){
        return FALSE;
    }

    if(pilha->calda == NULL){
        return FALSE;
    }

    noPilha* aux = pilha->calda;

    while(aux != NULL){
        dadosImpressaoVolta(aux);
        aux = aux->ant;
    }
    return TRUE;
}

int apagarPilha(Pilha* pilha){
    if(pilha == NULL){
        return FALSE;
    }

    else if(pilha->calda == NULL){
        return FALSE;
    }else{
        noPilha* atual = pilha->cabeca;
        noPilha* anterior = NULL;
        while(atual != NULL){
            if(atual->prox == NULL){
                atual = NULL;
                free(pilha->calda);
                pilha->cabeca = NULL;
                pilha->calda = NULL;
                free(pilha);
                
            }else{
                anterior = pilha->cabeca->prox;
                anterior->ant = NULL;
                free(pilha->cabeca);
                pilha->cabeca = anterior;
                atual = anterior;
               
            }
        }

        return TRUE;
    }
}


