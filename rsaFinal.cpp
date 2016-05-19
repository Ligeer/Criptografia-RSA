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
int numDigitos(Numprimo * a);
Numprimo *geraPrimoGrande();
Numprimo * criaLista(int valor);
int primalidade(int n);
void geraSeed();
void geraLista(Numprimo *head, int numeros);
void printLista(Numprimo *head);
void insereLista(Numprimo *head, int num);
void pedeEmprestado(Numprimo * a);
Numprimo * soma(Numprimo *head1, Numprimo *head2);
Numprimo * maior(Numprimo * a, Numprimo * b);
Numprimo * subtrai(Numprimo * a, Numprimo * b);


//OPERAÇÕES
//*FALTA COMEÇAR IMPLEMENTAR AS OPERAÇÕES

int main() {
    Numprimo * head1, * head2;

    head1 = criaLista(1); // 0 indica o sinal do numero
    head2 = criaLista(1);

    geraSeed();
    geraLista(head1, 25);
    geraLista(head2, 30);


    printLista(head1);
    printf("\n");
    printLista(head2);
    printf("\n");

    printLista(soma(head1, head2));

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

/* Recebe dois Numprimos e retorna o endereço do maior */
Numprimo * maior(Numprimo * a, Numprimo * b) {
    int x;
    Numprimo * aux1, * aux2;

    //tratamento numeros com sinais opostos
    if((a->num + b->num) == 0) { // se os dois tem sinais diferentes
        return a->num == 1 ? a : b;
    }

    // é maior o que tem mais digitos já que nao armazenamos zeros
    if(numDigitos(a) > numDigitos(b)) {
        return a;
    }
    if(numDigitos(a) < numDigitos(b)) {
        return b;
    }

    x = 0;
    aux1 = a->prox;
    aux2 = b->prox;

    while(x == 0) { // só entra no looping se possui mesma quantidade de digitos
        if(aux1->num > aux2->num) {
            return a;
        }
        if (aux1->num < aux2->num) {
            return b;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
}

/* Recebe um ponteiro para um Numprimo e conta a quantidades de
dígitos doo Numero
 */
int numDigitos(Numprimo * a) {
    Numprimo * aux;
    int i;

    i = 0;
    aux = a->prox;
    while(aux != a) {
        aux = aux->prox;
        i++;
    }
    return i;
}

void deslocaEsq(Numprimo *head) {
    Numprimo *tmp = head->ante;
    Numprimo *novo = (Numprimo*) malloc(sizeof(Numprimo));
    novo->num = 0;
    novo->ante = tmp;
    tmp->prox = novo;
    novo->prox = head; //TROCAR SE NÃO FOR CIRCULAR
}

void deslocaDir(Numprimo *head) {
    Numprimo *tmp = head->ante;
    if (tmp->ante == head) {
        head->ante = NULL;
        head->prox = NULL;
        printf("\n **entrei no null");
    }
    else {
        tmp->ante->prox = head;
        head->ante = tmp->ante;
    }
}

Numprimo *multiplica(Numprimo *head1, Numprimo *head2) {
    Numprimo *total;
    // X = HEAD1 | Y = HEAD2
    printf("\n Debug 1...");
    if(head2->prox == NULL) {
        return criaLista(0);
    }
    printf("\n Retirando:%d...", head2->ante->num);
    deslocaDir(head2); //DIVIDIMOS POR 10
    total = multiplica(head1, head2);
    if(impar(head2) == 0) {
        deslocaEsq(total);//MULTIPLICA POR 10
            printf("\n Debug 4...");
    }
    else {
        deslocaEsq(total); //DESLOQUEI
            printf("\n Debug 5...");
        return soma(head1, total);
    }
}

Resultado *divide(Numprimo *head1, Numprimo *head2) {
    Numprimo *aux1 = head1->ante;
    Numprimo *aux2 = head2->ante;
    Numprimo *q;
    Numprimo *r;
    Resultado *result;

    printf("\n DBG 1...");
    if (head1->prox == NULL) {
        //TRANSFORMANDO Q E R NA REPRESENTACAO DE 0 NOSSA
        printf("\n DBG 44...");
        //DEVOLVENDO UM PONTEIRO Q E R QUE SEJAM 0
        q = criaLista(0);
        r = criaLista(0);

        result = (Resultado*) malloc(sizeof(Resultado));
        result->value1 = q;
        result->value2 = r;

        printf("\n DBG 45...");
        return result;
    }
    /*DEBUGANDO*/
    printf("\n DBG 2...");
    //printf("\n");
   // printLista(head1);
    //printf("\n");
   // printLista(head2);
    /*DEBUGANDO*/
    printf("\n Sendo retirado:%d", head1->ante->num);
    deslocaDir(head1); //dividindo por 10
    aux1 = aux1->ante;
    result = divide(head1, head2);
    printf("\n DBG 7...");
    deslocaEsq(q);
    deslocaEsq(r);
    printf("\n DBG 3...");
    if(impar(head1) == 1) {
        r->ante->num = r->ante->num+1;
    }
    int size1 = numDigitos(r);
    int size2 = numDigitos(head2);
        printf("\n DBG 4...");
    if(maior(r, head2) == r || size1 == size2) {
        r->ante->num = r->ante->num-1;
        subtrai(r, head2);
            printf("\n DBG 5...");
    }
    result->value1 = q;
    result->value2 = r;
    return result;
}

Numprimo *copiaNum(Numprimo *head){
    Numprimo *aux = head->ante;
    Numprimo *novo = criaLista(0);
    while(aux != head) {
        insereLista(novo, aux->num);
        aux = aux->ante;
    }
    return novo;
}

int impar(Numprimo *head) {
    Numprimo *copia = copiaNum(head);
    Numprimo *aux = copia->ante;
    while(aux != copia){
        printf("\n %d/2 sobra %d", aux->num, aux->num%2);
        if(aux->num%2 != 0) {
            return 1; //RETORNA IMPAR
        }
        aux = aux->ante;
    }
    return 0; //RETORNA PAR
}

Numprimo * subtrai(Numprimo * a, Numprimo * b) {
    Numprimo * aux1, * aux2, * empresta, * c;
    int subtracao;

    // se b > a entao o algoritmo nao funciona, entao mudamos
    // o sinal do número e chamamos a funcao com os argumentos invertidos
    if(maior(a, b) == b) {
        c = subtrai(b, a);
        c->num *= -1; // negativa o resultado, já que b > a
        return c;
    }

    aux1 = a->ante; // elemento antes da cabeca = final
    aux2 = b->ante;
    c = criaLista(1);

    while(aux1 != a || aux2 != b) {
        subtracao = 0;

        if(aux1->num - aux2->num < 0) {
            pedeEmprestado(aux1); // pedimos emprestado para os dígitos anteriores
            subtracao = 10 + aux1->num - aux2->num ; // subtração feita com o empréstimo
        } else {
            subtracao = aux1->num - aux2->num; // não precisa fazer o empréstimo, subtração normal
        }
        insereLista(c, subtracao); // insere na lista o valor subtraido

        // os dois ponteiros percorrerão para a esquerda até encontrar a cabeça da lista
        if(aux1 != a) {
            aux1 = aux1->ante;
        }
        if(aux2 != b) {
            aux2 = aux2->ante;
        }

    }

    //agora uma das duas listas chegou na cabeça, a operação é só o próprio número
    while(aux1 != a) {
        insereLista(c, aux1->num);
        aux1 = aux1->ante;
    }

    while(aux2 != b) {
        insereLista(c, aux2->num);
        aux2 = aux2->ante;
    }
    return c;
}

/* Função utilizada na subtracao de um Numprimo
pede emprestado um numero de uma casa, balanceando o valor
na casa anterior
 */
void pedeEmprestado(Numprimo * a) {
    if((a->ante->num) == 0) {
        a->ante->num = 9;
        pedeEmprestado(a->ante);
    } else {
        a->ante->num -= 1;
    }
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

    if(head->num == -1) {
        printf("- ");
    }

    while(ini != head){
        printf("%i ", ini->num);
        ini = ini->prox;
        i++;
    }
}

