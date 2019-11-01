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

l inserir_inicio(l *nodoA, int i){
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    novo->id = i;
    novo->proximo = nodoA->proximo;
    nodoA->proximo = novo;  
}

l A(l *nodoA){
    l *ultimo = nodoA->proximo;
    l *primeiro = nodoA->proximo;
    nodoA->proximo = primeiro->proximo;
    while(ultimo->proximo){
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = primeiro;
    primeiro->proximo = NULL;
}

l B(l *nodoB, int i){
    l *primeiro = nodoB->proximo;
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    novo->id = i;
    novo->proximo = primeiro;
    nodoB->proximo = novo; 
}


void C(l *nodoC, l *res){
    l *ultimo = nodoC->proximo;
    l *primeiro = nodoC->proximo;
     nodoC->proximo = primeiro->proximo;
    l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    while(ultimo->proximo){
        ultimo = ultimo->proximo;
    }
    novo->id = (primeiro->id + ultimo->id);
    free(primeiro);
    free(ultimo);

    while(ultimo->proximo){
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = NULL;
}
    

    



void copia(l* nodo0, int i){
     l *novo = NULL;
    novo = (l*) malloc(sizeof(l*));
    novo->id = i;
    novo->proximo = nodo0->proximo;
    nodo0->proximo = novo;  
}

void imprimir(l* nodo0){
    l *aux = nodo0;
    aux = aux->proximo;
    while(aux){
        printf("\n%d",aux->id);
        aux = aux->proximo;
    }
    printf("\n");
}


int main(){
    l *nodo0 = NULL;
    nodo0 = (l*) malloc(sizeof(l*));
    l *nodoA = NULL;
    nodoA = (l*) malloc(sizeof(l*));
    l *nodoB = NULL;
    nodoB = (l*) malloc(sizeof(l*));
    l *nodoC = NULL;
    nodoC = (l*) malloc(sizeof(l*));
    l *res = NULL;
    res = (l*) malloc(sizeof(l*));

    int n = 1;

    while(n != 0){
        
        int n;
        int nnos;
        printf("\n Digite a quantidade de nós (Um número par) \n");
        scanf("%d", &nnos);

        if( (nnos%2) == 0){

            for(int i = nnos; i > 0; i--){
                inserir_inicio(nodo0,i);
                inserir_inicio(nodoA,i);
                inserir_inicio(nodoC,i);
            }
            imprimir(nodoA); 

            A(nodoA);
            printf("\n Letra A: \n");
            imprimir(nodoA);

            for(int i = 1; i <= nnos; i++){
                B(nodoB,i);
            }
        
            printf("\n Letra B: \n");
            imprimir(nodoB);

            printf("\n Letra C: \n");
            for(int i = 0; i < nnos; i++){
                C(nodoC,res);
            }
            
            imprimir(res);
        }
        else{
            printf("\n Tu não leu não irmão????? \n");
        }

        printf("\n Digite 0 se desejar sair e 1 para continuar \n");
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        return 0;
    }

}