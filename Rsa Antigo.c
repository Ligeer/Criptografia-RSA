#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*Tentei usar a struct só que o descriptografa não tá sendo chamado a função*/
struct rsa{
    int n;
    int e;
    int d;
    int msg;
    int totiente;
};

typedef struct rsa RSA;

int expModular(int a, int b, int n);
int primalidade(int n);
int geraNumeroMax(int n);
int geraNumeroRandom();
int geraPrimo();
int* euclidesEstendido(int a, int b);
RSA *criptografa(int msgOriginal);
RSA *descriptografa(RSA *msgEmissor);

int main(){
    RSA *msgEmissor;
    RSA *msgReceptor;

    geraSeed();

    msgEmissor = criptografa(98);
    printf("Msg: %d \n", msgEmissor->msg);
    msgReceptor = descriptografa(msgEmissor);
    printf("Msg Descondificado Originalera: %d", msgReceptor->msg);
    return 0;
}

RSA *criptografa(int MsgOriginal){
    int n;
    int p;
    int q;
    int totiente;
    int result;
    int msgCriptografada;
    RSA *msgEmissor;
    msgEmissor = (RSA*) malloc(sizeof(RSA));
    p = geraPrimo();
    q = geraPrimo();

    n=p*q;
    msgEmissor->n = n;
    totiente = (p-1)*(q-1);
    result = expModular(totiente, totiente+1, n);
    while(result != totiente % n){
        /*PROCURA OUTRO PRIMO PARA SER PRIMO RELATIVO*/
        p = geraPrimo();
        q = geraPrimo();
        n=p*q;
        totiente = (p-1)*(q-1);
        result = expModular(totiente, totiente+1, n);
    }
    /*RESULT = e -> Se torna o expoente que quero: C mod n = m^e mod n */
    /*C é a mensagem que queremos codificar, testando enviar: 31*/
    printf("Codificando msg: %d \n", MsgOriginal);
    printf("N:%d \n", n);
    printf("Primos: %d | %d \n", p, q);
    msgCriptografada = expModular(MsgOriginal, 3, n);
    msgEmissor->msg = msgCriptografada;
    msgEmissor->totiente = totiente;
    printf("Msg codificada: %d \n", msgCriptografada);
    return msgEmissor;
}

RSA *descriptografa(RSA *msgEmissor){
    int chave;
    RSA *msgOriginal;
    chave = geraNumeroMax(msgEmissor->n-1);
    printf("opdsd");
    while(3*chave != 1 % msgEmissor->totiente){
        chave = geraNumeroMax(msgEmissor->n-1);
    }
    msgOriginal = (RSA*) malloc(sizeof(RSA));
    msgOriginal->msg = expModular(msgEmissor->msg, chave, msgEmissor->n);
    msgOriginal->d = chave;
    return msgOriginal;
}

int primalidade(int n){
    int b = n-1;
    int i = 0;
    int a = 0;
    int result;
    while(i<=100){ /*Rodando 100 vezes para diminuir em 1/2*100 a chance de erro*/
        a = geraNumeroMax(n-1); /*Gerando numero entre 1 e n-1*/
        result = expModular(a, b, n);
        if (result != 1 % n){ /*Verificando inverso multiplicativo*/
            return 0;
        }
        i++;
    }
    return 1;
}

int geraPrimo(){
    int primo;
    primo = geraNumeroRandom();
    while(primalidade(primo) != 1){/*Em quanto primalidade não for igual a 1 que é verdadeiro*/
        primo = geraNumeroMax(50); /*Gerando numero aleatorio entre 1 e X*/
    }
    return primo;
}

void geraSeed() { /* gera uma seed para nova sequencia de numeros aleatorios */
    srand((unsigned)time(NULL));
}

int geraNumeroMax(int n){
    return rand() % n + 1;
}

int geraNumeroRandom(){
    return rand();
}

/*Calculado conforme a aula
Formula: a^b mod n  */
int expModular(int a, int b, int n){
    int z = 0;
    if(b==0){
        return 1;
    };
    z = expModular(a, floor(b/2), n) % n;
    if(b%2 == 0){
        return (z*z) % n;
    }else{
        return (z*z*a) % n ;
    }
}

int* euclidesEstendido(int a, int b){
    int *vetEuclides;
    int d = 0;
    vetEuclides = (int*) malloc(3*sizeof(int));
    if (b == 0){
        vetEuclides[0] = 1;
        vetEuclides[1] = 0;
        vetEuclides[2] = a;
        return vetEuclides;
    }
    vetEuclides = euclidesEstendido(b, a%b);
    vetEuclides[0] = b;
    vetEuclides[1] = a - (floor(a/b)*b);
    vetEuclides[2] = vetEuclides[2];
    return vetEuclides;
}
