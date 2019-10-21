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

l* crianos(l *nodo0){
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l));
    return novo;
}

l* inserir_inicio(l* nodo0, int i){
    l *novo = crianos(nodo0);
    
    if (nodo0 == NULL){
        nodo0 = novo;
        novo->proximo = NULL;
        novo->id = i;
    }
    else{
        novo->proximo = nodo0;
        novo->id = i;
        nodo0 = novo;

    }
    printf("\n%d", i);
    return nodo0;
}

void imprimir(l* nodo0){
    l *aux = nodo0;
    while(aux != NULL){
        printf("\n%d ",aux->id);
        aux = aux->proximo;
    }
}


int main(){
    l *nodo0 = NULL;
    nodo0 = (l*) malloc(sizeof(l*));
    l *novo=crianos(nodo0);

    int nnos;
    printf("Digite a quntidade de nós");
    scanf("%d", &nnos);
    for(int i = 1; i <= nnos; i++){
        crianos(nodo0);
        inserir_inicio(nodo0,i);
        imprimir(nodo0);
        printf("%d",i);
    } 
    
      return 0;
}
  

