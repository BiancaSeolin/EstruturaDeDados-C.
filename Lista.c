#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


struct tipoNo{
    int numero;
    struct tipoNo *prox;
};


typedef struct tipoNo noLista;


Lista* criarLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        *lista = NULL;
    }
    return (lista);
}

int inserindoOrdenado(Lista* inicio, int valor){
    if(inicio == NULL){
        return 0;
    }
    noLista* novoNo = (noLista*) malloc(sizeof(noLista));
    novoNo->numero = valor;
    novoNo->prox = NULL;

    if((*inicio) == NULL){
        *inicio = novoNo;
        return 1;
    }
    if((*inicio)->prox == NULL && (*inicio)->numero > valor){
        novoNo->prox = *inicio;
        *inicio = novoNo;
        return 1;
    }

    if((*inicio)->numero > valor){
        novoNo->prox = *inicio;
        *inicio = novoNo;
        return 1;
    }

    noLista *atual = *inicio, *anterior = NULL;

    while(atual != NULL){
        if(valor < atual->numero){
            novoNo->prox = atual;
            anterior->prox = novoNo;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novoNo;
    return 1;
}


void mergeListas(Lista* inicioUm, Lista* inicioDois, Lista* listaMerge){
    if(inicioUm == NULL){
        return 0;
    }

    if(inicioDois == NULL){
        return 0;
    }

    if(listaMerge == NULL){
        return 0;
    }

    noLista* auxListaUm = *inicioUm;
    noLista* auxListaDois = *inicioDois;

    while(auxListaUm != NULL || auxListaDois != NULL){
        if(auxListaUm != NULL){
            //printf("\nINSERIU DA LISTA UM!!!\n\n");
            inserindoOrdenado(listaMerge, auxListaUm->numero);
        }
        if(auxListaDois != NULL){
            //printf("\nINSERIU DA LISTA DOIS!!!\n\n");
            inserindoOrdenado(listaMerge, auxListaDois->numero);
        }

        auxListaUm = auxListaUm->prox;
        auxListaDois = auxListaDois->prox;
    }
}


int apagarLista(Lista* inicio){
    if(inicio == NULL){
        return 0;
    }
    if((*inicio) == NULL){
        free(inicio);
        return 1;
    }
    noLista *atual = *inicio, *anterior = NULL;


    while(atual != NULL){
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }

    free(inicio);
    return 1;
}

void mostrarLista(Lista* inicio){
    if(inicio == NULL){
        printf("\nEntrou if que inicio nao foi criado\n\n");
        return 0;
    }
    if((*inicio) == NULL){
        printf("\nEntrou if que o conteudo de inicio eh NULL\n\n");
        return 0;
    }
    noLista* aux = *inicio;
    while(aux != NULL){
        printf("%d |", aux->numero);
        aux = aux->prox;
    }
}
