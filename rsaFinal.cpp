#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct numPrimo {
    int num;
    struct numPrimo *prox;
    struct numPrimo *ante;
};

typedef struct numPrimo Numprimo;

//FUNÇÕES
int geraNumeroMax(int n);
Numprimo *geraPrimoGrande();
Numprimo * criaLista(int valor);
int primalidade(int n);
void geraSeed();
void geraLista(Numprimo *head);
void printLista(Numprimo *head);

//OPERAÇÕES
//*FALTA COMEÇAR IMPLEMENTAR AS OPERAÇÕES

int main() {
    Numprimo * head;

    head = criaLista(0); // 0 indica o sinal do numero

    geraSeed();
    geraLista(head);
    printLista(head);

    return 0;
}

int geraNumeroMax(int n){
    return rand() % n + 1;
}

void geraSeed() { /* gera uma seed para nova sequencia de numeros aleatorios */
    srand((unsigned)time(NULL));
}

Numprimo * criaLista(int valor) {
    Numprimo * head;
    head = (Numprimo *) malloc(sizeof(Numprimo));
    head->num = valor;
    head->prox = head;
    return head;
}

void insereLista (Numprimo *head, int num){
    Numprimo *novo;
    novo = (Numprimo*) malloc(sizeof(Numprimo));
    novo->num = num; //acessa nova e bota o endereço da pessoa1 lá dentro;

    if(head->prox == head) {
        novo->prox = head;
        head->prox = novo;
        novo->ante = head;
        head->ante = novo;
        return;
    }
    novo->prox = head->prox;
    head->prox = novo;
    novo->prox->ante = novo;
    novo->ante = head;
}

void geraLista(Numprimo *head) {
    int i;
    i=0;
    while (i != 10) { // deve ser colocado 256 digitos
        insereLista(head, geraNumeroMax(9)); //GERANDO NUMEROS DE 1-9 E GUARDANDO NA LISTA
        i++;
    }
}

void printLista(Numprimo *head){
    int i;
    Numprimo *ini;

    ini = head->prox;
    i=0;
    while(ini != head){
        printf("Indice: %d |Num: %d \n", i, ini->num);
        ini = ini->prox;
        printf("____________\n");
        i++;
    }
}



int primalidade(int n){
    int b = n-1;
    int i = 0;
    int a = 0;
    int result;
    while(i <= 100){ /*Rodando 100 vezes para diminuir em 1/2*100 a chance de erro*/
        a = geraNumeroMax(n-1); /*Gerando numero entre 1 e n-1*/
        //result = expModular(a, b, n);
        if (result != 1 % n){ /*Verificando inverso multiplicativo*/
            return 0;
        }
        i++;
    }
    return 1;
}
