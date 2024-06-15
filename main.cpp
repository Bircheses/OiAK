#include <cstdio>
#include "Counter.h"
#include <iostream>
#include "cmath"

typedef unsigned char uchar;
typedef unsigned short ushort;

// Function to implement extended Euclidean algorithm, accepts r/2 instead of r
uchar xbinGCD(long long int a, long long int b){
    long long int alpha, beta, u, v;
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
    return v;
}

// Function to perform Montgomery multiplication using the CIOS approach
void CIOS(uchar *res, const uchar *a, const uchar *b, const uchar *n, uchar n0_prime, uchar len) {
    ushort t[2*len+1];
    uchar i, j;

    for (i=0; i<2*len+1; i++) {
        t[i] = 0;
    }

    // algorithm
    for (i=0; i<len; i++) {
        ushort C = 0;
        for (j=0; j<len; j++) {
            ushort prod = (ushort)a[j] * b[i] + t[j] + C;
            t[j] = (uchar)prod;
            C = prod >> 8;
        }
        ushort prod = t[len] + C;
        t[len] = (uchar)prod;
        t[len+1] = prod >> 8;
        uchar m = (uchar)((ushort)t[0] * n0_prime);
        prod = (ushort)t[0] + (ushort)m * n[0];
        C = prod >> 8;
        for (j=1; j<len; j++) {
            prod = (ushort)t[j] + (ushort)m * n[j] + C;
            t[j-1] = (uchar)prod;
            C = prod >> 8;
        }
        prod = (ushort)t[len] + C;
        t[len-1] = (uchar)prod;
        t[len] = (t[len+1] + (prod >> 8));
    }

    // Step 3
    for (i=0; i<len; i++) {
        res[i] = t[i];
    }
    ushort borrow = 0;
    for (i=0; i<len; i++) {
        ushort diff = (ushort)res[i] - n[i] - borrow;
        res[i] = (uchar)diff;
        borrow = (diff >> 8) & 1;
    }
    if (borrow) {
        for (i=0; i<len; i++) {
            res[i] = t[i];
        }
    }
}

// Function to perform Montgomery multiplication using the SOS approach
void SOS(uchar *res, const uchar *a, const uchar *b, const uchar *n, uchar n0_prime, uchar len) {
    ushort t[2*len];
    uchar i, j;

    for (i=0; i<2*len; i++) {
        t[i] = 0;
    }

    // algorithm
    for (i=0; i<len; i++) {
        ushort C = 0;
        for (j=0; j<len; j++) {
            ushort prod = (ushort)a[j] * b[i] + t[i+j] + C;
            t[i+j] = (uchar)prod;
            C = prod >> 8;
        }
        t[i + len] = C;
    }
    for (i=0; i<len; i++) {
        ushort C = 0;
        uchar m = (uchar)((ushort)t[i] * n0_prime);
        for (j=0; j<len; j++) {
            ushort prod = (ushort)m * n[j] + t[i+j] + C;
            t[i+j] = (uchar)prod;
            C = prod >> 8;
        }
        ushort sum = (ushort)t[i+len] + C;
        t[i+len] = (uchar)sum;
        t[i+len+1] += sum >> 8;
    }

    // Step 3
    for (i=0; i<len; i++) {
        res[i] = t[i+len];
    }
    ushort borrow = 0;
    for (i=0; i<len; i++) {
        ushort diff = (ushort)res[i] - n[i] - borrow;
        res[i] = (uchar)diff;
        borrow = (diff >> 8) & 1;
    }
    if (borrow) {
        for (i=0; i<len; i++) {
            res[i] = t[i+len];
        }
    }
}


// Utility function to print an array of integers
void print_array(const char *name, const uchar *arr, uchar len) {
    printf("%s = ", name);
    for (uchar i = 0; i < len; i++) {
        printf("%02x ", arr[len - 1 - i]);
    }
    printf("\n");
}

int main() {
    uchar len = 4;  // Example length (number of 8-bit words)

    Counter counter;

    uchar a[] = {0x78, 0x89, 0x9a, 0x6b};
    uchar b[] = {0x01, 0x12, 0x23, 0x34};
    uchar n[] = {0xff, 0xff, 0xff, 0xff};

    long long int n_1 = 0xfffffff1;
    long long int r =  pow(2,len*8-1);
    uchar n0_prime = xbinGCD(r, n_1);
    for(int i=0;i<len;i++){
        n[i]= (uchar) n_1;
        n_1 = n_1 >> 8;
    }
    uchar res[len];

    counter.start();
    CIOS(res, a, b, n, n0_prime, len);
    counter.stop();
    print_array("Result", res, len);
    printf("%lf\n", counter.getElapsedTime());

    counter.start();
    SOS(res, a, b, n, n0_prime, len);
    counter.stop();
    print_array("Result", res, len);
    printf("%lf\n", counter.getElapsedTime());

    return 0;
}