#include "SOS.h"
#include <iostream>
#include <cmath>

#include "StaticFunctions.cpp"

using namespace std;

/**
     * @param a - tablica słów a
     * @param b - tablica słów b
     * @param n -
     * @param s - ilość słów w tablicach a i b
     * @param w - ilość bitów w jednym słowie
     */
SOS::SOS(unsigned short* a, unsigned short* b, unsigned short n, int s, int w) {
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

SOS::~SOS() {
    delete [] a;
    delete [] b;
    delete [] t;
    delete [] u;
}

void SOS::multiplication() {
    xbinGCD(r, n, &r_, &n_);

//    cout << r_ << " " << n_ << endl;

    n_ = n_ & W;
//    cout << n_ << endl;

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

//    cout << toBinary(t[3]) << " " << toBinary(t[2]) << " " << toBinary(t[1]) << " " << toBinary(t[0]) << endl;

    for (int i = 0; i < s; i++) {
        unsigned int temp_n = n;
        unsigned int C = 0;
        unsigned int m = (t[i] * n_);
        m = m & W;
//        cout << "M: " << m << " " << n_ << " t[i]: " << t[i] << endl;
        for (int j = 0; j < s; j++) {
            unsigned int Sum = t[i + j] + m * (temp_n & W) + C;
//            cout << "t[i+j]: " << t[i + j] << " n[j]: " << (temp_n & W) << " C: " << C << endl;
            C = 0;
            while (Sum >= 16) {
                C++;
                Sum -= 16;
            }
//            cout << "i: " << i << " j: " << j << " sum: " << Sum << " C: " << C << endl;
            t[i + j] = Sum;
            temp_n = temp_n >> 4;
        }
//        cout << t[i + s] << " bb " << C << endl;
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
//    cout << t[3] << " " << t[2] << " " << t[1] << " " << t[0] << endl;
//    cout << toBinary(t[3]) << " " << toBinary(t[2]) << " " << toBinary(t[1]) << " " << toBinary(t[0]) << endl;

    for (int j = 0; j <= s; j++) {
        u[j] = t[j + s];
    }

    unsigned int Borrow = 0;
    unsigned int temp_n = n;
    unsigned int Difference = 0;
    for (int i = 0; i < s; i++) {
//        cout << endl << u[i] << " - " << (temp_n & W) << " - " << Borrow << " DIFF: ";
        Difference = u[i] - (temp_n & W) - Borrow;
        Borrow = 0;
        if (Difference > u[i]) {
            Borrow++;
        }
//        cout << (Difference & W) << " " << Borrow << endl;
        t[i] = Difference & W;
//        cout << temp_n << endl;
        temp_n = temp_n >> 4;
//        cout << temp_n << endl;
    }
    Difference = u[s] - Borrow;
    if (Difference > u[s]) {
        Borrow++;
    }
    t[s] = Difference;
    if (Borrow == 0) {
        cout << toBinary(t[1]) << " " << toBinary(t[0]) << " t" << endl;
    } else {
        cout << toBinary(u[1]) << " " << toBinary(u[0]) << " u" << endl;
    }

}
