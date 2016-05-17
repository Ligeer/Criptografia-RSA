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
Numprimo * subtrai(Numprimo * a, Numprimo * b);
int primalidade(int n);
void geraSeed();
void geraLista(Numprimo *head, int numeros);
void printLista(Numprimo *head);
void insereLista(Numprimo *head, int num);
Numprimo *soma(Numprimo *head1, Numprimo *head2);

//OPERAÇÕES
//*FALTA COMEÇAR IMPLEMENTAR AS OPERAÇÕES

int main() {
    Numprimo * head1, *head2;

    head1 = criaLista(0); // 0 indica o sinal do numero
    head2 = criaLista(0);

    geraSeed();
    geraLista(head1, 5);
    geraLista(head2, 5);

    printLista(head1);
    printf("\n");
    printLista(head2);
    printf("\n");

    printLista(subtrai(head1, head2));
    return 0;
}


Numprimo *soma(Numprimo *head1, Numprimo *head2) {
    Numprimo *headaux1 = head1->ante;
    Numprimo *headaux2 = head2->ante;
    Numprimo *soma = criaLista(0);
    int total = 0;
    int carry = 0; //ARMAZENA O EXCESSO DA SOMA
    int size1 = 1;
    int i = 0;
    while (headaux1 != head1 || headaux2 != head2) {
        total = headaux1->num+headaux2->num+carry;
        if (total > 10) { //EXEMPLO 24
            carry = total/10; // CARRY RECEBE 2
            total = total%10; // TOTAL RECEBE 4
            insereLista(soma, total); //INSERE NA LISTA RESULTADO O 4
        }
        else if(total == 10) { //SE FOR TOTAL 10 PRECISAMOS TRATAR
            carry = total - 9; //CARRY RECEBE 1
            total = 0; //TOTAL 0
            insereLista(soma, total); //INSERE 0 NA SOMA
        }
        else {
            carry = 0; //ZERA O CARRY PORQUE JÁ FOI ADICIONADO NA SOMA E NAO EXCEDEU 10
            insereLista(soma, total); //INSERE O TOTAL
        }
        if (headaux1 != head1) {
            headaux1 = headaux1->ante;
        }
        if (headaux2 != head2) {
            headaux2 = headaux2->ante;
        }
        i++;
    }
    if(carry != 0) {
        insereLista(soma, carry);
    }
    printf("\n");
    return soma;
}

/* Recebe dois tipos Numprimo e subtrai a - b e retorna */
Numprimo * subtrai(Numprimo * a, Numprimo * b) {
    Numprimo * aux1, * aux2, * c;
    int subtracao;

/* Tratamentos a serem feitos:
    a - 0 = a
    0 - b = -b

    retornar numeros negativos
    sequencias grandes de 0
 */
        aux1 = a->ante; // elemento antes da cabeca = final
        aux2 = b->ante;



        c = criaLista(1);
        while(aux1 != a && aux2 != b) {
            subtracao = 0;
            if(aux1->num - aux2->num < 0) {
                // tenta pedir emprestado um do lado esquerdo
                if(aux1->ante != a) {
                    subtracao = 10; // pega emprestado o algarismo esquerdo
                    aux1->ante->num -= 1; // paga com -1 no algarismo esquerdo
                    subtracao += aux1->num; // valor com o emprestimo
                }
                if(aux2->ante != b) {
                    subtracao -= aux2->num; // subtrai
                }
            } else { // faz a subtracao normal
                subtracao = aux1->num - aux2->num;
            }

            insereLista(c, subtracao);

            if(aux1 != a) {
                aux1 = aux1->ante;
            }
            if(aux2 != b) {
                aux2 = aux2->ante;
            }
        }

    return c;
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

void insereLista(Numprimo *head, int num){
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

void geraLista(Numprimo *head, int numeros) {
    int i;
    i=0;
    while (i != numeros) { // deve ser colocado 256 digitos
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
        printf("%i ", ini->num);
        ini = ini->prox;
        i++;
    }
}

