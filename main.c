#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define TAM_VET 5

int main()
{
    int vet_numeros_lista_um[TAM_VET] = {9,0,2,3,10};
    int vet_numeros_lista_dois[TAM_VET] = {7,4,6,5,1};

    int i;

    Lista* cabecaListaUm = criarLista();
    Lista* cabecaListaDois = criarLista();
    Lista* cabecaListaMergida = criarLista();

    //INSERINDO LISTA UM ORDENADO
    for(i = 0; i<TAM_VET; i++){
        inserindoOrdenado(cabecaListaUm, vet_numeros_lista_um[i]);
    }

    //INSERINDO LISTA DOIS ORDENADO
    for(i = 0; i<TAM_VET; i++){
        inserindoOrdenado(cabecaListaDois, vet_numeros_lista_dois[i]);
    }

    //MOSTRANDO LISTAS ORDENADAS
    printf("\nLista UM: ");
    mostrarLista(cabecaListaUm);

    printf("\nLista Dois: ");
    mostrarLista(cabecaListaDois);

    //DAR MERGE NAS LISTAS
    mergeListas(cabecaListaUm, cabecaListaDois, cabecaListaMergida);

    printf("\nLista Mergida: ");
    mostrarLista(cabecaListaMergida);




    //APAGANDO LISTAS COMPLETAS
    apagarLista(cabecaListaUm);
    apagarLista(cabecaListaDois);
    apagarLista(cabecaListaMergida);


    printf("\n\n\n");

    return 0;
}
