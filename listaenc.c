#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int nData;
    struct Node *proximo;
};
 
typedef struct Node node; 
//Função pra printar o nó na tela.

void inserirInicio(node *pNode0, node *pNode1){
    pNode0 -> proximo = pNode1;
}

void inserirMeio(node *pNode1, node *pNode5, node *pNode2){
    pNode1 -> proximo = pNode5;
    pNode5 -> proximo = pNode2;
}

void inserirFinal(node *pNode3, node *pNode4){
    pNode3 -> proximo = pNode4;
}

void removerInicio(node *pNode0){
    pNode0 -> proximo = NULL;
}

void removerMeio(node *pNode1, node *pNode2, node *pNode5){
    pNode1 -> proximo = pNode2;
    pNode5 -> proximo = NULL;
}

void removerFinal(node *pNode4){
    pNode4 -> proximo = NULL;
}

void displayLL(node *p)
{
    printf("Mostrando a lista:\n"); 
    if(p){
        do{
            printf(" %d\n", p->nData);
            p=p->proximo;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}
 
 void inverte(node *pNode1, node *pNode2, node *pNode3){
    int c = pNode1-> nData;
    pNode1->nData = pNode3->nData;
    pNode3->nData = c;
}
 
int main(void){
    node *pNode0 = NULL;
    node *pNode1 = NULL;
    node *pNode5 = NULL;
    node *pNode2 = NULL;
    node *pNode3 = NULL;
    node *pNode4 = NULL;
     
    //Criando os nos e associando os dados.

    pNode0 = (node*) malloc(sizeof(node*));
    pNode0 -> nData = 0;

    pNode1 = (node*) malloc(sizeof(node*));
    pNode1->nData = 10;

    pNode5 = (node*) malloc(sizeof(node*));
    pNode5 -> nData = 15;
     
    pNode2 = (node*) malloc(sizeof(node*));
    pNode2->nData = 20;
     
    pNode3 = (node*) malloc(sizeof(node*));
    pNode3->nData = 30;

    pNode4 = (node*) malloc(sizeof(node*));
    pNode4 -> nData = 40;
     
    //Conectando os nós
    inserirInicio(pNode0, pNode1);
    inserirMeio(pNode1, pNode5, pNode2);
    pNode2->proximo = pNode3;
    inserirFinal(pNode3, pNode4);  
    pNode4->proximo = NULL;

    removerInicio(pNode0);
    removerMeio(pNode1, pNode2, pNode5);
    removerFinal(pNode3);  

    inverte(pNode1, pNode2, pNode3);
    //Mostrando a lista.
    if(pNode1)  
        displayLL(pNode1);

  free(pNode0);
  free(pNode1);
  free(pNode5);
  free(pNode2);
  free(pNode3);
  free(pNode4);
  
  return 0;
}