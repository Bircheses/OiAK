#include "CIOS.h"
#include <cmath>
#include <iostream>

#include "StaticFunctions.cpp"

using namespace std;

CIOS::CIOS(unsigned short* a, unsigned short* b, unsigned short n, int s, int w) {
    this->s = s;
    W = pow(2, w) - 1;
    this->a = new unsigned short[s];
    this->b = new unsigned short[s];
    for(int i=0; i<s; i++){
        this->a[i]=a[i];
        this->b[i]=b[i];
    }
    r = pow(2, s*w);
    this->n = r - 1;
    t = new unsigned short[2*s];
    u = new unsigned short[2*s];
    for(int i=0; i<2*s; i++){
        t[i] = 0;
        u[i] = 0;
    }
}

CIOS::~CIOS() {
    delete [] a;
    delete [] b;
    delete [] t;
    delete [] u;
}

void CIOS::multiplication() {
    xbinGCD(r, n, &r_, &n_);
    n_ = n_ & W;
    for(int i=0;i<s;i++){
        unsigned int C = 0;
        unsigned int S;
        for(int j=0;j<s;j++){
            S = t[j] + a[j]*b[i] + C;
            C=0;
            while (S >= 16) {
                C++;
                S -= 16;
            }
            t[j] = S;
        }
        S = t[s] + C;
        C = 0;
        while(S>15){
            C++;
            S -= 16;
        }
        t[s] = S;
        t[s+1] = C;
        C = 0;
        unsigned int m = (t[0]*n_)& W;
        unsigned int temp_n = n;
        for(int j=0; j<s; j++){
            S = t[j] + m * (temp_n & W) + C;
            C=0;
            while (S >= 16) {
                C++;
                S -= 16;
            }
            t[j] = S;
            temp_n = temp_n >> 4;
        }
        S = t[s] + C;
        C = 0;
        if(S>15){
            C++;
            S -= 16;
        }
        t[s] = S;
        t[s+1] = t[s+1] + C;
        for(int j=0; j<=s; j++){
            t[j] = t[j+1];
        }
    }
    for(int i=0;i<s+2;i++){
        u[i]=t[i];
    }
    unsigned int Borrow = 0;
    unsigned int temp_n = n;
    unsigned int Difference = 0;
    for (int i = 0; i < s+2; i++) {
        Difference = u[i] - (temp_n & W) - Borrow;
        Borrow = 0;
        if (Difference > u[i]) {
            Borrow++;
        }
        t[i] = Difference & W;
        temp_n = temp_n >> 4;
    }
    Difference = u[s] - Borrow;
    if (Difference > u[s]) {
        Borrow++;
    }
    t[s] = Difference;
    if (Borrow == 0) {
        cout << toBinary(t[1]) << " " << toBinary(t[0]) << "t" << endl;
    } else {    
        cout << toBinary(u[1]) << " " << toBinary(u[0]) << "u" << endl;
    }
}
