/**
*** Universidade Federal de Santa Catarina
*** Exercício programa da disciplina de Análise e Projeto de Algoritmos 2016/1
*** Alunos: Ale Chaito (14205353) Christian Roger Gaio (14202477) e Luan Rodrigues Silva (14209239)
*** Professor: Álvaro Pereira Franco Junio


    Esquema de Criptografia RSA

        Esta lista de exercícios trata de números inteiros na base 10 com muitos dígitos
            (digamos 500 dígitos). Você pode escolher a estrutura de dados que quiser
            para armazenar cada dígito de um número. Lembre que um número inteiro pode
            ser negativo e assim, este caso deve ser tratado.

        Aritmética básica:
            - Soma
            - Subtração
            - Multiplicação
            - Exponenciação
            - Divisão

        Aritmética modular:
            - Soma modular
            - Subtração modular
            - Multiplicação modular
            - Exponenciação modular
            - Divisão modular

        Criptografia RSA:
            - Implemente um algoritmo probabilístico que testa a primalidade de um número
            inteiro, e erra com probabilidade 1/2^k, com k >= 1
            - Implemente um algoritmo que gera números primos com n dígitos (n <= 200).
            o tempo de execução médio desse algorítmo deve ser O(n^4).
            - Implemente o esquema de criptografia RSA. Você precisa gerar uma única vez
            as chaves pública e privada. A partir daí um texto qualquer deve ser criptografado
            através do esquema RSA. Para a correção deste exercício, além da implementação,
            divulguem as chaves pública e privadas geradas.



    Descrição dos tipos de dados:

        Numprimo - essa estrutura armazena um numero inteiro que equivale a um dígito ou o sinal
        do número, possui um ponteiro que aponta para uma struct anterior e outro para o próximo.

        Resultado - possui dois ponteiros para Numprimo, um representa o quociente de uma divisão
        e o outro representa o resto.


    Descrição das funções:

        int geraNumeroMax(int n)
            - A função gera um algaristmo aleatório para ser inserido na lista.
        int numDigitos(Numprimo * a)
            - A função que recebe um endereço para uma lista, conta a quantidade de dígitos e retorna este valor.
        int primalidade(int n)
            - A função recebe um número e verifica se ele é primo.
        int deslocaEsquerda(Numprimo * a)
            - Função que recebe um endereço de uma cabeça de lista como parâmetro e desloca um dígito para a esquerda equivalente a uma divisão por dez.
        int ePar(Numprimo * a)
            - A função que recebe um endereço de lista verifica se o conteúdo desta é par.
        void geraSeed()
            - A função cria uma seed para gerar número aleatório.
        void geraLista(Numprimo *head, int numeros)
            - A função recebe um endereço de cabeça de lista e os números para inserir nesta lista.
        void printLista(Numprimo *head)
            - A função que recebe um endereço de cabeça de uma lista e escreve o seu conteúdo.
        void insereLista(Numprimo *head, int num)
            - A função que recebe um endereço de cabeça de lista e um número, inserindo-o na lista.
        void pedeEmprestado(Numprimo * a)
            - Função utilizada na subtracao pede emprestado um numero de uma casa, balanceando o valor na casa anterior.
        void deslocaDireita(Numprimo * a)
            - Função que recece um endereço de lista como parâmetro e se o número for diferente de zero, adiciona um digito zero no final do número.
        int numMaior(Numprimo *head1, Numprimo *head2)
            - Função que recebe dois endereços de cabeças de listas e retorna a que contém maior valor.
        void limpaZero(Numprimo *head)
            - A função que recebe o endereço da cabeça de uma lista e limpa os zeros da subtração.
        int numIgual(Numprimo *head1, Numprimo *head2)
            - A função que recebe o endereço para duas cabeças de listas e compara dígito a dígito se eles são iguais
        void removeNumero(Numprimo * vitima)
            - A função que recebe um endereço para um número e deleta-o.
        void desalocaLista(Numprimo * lst)
            - A função que recebe um endereço para uma lista e desaloca esta.
        Numprimo * criaLista(int valor)
            - A função cria uma lista.
        Numprimo *copiaNum(Numprimo *head)
            - A função que recebe um endereço de cabeça de lista e copia este conteúdo numa nova lista.
        Numprimo *geraPrimoGrande()
            - A função gera um número primo grande.
        Numprimo * copia(Numprimo * a)
            - A função que recebe um endereço de uma lista e retorna o mesmo conteúdo num novo endereço.


        Numprimo * soma(Numprimo *head1, Numprimo *head2)
            - A função que recebe dois endereços para cabeças de listas retorna a soma do conteúdo dessas listas.
        Numprimo * maior(Numprimo * a, Numprimo * b)
            - A função que recebe dois endereços de listas e retorna a que possui maior valor.
        Numprimo * subtrai(Numprimo * a, Numprimo * b)
            - A função que recebe dois endereços de listas e retorna a subtração entre os seus valores.
        Numprimo * multiplica(Numprimo *head1, Numprimo *head2)
            - A função que recebe dois endereços de cabeças de listas e retorna o valor da multiplicação dos seus conteúdos.
        Numprimo * exponenciacao(Numprimo * a, Numprimo * b)
            - A função que recebe dois endereços de listas
        Resultado *divide(Numprimo *head1, Numprimo *head2)
            - A função que recebe dois endereços para cabeças de listas e retorna a divisão entre eles.
*/
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct digito {
    int num;
    struct digito * prox;
    struct digito * ante;
};

