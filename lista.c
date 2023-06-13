#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* proximo;
}No;

int main() {
   //Inicia a lista
    No* inicio = (No*)malloc(sizeof(No));
    inicio = NULL;

    // adiciona novos elementos na lista
    No* No1 = (No*)malloc(sizeof(No));
    No1->valor = 10;
    No1->proximo = NULL;
    inicio = No1;

    No* No2 = (No*)malloc(sizeof(No));
    No2->valor = 20;
    No2->proximo = NULL;
    No1->proximo = No2;

    No* No3 = (No*)malloc(sizeof(No));
    No3 ->valor = 30;
    No3 ->proximo = NULL;
    No2 ->proximo = No3;

    No* No4 = (No*)malloc(sizeof(No));
    No4->valor = 40;
    No4->proximo = NULL;
    No3->proximo = No4;

    // Imprimir a lista
    printf("Elementos da lista: ");
    No* noAtual = inicio;
    while (noAtual != NULL) {
        printf("%d ", noAtual->valor);
        noAtual = noAtual->proximo;
    }
    printf("\nimprimi");

    // Liberar a memória alocada
    noAtual = inicio;
    while (noAtual != NULL) {
        No* proximoNo = noAtual->proximo;
        free(noAtual);
        noAtual = proximoNo;
    }

    return 0;
}
