#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int expModular(int a, int b, int n);
int primalidade(int n);
int geraNumeroMax(int n);
int geraNumeroRandom();
int geraPrimo();

int main(){
    int r = 0;
    /*Ele ta errando de vez em quando não sei porque...*/
    r = geraPrimo();
    printf("Primo encontrado: %d \n", r);
    return 0;
}
int primalidade(int n){
    int b = n-1;
    int i = 0;
    int a = 0;
    int result;
    while(i<=100){
        a = geraNumeroMax(n);
        result = expModular(a, b, n);
        if (result != 1 % n){
            return 0;
        }
        i++;
    }
    return 1;
}

int geraPrimo(){
    int primo;
    primo = geraNumeroRandom();
    while(primalidade(primo) != 1){
        primo = geraNumeroMax(50);
        printf("procurando... \n");
    }
    return primo;
}

int geraNumeroMax(int n){
    n = n-1;
    srand((unsigned)time(NULL));
    return rand() % n + 1;
};

int geraNumeroRandom(){
    srand((unsigned)time(NULL));
    return rand();
};

int expModular(int a, int b, int n){
    int z = 0;
    if(b==0){
        return 1;
    };
    z = expModular(a, ceil(b/2), n) % n;
    if(b%2 == 0){
        return (z*z) % n;
    }else{
        return (z*z*a) % n ;
    }
};
