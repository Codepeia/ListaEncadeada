#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
}Lista;

//iniciar a lista
Lista* inicializa(void){
    return NULL;
}
//returna 1 se vazia e 0 se não está vazia;
int vazia(Lista* lista ){
    if(lista == NULL){
        return 1;
    }else{
        return 0;
    }
}

//função de inserção no inicio da lista
Lista* insereInicio(Lista* lista, int i){
    Lista* novo =(Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = lista;
    return novo;
}

Lista* insereFim(Lista* lista, int i){
    Lista* novo =(Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = NULL;

    if(lista == NULL){
        return novo;
    }

    Lista* atual = lista;
    while(atual->prox != NULL){
        atual = atual->prox;
    } 
    atual->prox = novo;
    return lista;
}

void imprime(Lista* lista){
    if(vazia(lista)){
        printf("Lista vazia");
        return;
    }
    Lista* p = lista;
    while(p != NULL){
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL \n");
}
//buscar um elemento na lista
Lista* buscar(Lista* lista, int i){
    Lista* p = lista;
    while(p != NULL){
        if(p->info == i){
            printf("Achou o elemento %d", p->info);
            return p;
        }
    p = p->prox;
    }
    printf("Elemento não encontrado");
    return NULL;

}

//função para remover elemento da lista
Lista* remover(Lista* lista, int i){
    Lista* ant = NULL; //ponteiro para elemento anterior
    Lista* p = lista;//ponteiro para percorrer a lista

    //procurar o elemento na lista , guardando o anterior
    while( p != NULL && p->info != i){
        ant = p;
        p = p->prox;
    }
    //verifica se achou o elemento
    if( p == NULL){
        return lista;//não achou a lista
    }
    //remover o primeiro elemento da lista
    if(ant == NULL){
        lista = p->prox;
    }else{//retirar do meio da lista
        ant->prox = p->prox;
    }
    free(p);
    return lista;
}
main(){
    Lista* lista;

    lista = inicializa();
    lista = insereInicio(lista, 10);
    lista = insereInicio(lista, 20);
    lista = insereInicio(lista, 30);
    lista = insereInicio(lista, 40);

    imprime(lista);
    buscar(lista, 80);

    lista = insereFim(lista, 100);
    imprime(lista);

    lista = remover(lista, 40);

    imprime(lista);

    lista = remover(lista, 10);

     imprime(lista);

    lista = remover(lista, 100);

     imprime(lista);
}