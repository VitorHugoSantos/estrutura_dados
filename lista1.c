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
    struct l *proximo;
};

typedef struct Lista l;

void crianos(l *n, int i){

    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));

    if(i==0){
        n->proximo = novo;
    }

    if(n){
        do{
            n = n->proximo;
        }
        while(n);
    }

    novo->proximo = NULL;
    novo->id = i + 1;

    printf(" %d\n", n->id);
}


int main(){
    l *nodo0 = NULL;
    nodo0 = (l*) malloc(sizeof(l*));
    nodo0->id = 0;

    int nnos;
    printf("Digite a quntidade de nós");
    scanf("%d", &nnos);

    for(int i = 0; i < nnos; i++){
        crianos(nodo0, i);
    } 
}


