#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int expModular(int a, int b, int n);

int main(){
    int r = 0;
    printf("DBG1");
    r = expModular(31, 3, 137);
    printf("R:%d \n", r);
    return 0;
}

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
};
