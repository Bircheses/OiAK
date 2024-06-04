#include <iostream>

#include "Algortihms/SOS.h"
#include "Algortihms/CIOS.h"
#include "Algortihms/Counter.h"

using namespace std;


int main() {

    int s=2; //ilość słów binarnych o długości 4 bity
    int w=4; //długość słowa - 4 bity
    unsigned int a[2] = {6,2}; //(0110 0010)
    unsigned int b[2] = {5,3}; //(0101 0011)

    Counter counter;

    SOS sos(a,b,0,s,w);
    counter.start();
    sos.multiplication();
    counter.stop();
    cout << counter.getElapsedTime() << endl;

    CIOS cios(a,b,0,s,w);
    counter.start();
    cios.multiplication();
    counter.stop();
    cout << counter.getElapsedTime() << endl;

    return 0;
}
