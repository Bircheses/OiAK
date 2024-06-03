#include <iostream>

#include "Algortihms/SOS.h"
#include "Algortihms/CIOS.h"

using namespace std;


int main() {

    int s=2; //ilość słów binarnych o długości 4 bity
    int w=4; //długość słowa - 4 bity
    unsigned short a[2] = {6,2}; //(0110 0010)
    unsigned short b[2] = {5,3}; //(0101 0011)


    SOS sos(a,b,0,s,w);
    sos.multiplication();

    CIOS cios(a,b,0,s,w);
    cios.multiplication();

    return 0;
}
