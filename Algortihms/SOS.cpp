#include "SOS.h"
#include <iostream>
#include <cmath>

#include "StaticFunctions.cpp"

typedef unsigned long long uint64;

struct uint128{
    uint64 hi;
    uint64 lo;
};

using namespace std;

SOS::SOS(const uint64* a, const uint64* b, uint64 n, int s) {
    this->s = s;
    W = pow(2, w) - 1;
    this->a = new uint64[s];
    this->b = new uint64[s];
    for(int i=0; i<s; i++){
        this->a[i]=a[i];
        this->b[i]=b[i];
    }
    r = pow(2, s*w);
    this->n = r - 1;
    t = new uint64[2*s];
    u = new uint64[2*s];
    for(int i=0; i<2*s; i++){
        t[i] = 0;
        u[i] = 0;
    }
}

SOS::~SOS() {
    delete [] a;
    delete [] b;
    delete [] t;
    delete [] u;
}

void SOS::multiplication() {
    xbinGCD(r, n, &r_, &n_);
    n_ = n_ & W;
    for (int i = 0; i < s; i++) {
        int Carry = 0;
        for (int j = 0; j < s; j++) {
            int Sum = t[i + j] + a[j] * b[i] + Carry;
            Carry = 0;
            while (Sum >= 16) {
                Carry++;
                Sum -= 16;
            }
            t[i + j] = Sum;
        }
        t[i + s] = Carry;
    }
    for (int i = 0; i < s; i++) {
        unsigned int temp_n = n;
        unsigned int C = 0;
        unsigned int m = (t[i] * n_);
        m = m & W;
        for (int j = 0; j < s; j++) {
            unsigned int Sum = t[i + j] + m * (temp_n & W) + C;
            C = 0;
            while (Sum >= 16) {
                C++;
                Sum -= 16;
            }
            t[i + j] = Sum;
            temp_n = temp_n >> 4;
        }
        t[i + s] = t[i + s] + C;
        for (int j = 0; C != 0; j++) {
            if (t[i + s + j] > 15) {
                t[i + s + j] -= 16;
                t[i + s + j + 1]++;
                C = 1;
            } else {
                C = 0;
            }
        }
    }
    for (int j = 0; j <= s; j++) {
        u[j] = t[j + s];
    }
    unsigned int Borrow = 0;
    unsigned int temp_n = n;
    unsigned int Difference = 0;
    for (int i = 0; i < s; i++) {
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
