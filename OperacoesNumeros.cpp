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

struct resultado {
    struct numPrimo *value1;
    struct numPrimo *value2;
};

typedef struct numPrimo Numprimo;
typedef struct resultado Resultado;

//FUNÇÕES
int geraNumeroMax(int n);
int numDigitos(Numprimo * a);
int primalidade(int n);
int deslocaEsquerda(Numprimo * a);
int ePar(Numprimo * a);
Numprimo *geraPrimoGrande();
Numprimo * criaLista(int valor);
Numprimo * copia(Numprimo * a);
void geraSeed();
void geraLista(Numprimo *head, int numeros);
void printLista(Numprimo *head);
void insereLista(Numprimo *head, int num);
void pedeEmprestado(Numprimo * a);
void deslocaDireita(Numprimo * a);
void insereZeros(Numprimo *head, int n, int digito);
int numMaior(Numprimo *head1, Numprimo *head2);
void limpaZero(Numprimo *head);
Numprimo *copiaNum(Numprimo *head);
int numIgual(Numprimo *head1, Numprimo *head2);
void removeNumero(Numprimo * vitima);
void desalocaLista(Numprimo * lst);

//OPERAÇÕES
Numprimo * soma(Numprimo *head1, Numprimo *head2);
Numprimo * maior(Numprimo * a, Numprimo * b);
Numprimo * subtrai(Numprimo * a, Numprimo * b);
Numprimo * multiplica(Numprimo *head1, Numprimo *head2);
Numprimo * multiplica2(Numprimo *head1, Numprimo *head2);
Numprimo * exponenciacao(Numprimo * a, Numprimo * b);
Resultado *divide(Numprimo *head1, Numprimo *head2);

int main() {
    Numprimo * head1, * head2, * head3, *aux;
    int i, escolha;
    Resultado * result;

    head1 = criaLista(1); // 0 indica o sinal do numero
    head2 = criaLista(1);
    head3 = criaLista(1);

    geraSeed();

    insereLista(head1, 2);
    insereLista(head1, 3);
    insereLista(head1, 7);
    insereLista(head1, 4);
    insereLista(head1, 2);
    insereLista(head1, 5);
    insereLista(head1, 3);

    insereLista(head2, 2);
    insereLista(head2, 3);
    insereLista(head2, 7);
    insereLista(head2, 4);

    insereLista(head3, 4);
    insereLista(head3, 3);

    geraLista(head1, 7);
    geraLista(head2, 4);
    geraLista(head2, 2);

    printLista(head1);
    printf("\n\n\n\n");
    printLista(head2);
    printf("\n\n\n\n");
    printLista(head3);
    printf("\n\n\n\n");

    printf("Digite:\n1- Soma\n2- Subtracao\n3- Multiplicacao\n4- Divisao");
    scanf("%i", &escolha);

    switch(escolha) {
        case 1:
            printf("\n\n A + B \n");
            printLista(soma(copia(head1), copia(head2) ) );
            break;
        case 2:
            printf("\n\n A - B \n");
            printLista(subtrai(copia(head1), copia(head2) ) );
            break;
        case 3:
            printf("\n\n A * B \n");
            printLista(multiplica(copia(head1), copia(head2) ) );
            break;
        case 4:
            printf("\n\n A / B \n");
            result = divide(copia(head1), copia(head2));
            printf("\nQuociente:\n");
            printLista(result->value1);
            printf("\nResto:\n");
            printLista(result->value2);
            break;
        default:
            break;
    }
    return 0;
}

Resultado *  divide(Numprimo * a, Numprimo * b) {
    Numprimo * aux, * aux2;
    Resultado * result, * result2;
    int resto, i;

    if(a->prox->num == 0) { // se b = 0
        result = (Resultado *) malloc(sizeof(result));

        result->value1 = criaLista(1);
        insereLista(result->value1, 0);

        result->value2 = criaLista(1);
        insereLista(result->value2, 0);
        return result;
    } else {
        resto = deslocaEsquerda(a);
        result = divide(a, b);

        deslocaDireita(result->value1);
        deslocaDireita(result->value2);

        aux2 = criaLista(1);
        insereLista(aux2, resto);
        result->value2 = soma(aux2, result->value2);


        aux = criaLista(1);
        insereLista(aux, 1);

        aux->prox->num = 1;

        for(i = 1; i <= 10; i++) {

            aux->prox->num = i;
            aux2->prox->num = i - 1;

            if(! (maior(result->value2, multiplica(aux, b)) == result->value2)) {
                if(i == 1)  {
                    return result;
                }

                result->value1 = soma(result->value1, aux2); // q' + aux

                // aux * b - r'
                result->value2 = subtrai(result->value2, multiplica(aux2, b));
                return result;
            }
        }
        aux2->prox->num += 1;
        result->value1 = soma(result->value1, aux2);
        result->value2 = subtrai(result->value2, multiplica(aux2, b));
        return result;
    }
}

