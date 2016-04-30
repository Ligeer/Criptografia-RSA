#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

bool isCousin(int number);

using namespace std;

int main() {
int aleat, i;


 srand(time(NULL));

 aleat = rand() % 100;

 cout<<"Número aleatorio selcionado = "<<aleat<<endl;
 cout<<"oi";

if(isCousin(aleat) == true) {
cout<<"eh primo";
} else {
cout<<"nao eh primo";
}

}

bool isCousin(int number) {
int a, i;
    for(i = 1; i < 100; i++) {
        a = rand() % number;

        if(pow(a, number - 1) != (1 % number)) {
            return false;
        }
    }
    return true;
}

