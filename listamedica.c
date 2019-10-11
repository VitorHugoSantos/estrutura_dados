#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente{
    char nome[50];
    int id;
    struct Paciente *proximo;
};

typedef struct Paciente paci;

void displayLL(paci *p){

     printf("Lista de pacientes em espera: \n");

     if(p){

         do{

             printf(" %d", p->id);
             p=p->proximo;
        }
        while(p);
        printf("\n");
    }
    else{
        printf("Sem pacientes em espera.");
    }  
}

void inserir_inicio(paci *paci0){
    paci *pacinovo = NULL;
    pacinovo = (paci*) malloc(sizeof(paci*));
    pacinovo->id=0;
    pacinovo->proximo = paci0;
    pacinovo->proximo = NULL;
}

void inserir_meio(paci *anterior, paci *proximo){

}

int main(void){
    paci *paci0 = NULL;
    int choice;
    int continua = 1;

    paci0 = (paci*) malloc(sizeof(paci*));
    paci0->id = 0;

    printf("Bem vindo ao consultório do Dr. Felisbino\n");

    do{
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
            inserir_inicio(paci0);
            printf("\tDigite o nome do paciente: \n");
            char nome[50];
            scanf("%s",&nome[50]);
            strcpy(paci0->nome, nome);
            displayLL(paci0);
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




}
