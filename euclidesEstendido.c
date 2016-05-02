/*Calculando euclides conforme a aula, d = a*X + b*Y | d = mdc(a,b)/
int* ext(int a, int b){
    int *vetEuclides;
    int d = 0;
    vetEuclides = (int*) malloc(3*sizeof(int));
    if (b == 0){
        vetEuclides[0] = 1;
        vetEuclides[1] = 0;
        vetEuclides[2] = a;
        return vetEuclides;
    }
    vetEuclides = ext(b, a%b);
    vetEuclides[0] = b;
    vetEuclides[1] = a - (floor(a/b)*b);
    vetEuclides[2] = vetEuclides[2];
    return vetEuclides;
}
