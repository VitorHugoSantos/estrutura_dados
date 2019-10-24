/*
Seja L uma lista simplesmente encadeada composta de números inteiros
cujos nós são l1, l2, l3, ..., ln. Escreva uma programa que,
percorrendo L, uma única vez, construa três outras lista formadas
dos seguintes elementos:
a. l2, l3, ..., ln, l1;
b. ln, ln-1 ,...,l1;
c. l1+ln, l2+ln-1, ..., ln/2+ln/2+1; onde n é par e definido pelo usuário
*/

#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int id;
    struct Lista *proximo;
};

typedef struct Lista l;

l inserir_inicio(l* nodo0, int i){
    l *primeiro = nodo0->proximo;
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    novo->id = i;
    novo->proximo = primeiro;
    nodo0->proximo = novo;  
}

l inserir_fim(l *nodo0, int i){
    l *ultimo = nodo0->proximo;
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    novo->id = i;
    while(ultimo->proximo){
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = NULL;
    novo->proximo = NULL;
    ultimo->proximo = novo;
}


void imprimir(l* nodo0){
    l *aux = nodo0;
    while(aux){
        printf("\n%d ",aux->id);
        aux = aux->proximo;
    }
}


int main(){
    l *nodo0 = NULL;
    nodo0 = (l*) malloc(sizeof(l*));

    int nnos;
    printf("Digite a quntidade de nós ");
    scanf("%d", &nnos);
    for(int i = 1; i <= nnos; i++){
        inserir_fim(nodo0,i);
    }
    imprimir(nodo0); 
    
      return 0;
}