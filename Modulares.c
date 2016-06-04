//Soma
Numprimo *somaModular(Numprimo *num1, Numprimo *num2, Numprimo *mod);
//Subtração
Numprimo *subtracModular(Numprimo *num1, Numprimo *num2, Numprimo *mod);
//Multiplicação
Numprimo *multiplicaModular(Numprimo *num1, Numprimo *num2, Numprimo *mod);
//Exponenciação
//Numprimo *expoModular(Numprimo *x, Numprimo *y, Numprimo *N);
//Numprimo *expModular2(Numprimo *a, Numprimo *b, Numprimo *n);

//Função soma modular: faz a soma de 2 numeros e devolve o resto pelo modulo
Numprimo *somaModular(Numprimo *num1, Numprimo *num2, Numprimo *mod) {
    Numprimo *result = soma(num1, num2);
    Resultado *tmp = divide(result, mod);
    return tmp->value2; //Retornando o resto
}

//Função subtracai modular: faz a subtracao entre n1 e n2, devolvendo o resto da divisao por mod
Numprimo *subtracModular(Numprimo *num1, Numprimo *num2, Numprimo *mod) {
    Numprimo *result;
    result = subtrai(num1, num2);
    Resultado *tmp = divide(result, mod);
    return tmp->value2; //Retornando o resto
}

//Função multiplica modular: faz a multiplicacoes entre n1 e n2, devolvendo o resto da divisao por mod
Numprimo *multiplicaModular(Numprimo *num1, Numprimo *num2, Numprimo *mod) {
    Numprimo *result;
    result = multiplica(num1, num2);
    Resultado *tmp = divide(result, mod);
    return tmp->value2; //Retornando o resto
}

TENHO ALGUMAS VERSÕES DO EXPONENCIAÇÃO SE QUISER UTILIZAR VEJA QUAL A MELHOR

//Função exponenciacao modular
/*Numprimo *expoModular(Numprimo *x, Numprimo *y, Numprimo *N) {
    Numprimo *z; //Irá guardar o valor das chamadas recursivas
    Numprimo *z2 = criaLista(0); //Irá guardar o valor das chamadas recursivas
    Numprimo *auxExpMod;
    Resultado *auxDivide;
    int i = 1;
    //Criando o numero 10
    Numprimo *num10 = NULL;
    if(num10 == NULL) {
        num10 = criaLista(0);
        insereLista(num10, 0);
        insereLista(num10, 1);
    }
    //----------------------------
    printLista(y);
    printf("\n");
    if(y->prox->num == 0) { //Significando o igual a 0
        z = criaLista(0);
        insereLista(z, 1);
        return z;
    }
    deslocaEsquerda(y);
    z = expoModular(x, y, N);
    printLista(z);
    while(i != 10) {
        if(z2->prox == z2){
            z2 = copiaNum(z);
        }
        z2 = multiplica(z, z2);
        i++;
    }
    z = z2;
    z = expoModular(x, num10, N);
    auxDivide = divide(exp, num10); //Vai retornar o quociente e o resto,
    auxExpMod = expoModular(x, auxDivide->value2, N);
    return multiplicaModular(auxExpMod, z, N);
}*/
