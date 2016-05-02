int euclidesEstendido(int a, int b){
    /*encontrando d = a*X + b*Y */
    int dividendo, divisor;
    dividendo = a;
    divisor = b;
    if(divisor == 0){
        return dividendo;
    }
    else{
        return mdc(b, a%b);
    }
}