// recebe n = quantia de zeros, digito = valor total da mult de n1*n2
// @TODO: poder reaproveitar parte da funcao deslocaDireita que faz a mesma coisa só que uma vez
void insereZeros(Numprimo *head, int n, int digito) {
    int auxNum;
    while(n != 0) { //Inserindo primeiros todos os 0
        insereLista(head, 0);
        n--;
    }
    //Variavel digito sempre tera 2 casas decimais apenas
    auxNum = digito%10;
    digito = (digito - auxNum)/10;
    insereLista(head, auxNum);
    insereLista(head, digito);
}

// Pode dale que o algoritmo tá zika agora
Numprimo * exponenciacao(Numprimo * a, Numprimo * b) {
    Numprimo * c, * aux, * um;
    Numprimo *tmp = copiaNum(a);

    if(numDigitos(b) == 1) {
        switch(b->prox->num) {
            case 0: // retorna um
                c = criaLista(1);
                insereLista(c, 1);
                return c;
            case 1: // retorna uma cópia do próprio a
                return tmp;
            case 2: // retorna multiplica(a, a);
                return multiplica(a, tmp);
        }
    }

    c = multiplica(a, tmp);

    um = criaLista(1);  // o valor desse com o de um auxiliar precisa uma hora ser igual ao expoente
    insereLista(um, 1); // um representa uma lista com o valor igual a 1

    aux = criaLista(1);
    insereLista(aux, 2); // ja fizemos a * a = duas vezes a^2, entao devemos 2

    while(aux->prox->num != b->prox->num) { // quando os expoente auxiliar for igual o expoente real, temos o resultado das multiplicacoes
        c = multiplica(a, c);
        aux = soma(aux, um);
    }
    return c;
}

//Depende da funcao insereZeros
Numprimo *multiplica(Numprimo *head1, Numprimo *head2) {
    Numprimo *aux1 = head1->ante;
    Numprimo *aux2 = head2->ante;
    Numprimo *result = criaLista(1); //recebe o valor da soma total
    Numprimo *tmp = criaLista(1); // recebe num1*num2..seguido de zeros
    Numprimo *exclude;
    int total = 0;
    int qntZeros1 = 0; //CONTANDO A QUANTIA DE ZEROS PARA A SOMA
    int qntZeros2 = 0; //CONTANDO A QUANTIA DE ZEROS PARA A SOMA
    while(aux2 != head2) {
        aux1 = head1->ante; //voltando sempre pro final
        while(aux1 != head1) {
            total = aux2->num*aux1->num;
            tmp = criaLista(1); //Precisa sempre ser renovada
            insereZeros(tmp, qntZeros1+qntZeros2, total); //A multiplicacao recebe uma quantia de zeros = zero1+zero2
            if(result != result->prox) { // SE RESULTE NÃO ESTIVER VAZIA
                result = soma(result, tmp); //Soma vai ser incrementado sempre
            }
            else {
                result = tmp; //Se nao o result sera apenas a primeira multiplicacao
            }
            qntZeros1++;
            aux1 = aux1->ante;
        }
        aux2 = aux2->ante;
        total = 0; //zerando o total
        qntZeros1 = 0; //apenas o qntzeros do numero 1 precisa ser limpo
        qntZeros2++;
    }
    if(result->prox->num == 0) { //Apagando o zero que aparece de vez em quando
        exclude = result->prox;
        result->prox = exclude->prox;
        free(exclude); //liberando a memoria que estava alocada pra aquela celular
    }
    return result;
}

// Recebe um Numprimo e retorna verdadeiro se se o resto da divisao por 2 é zero do último dígito
int ePar(Numprimo * a) {
    return a->ante->num  % 2 == 0 ? 1 : 0;
}

// Recebe um Numprimo a e retorna Numprimo igual com outro endereço
Numprimo * copia(Numprimo * a) {

    Numprimo * nova, * aux;

    aux = a->ante;
    nova = criaLista(a->num); // cria nova cabeça igual a cabeça de a

    while(aux != a) { // percorre do final até o começo
        insereLista(nova, aux->num);
        aux = aux->ante;
    }
    return aux; // devolve a cabeça do numero copiado
}

// Desloca um digito para a esquerda do número, divisão inteira por 10
int deslocaEsquerda(Numprimo * a) {
    Numprimo * aux;
    int numero;

    numero = a->ante->num;

    if(a->prox != a) { // fica  a critério deixar o número 0 ou somente a cabeça para representar um numero vazio
        aux = a->ante;
        aux->ante->prox = a;
        a->ante = aux->ante;
        free(aux);
    }
    if(a->prox == a) {
        insereLista(a, 0);

    }
    return numero;
}



