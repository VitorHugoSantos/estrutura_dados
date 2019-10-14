#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente{
    char nome[50];
    int id;
    struct Paciente *proximo;
};

typedef struct Paciente paci;

void imprime (paci *p) {
   printf("Mostrando a lista:\n"); 
    if(p){
        do{
            printf(" %d\n", p->id);
            p = p -> proximo;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}

void inserir_inicio(paci *paci0){
    paci *pacinovo = NULL;
    pacinovo = (paci*) malloc(sizeof(paci*));
    pacinovo -> id = 0;
    pacinovo -> proximo = paci0;
}

void inserir_meio(paci *anterior, paci *proximo){

}

int main(void){
    int choice;
    int continua = 1;
    char nome[50];

    printf("\tBem vindo ao consultório do Dr. Felisbino\n");
    printf("\t++++++++++++++++++++++++++++++++++++++++++\n");

    do{
        paci *paci0 = NULL;
        paci0 = (paci*) malloc(sizeof(paci*));
        paci0 -> id = 0;
        printf("\t Digite 1 para inserir um paciente\n");
        printf("\t Digite 2 para desistir da consulta\n");
        printf("\t Digite 3 para mostrar a lista de espera\n");

        scanf("%d", &choice);

        if(choice == 1){
            int choi;
            printf("\t Digite 1 para inserir o paciente no inicio\n");
            printf("\t Digite 2 para inserir o paciente no meio\n");
            printf("\t Digite 3 para inserir o paciente no fim\n");
            scanf("%d", &choi);
            if (choi == 1){
                printf("\tDigite o nome do paciente: \n");
                scanf("%s",&nome[50]);
                printf("Tô aq\n");
                inserir_inicio(paci0);
                printf("Tô aq 2 \n");
                strcpy(paci0 -> nome, nome);
                printf("Tô aq 3 \n");
                imprime(paci0);
                printf("Tô aq 4 \n");
            }
        
        }

        if(choice == 2){

        }

        if(choice == 3){

        }
        printf("Digite 1 para continuar e 0 para sair");
        scanf("%d",&continua);
    }  
    while (continua == 1);

return 0;
}