struct divisao {
    struct digito * q;
    struct digito * r;
};

typedef struct digito Numero;
typedef struct divisao Divisao;

//FUNÇÕES
int geraNumeroMax(int n);
int numDigitos(Numero * a);
int primalidade(int n);
int deslocaEsquerda(Numero * a);
int ePar(Numero * a);
Numero * geraPrimoGrande();
Numero * criaLista(int valor);
Numero * copia(Numero * a);
void geraSeed();
void geraLista(Numero *head, int numeros);
void printLista(Numero *head);
void insereLista(Numero *head, int num);
void pedeEmprestado(Numero * a);
void deslocaDireita(Numero * a);
void insereZeros(Numero *head, int n, int digito);
void limpaZero(Numero *head);
void removeNumero(Numero * vitima);
void desalocaLista(Numero * lst);
void printMultiplicacoes(int digitos);
int numIgual(Numero *head1, Numero *head2);
int numMaior(Numero *head1, Numero *head2);
Numero * copiaNum(Numero *head);

//OPERAÇÕES
Numero * soma(Numero *head1, Numero *head2);
Numero * maior(Numero * a, Numero * b);
Numero * subtrai(Numero * a, Numero * b);
Numero * multiplica(Numero *head1, Numero *head2);
Numero * exponenciacao(Numero * a, Numero * b);
Divisao *divide(Numero *head1, Numero *head2);

// OPERAÇÕES MODULARES
Numero * somaModular(Numero * a, Numero * b, Numero * n);
Numero * subtracaoModular(Numero * a, Numero * b, Numero * n);


int main() {
    // Teste do multiplica recursivo, consegue fazer multiplicacoes de 600 digitos em poucos segundos
    int digitos;
    Numero * head1, * head2, * rst;


    geraSeed();

    printf("Digite a quantidade de digitos dos dois numeros para fazer a multiplicacao\n");
    scanf("%i", &digitos);

    head1 = criaLista(1); // 0 indica o sinal do numero
    head2 = criaLista(1);
    printf("Gerando numeros... \n\n");

    geraLista(head1, digitos);
    geraLista(head2, digitos);

    printLista(head1);
    printf("\n");
    printLista(head2);
    printf("\n");

    rst = multiplica(copia(head1), copia(head2) );
    printLista(rst);

    printf("\n\n\n");
    desalocaLista(head1);
    desalocaLista(head2);
    desalocaLista(rst);

    return 0;
}

Numero * somaModular(Numero * a, Numero * b, Numero * n) {
    Numero * aux;
    Divisao * rst;

    aux = copia(soma(a, b));
    rst = divide(aux, n);

    return rst->r; // retorna soma(a, b) mod n
}

Numero * subtracaoModular(Numero * a, Numero * b, Numero * n) {
    Numero * aux;
    Divisao * rst;

    aux = subtrai(a, b);
    rst = divide(aux, n);
    return rst->r; // retorna soma(a, b) mod n
}

//q = q
//r = r
Divisao *  divide(Numero * a, Numero * b) {
    Numero * aux, * aux2;
    Divisao * result;
    int resto, i;


    if(a->prox->num == 0) { // se b = 0
        result = (Divisao *) malloc(sizeof(result));

        result->q = criaLista(1);
        insereLista(result->q, 0);

        result->r = criaLista(1);
        insereLista(result->r, 0);
        return result;
    } else {
        resto = deslocaEsquerda(a);
        result = divide(a, b);

        deslocaDireita(result->q);
        deslocaDireita(result->r);

        aux2 = criaLista(1);
        insereLista(aux2, resto);
        result->r = soma(aux2, result->r);


/*
        result2 = divide(result->r, b);
        result->q = soma(result->q, result2->q);
        result->r = copia(result2->r);
        return result;
*/

        aux = criaLista(1);
        insereLista(aux, 1);

        aux->prox->num = 1;

        for(i = 1; i <= 10; i++) {
            aux->prox->num = i;
            aux2->prox->num = i - 1;

            if(! (maior(result->r, multiplica(aux, b)) == result->r)) {
                if(i == 1)  {
                    return result;
                }

                result->q = soma(result->q, aux2); // q' + aux

                // aux * b - r'
                result->r = subtrai(result->r, multiplica(aux2, b));
                return result;
            }
        }
        aux2->prox->num += 1;
        result->q = soma(result->q, aux2);
        result->r = subtrai(result->r, multiplica(copia(aux2), copia(b)));
        return result;
    }
}

