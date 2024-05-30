#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

typedef unsigned short uint16;

string toBinary(int n) {
    const int BITS = 4;  // Number of bits for the binary representation
    std::bitset<BITS> binary(n);
    return binary.to_string();
}

void xbinGCD(uint16 a, uint16 b, uint16 *pu, uint16 *pv){
    uint16 alpha, beta, u, v;
    u = 1; v = 0;
    alpha = a; beta = b;
    while (a > 0) {
        a = a >> 1;
        if ((u & 1) == 0) {
            u = u >> 1; v = v >> 1;
        }
        else {
            u = ((u ^ beta) >> 1) + (u & beta);
            v = (v >> 1) + alpha;
        }
    }
    *pu = u;
    *pv = v;
}

int main() {

    int s=2; //ilość słów binarnych o długości 4 bity
    uint16 a[2] = {6,2}; //(0110 0010)
    uint16 b[2] = {5,3}; //(0101 0011)
    uint16 t[4] = {0,0,0,0};
    uint16 r = pow(2, s*2);
    uint16 n = r-1;
    uint16 r_;
    uint16 n_;

    xbinGCD(r >> 1, n, &r_, &n_);

    cout << r_ << " " << n_ << endl;

    for(int i=0; i<s; i++){
        int Carry = 0;
        for(int j=0; j<s; j++){
            int Sum = t[i+j] + a[j]*b[i] + Carry;
            Carry = 0;
            while (Sum >= 16){
                Carry++;
                Sum-=16;
            }
            t[i+j] = Sum;
        }
        t[i+s] = Carry;
    }

    cout << toBinary(t[3]) << " " << toBinary(t[2]) << " " << toBinary(t[1]) << " " << toBinary(t[0]) << endl;

    return 0;
}
