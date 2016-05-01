#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct RSA {
    long chave_publica;
    long chave_privada;
    long e;
    long d;
};

typedef unsigned long int ulgint;

int geraNumero();
long expModular(long N, long A, long expoente);
int fermat(int number);

int primo(int numCandidato);

int main(){
    int r;
    int d;
    int idx = 0;


    idx = fermat(13);
    printf("%i ", idx);
    return 0;
}

int geraNumero(){
    srand( (unsigned)time(NULL) );
    return rand();
};

long expModular(long N, long A, long expoente){
    long result;
    result = 0;
    while(expoente != 0){
        printf("DBG - EXPOENTE: %ld \n", expoente);
        printf("DBG - N: %ld \n", N);
        printf("DBG - A: %ld \n", A);
        A = pow(A, expoente);
        printf("DBG - A: %ld \n", A);
        result = A % N;
        printf("DBG - Result parcial: %ld \n", result);
        expoente--;
    }
    printf("DBG - Resultado: %ld \n", result);
    return result;
};


/**
int fermat(int number)

utiliza algoritmo de fermat para verificar se um number e primo

se number é primo retorna 1, se nao retorna 0
*/
int fermat(int number){
    int r;
    int flagPrimo = 1;
    int i = 0;
    int vetFatores[1000];
    while(number % 2 == 0){
        number = number/2;
        vetFatores[i] = 2;
        i++;
    }
    if(number == 1){
        return 0;
    }

    r = sqrt(number);

    while(r < (number+1)/2){
        int m = (r*r) - number;
        if(m >= 0 && sqrt(m) == floor(sqrt(m))){
            int s = sqrt(m);
            fermat(r - s);
            fermat(r + s);
            flagPrimo = 0;
            return 0;
        }
        r=r+1;
    }

    if(flagPrimo == 1){
        vetFatores[i] = number;
        i++;
    }
    return i;
}
/*int mdc(int a,int b){
    if(b == 0){
        return a;
    }
    else{
        return mdc(b,a%b);
    }
}*/
/*
long euclides_ext(long x, long y, long d)
{
    long r;
    r = mod(b, a);
    if (r == 0) {
        return (mod((c / a), (b / a)));   // retorna (c/a) % (b/a)
    }
    return ((euclides_ext(r, a, -c) * b + c) / (mod(a, b)));
}
*/
