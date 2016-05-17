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
void geraLista(Numprimo *head);
void printLista(Numprimo *head);
void insereLista(Numprimo *head, int num);
bool isNegativo(Numprimo * head);

//OPERAÇÕES
//*FALTA COMEÇAR IMPLEMENTAR AS OPERAÇÕES

int main() {
    Numprimo * head, *head2;

    head = criaLista(1); // 0 indica o sinal do numero
    head2 = criaLista(1);

    geraSeed();
    geraLista(head);
    geraLista(head2);

    printLista(head);
    printf("\n");
    printLista(head2);
    printf("\n");
    printLista(subtrai(head, head2));
    return 0;
}

bool isNegativo(Numprimo * head) {
    return head->num >= 0 ? true : false;
}

Numprimo * soma(Numprimo * a, Numprimo * b) {
    /*colocar funcao  */
    return NULL;
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

void geraLista(Numprimo *head) {
    int i;
    i=0;
    while (i != 20) { // deve ser colocado 256 digitos
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