Numero * multiplica(Numero * a, Numero * b) {
    Numero * c, * aux;
    int resto, i;

    aux = criaLista(1);

    if(numDigitos(b) == 1) {
        switch(b->prox->num) {
            case 0:
                c = criaLista(1);
                insereLista(c, 0);
                break;
            case 1:
                c = copia(a);
                break;
            case 2:
                c = soma(copia(a), copia(a));
                break;
            default:
                c = soma(copia(a), copia(a));
                for(i = 2; i < b->prox->num; i++) {
                    c = soma(copia(c), copia(a));
                }
                break;
        }
        return c;
    }


    resto = deslocaEsquerda(b);
    c = multiplica(a, b);

    insereLista(aux, resto);
    deslocaDireita(c);

    return soma(c, multiplica(a, aux));
}

// recebe n = quantia de zeros, digito = valor total da mult de n1*n2
// @TODO: poder reaproveitar parte da funcao deslocaDireita que faz a mesma coisa só que uma vez
void insereZeros(Numero *head, int n, int digito) {
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
Numero * exponenciacao(Numero * a, Numero * b) {
    Numero * c, * aux, * um;
    Numero *tmp = copiaNum(a);

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

// Recebe um Numero e retorna verdadeiro se se o resto da divisao por 2 é zero do último dígito
int ePar(Numero * a) {
    return a->ante->num  % 2 == 0 ? 1 : 0;
}

// Recebe um Numero a e retorna Numero igual com outro endereço
Numero * copia(Numero * a) {

    Numero * nova, * aux;

    aux = a->ante;
    nova = criaLista(a->num); // cria nova cabeça igual a cabeça de a

    while(aux != a) { // percorre do final até o começo
        insereLista(nova, aux->num);
        aux = aux->ante;
    }
    return aux; // devolve a cabeça do numero copiado
}

// Desloca um digito para a esquerda do número, divisão inteira por 10
int deslocaEsquerda(Numero * a) {
    Numero * aux;
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
void deslocaDireita(Numero * a) {
    if(a->prox->num != 0) { // se o número já é 0 nao adianta tentar colocar outro na frente
        insereLista(a->ante, 0); // finge que o elemento anterior a cabeça é a cabeça e faz a inserção nela
    }
}

Numero * soma(Numero *head1, Numero *head2) {
    Numero *headaux1 = head1->ante;
    Numero *headaux2 = head2->ante;
    Numero *soma = criaLista(1);
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
Numero * maior(Numero * a, Numero * b) {
    Numero * aux1, * aux2;

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

/* Recebe um ponteiro para um Numero e conta a quantidades de
dígitos doo Numero
 */
int numDigitos(Numero * a) {
    Numero * aux;
    int i;

    i = 0;
    aux = a->prox;
    while(aux != a) {
        aux = aux->prox;
        i++;
    }
    return i;
}

Numero * subtrai(Numero * a, Numero * b) {
    Numero * aux1, * aux2, * c;
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
void limpaZero(Numero *head) {
    Numero *exclude;
    while(head->prox->num == 0) {
        exclude = head->prox;
        head->prox = exclude->prox;
        exclude->prox->ante = head;
        free(exclude);
    }
}

//Recebe um numero e devolve um ponteiro novo alocado de uma copia identica
Numero *copiaNum(Numero *head) {
    Numero *aux = head->ante;
    Numero *copia = criaLista(0);
    while(aux != head){
        insereLista(copia, aux->num);
        aux = aux->ante;
    }
    return copia;
}


//Função otimizada para comparar se o numero é maior comparando digito a digito
int numMaior(Numero *head1, Numero *head2) {
    //Numero 1 é maior que 2 somente se todos digitos de 1 é maior que 2
    Numero *aux1 = head1->prox;
    Numero *aux2 = head2->prox;
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
int numIgual(Numero *head1, Numero *head2){
    Numero *aux1 = head1->prox;
    Numero *aux2 = head2->prox;
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

/* Função utilizada na subtracao de um Numero
pede emprestado um numero de uma casa, balanceando o valor
na casa anterior
 */
void pedeEmprestado(Numero * a) {
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

Numero * criaLista(int valor) {
    Numero * head;
    head = (Numero *) malloc(sizeof(Numero));
    head->num = valor;
    head->prox = head;
    return head;
}

void desalocaLista(Numero * lst) { // remove todos os elementos da lista
    while(numDigitos(lst) != 0) { // enquanto a quantidade de digitos for diferente de zero ainda temos coisa para remover
        removeNumero(lst); // remove o elemento indicado
    }
}

void removeNumero(Numero * vitima) { // desaloca a memória da célula indicada
    Numero * aux;

    if(vitima->prox == vitima) { // se a celula for a cabeça
        free(vitima); // desaloca vitima
    } else { // removemos um membro da lista duplamente encadeada
        aux = vitima->ante;
        aux->ante->prox = vitima;
        vitima->ante = aux->ante;
        free(aux); // desaloca aux
    }
}

void insereLista(Numero *head, int num){
    Numero *novo;
    novo = (Numero*) malloc(sizeof(Numero));
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

void geraLista(Numero *head, int numeros) {
    int i;
    i=0;
    while (i != numeros) { // deve ser colocado 256 digitos
        insereLista(head, geraNumeroMax(9)); //GERANDO NUMEROS DE 1-9 E GUARDANDO NA LISTA
        i++;
    }
}

void printLista(Numero *head){
    int i;
    Numero *ini;

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

