#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;


/**
  O tipo de dado bin armazenará um digito inteiro e o endereço do próximo bin,
    o tratamento de 0 e 1 será feito por outras funções

*/
struct binario {
    int conteudo;
    struct binario * seguinte;
};
typedef binario bin;

/* Percorre cada bin e imprime os dígitos todos concatenados na mesma string */
void printBin(bin * numero) {
    bin * aux;

    aux = numero;
    while(aux != NULL) {
        cout<<aux->conteudo;
        aux = aux->seguinte;
    }
}

/* Cria um ponteiro para um bin, e armazena o valor dentro dele,
a função retorna o endereço do bin criado
 */
bin * criaBin(int valor) {
    bin * novo;
    novo = (bin *) malloc(sizeof(bin));
    novo->conteudo = valor;
    novo->seguinte = NULL;
    return novo;
}

/* Faz a conversão de um inteiro para um bin
    retorna o endereço do bin
 */
bin * transformaBinario(int valor) {
    bin * inicio, * fim;
    int aux;

    aux = valor;
    inicio = criaBin(aux % 2);

    aux /= 2;

    while(aux != 0) { // a cada iteracao adicionamos o binario ao contraro ( no final) semelhante a uma pilha
        fim = criaBin(aux % 2);
        fim->seguinte = inicio;
        inicio = fim;
        aux /= 2;
    }
    return fim;
}

bin * somaBinario(bin * a, bin * b) {
/*
*c = novo bin
int soma;

enquanto(a->seg = NULL e b->seg = NULL) {
    soma = 0;
    se (a->seg != NULL) {
        soma += a->seg->conteudo;
        a = a->seg;
    }
    se (b->seg != NULL) {
        soma += a;
        b = b->seg
    }
    adiciona no final de *c (soma %2)
*/
return NULL;
}

bin * subtraiBinario(bin * a, bin * b) {
    /* semelhante ao somabin */
    return NULL;
}


int main() {
    printBin(transformaBinario(23)); /* imprime 23 em binario */
    return 0;
}