// Desloca um digito para a direita do número, multiplicação por 10
void deslocaDireita(Numprimo * a) {
    if(a->prox->num != 0) { // se o número já é 0 nao adianta tentar colocar outro na frente
        insereLista(a->ante, 0); // finge que o elemento anterior a cabeça é a cabeça e faz a inserção nela
    }
}

Numprimo * soma(Numprimo *head1, Numprimo *head2) {
    Numprimo *headaux1 = head1->ante;
    Numprimo *headaux2 = head2->ante;
    Numprimo *soma = criaLista(1);
    int total = 0;
    int carry = 0; //ARMAZENA O EXCESSO DA SOMA
    int i = 0;
    while (headaux1 != head1 || headaux2 != head2) {

        if(headaux1 != head1 && headaux2 != head2) {
            total = headaux1->num + headaux2->num +carry;
        } else if (headaux1 == head1) {
            total = headaux2->num + carry;
        } else if (headaux2 == head2) {
            total = headaux1->num + carry;
        }


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
    }
    if(carry != 0) {
        insereLista(soma, carry);
    }

    return soma;
}

/* Recebe dois Numprimos e retorna o endereço do maior */
Numprimo * maior(Numprimo * a, Numprimo * b) {
    Numprimo * aux1, * aux2;

    //tratamento numeros com sinais opostos
    if((a->num + b->num) == 0) { // se os dois tem sinais diferentes
        return a->num == 1 ? a : b;
    }

    // é maior o que tem mais digitos já que nao armazenamos zeros

    // tratar se ambos forem negativos
    if(numDigitos(a) > numDigitos(b)) {
        return a;
    }
    if(numDigitos(a) < numDigitos(b)) {
        return b;
    }

    aux1 = a->prox;
    aux2 = b->prox;

    while(aux1->prox != a) { // só entra no looping se possui mesma quantidade de digitos
        if(aux1->num > aux2->num) {
            return a;
        }
        if (aux1->num < aux2->num) {
            return b;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return a;
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

Numprimo * subtrai(Numprimo * a, Numprimo * b) {
    Numprimo * aux1, * aux2, * c;
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
    limpaZero(c); //Estava gerando zeros ao começo do numero na saida
    return c;
}

//Limpa zero do inicio da subtração
void limpaZero(Numprimo *head) {
    Numprimo *exclude;
    while(head->prox->num == 0) {
        exclude = head->prox;
        head->prox = exclude->prox;
        exclude->prox->ante = head;
        free(exclude);
    }
}

//Recebe um numero e devolve um ponteiro novo alocado de uma copia identica
Numprimo *copiaNum(Numprimo *head) {
    Numprimo *aux = head->ante;
    Numprimo *copia = criaLista(0);
    while(aux != head){
        insereLista(copia, aux->num);
        aux = aux->ante;
    }
    return copia;
}


//Função otimizada para comparar se o numero é maior comparando digito a digito
int numMaior(Numprimo *head1, Numprimo *head2) {
    //Numero 1 é maior que 2 somente se todos digitos de 1 é maior que 2
    Numprimo *aux1 = head1->prox;
    Numprimo *aux2 = head2->prox;
    if(numDigitos(head1) > numDigitos(head2)) {
        return 1;
    }
    if(numDigitos(head1) == numDigitos(head2)){
        while(aux1 != head1) {
            if(aux1->num < aux2->num){
                return 0;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        return 1;
    }
    else{
        return 0;
    }
}

//Verifica se os numeros sao exatamente iguais
int numIgual(Numprimo *head1, Numprimo *head2){
    Numprimo *aux1 = head1->prox;
    Numprimo *aux2 = head2->prox;
    if(numDigitos(head1) != numDigitos(head2)){ //garantindo que a quantia de digito é igual
        return 0;
    }
    while(aux1 != head1) {
        if(aux1->num != aux2->num) {
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return 1;
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

void desalocaLista(Numprimo * lst) { // remove todos os elementos da lista
    while(numDigitos(lst) != 0) { // enquanto a quantidade de digitos for diferente de zero ainda temos coisa para remover
        removeNumero(lst); // remove o elemento indicado
    }
}

void removeNumero(Numprimo * vitima) { // desaloca a memória da célula indicada
    Numprimo * aux;

    if(vitima->prox == vitima) { // se a celula for a cabeça
        free(vitima); // desaloca vitima
    } else { // removemos um membro da lista duplamente encadeada
        aux = vitima->ante;
        aux->ante->prox = vitima;
        vitima->ante = aux->ante;
        free(aux); // desaloca aux
    }
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