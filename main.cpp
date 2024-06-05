#include <cstdio>
#include "Counter.h"

// Function to implement extended Euclidean algorithm, accepts r/2 instead of r
uint32_t xbinGCD(uint32_t a, uint32_t b){
    uint32_t alpha, beta, u, v;
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
void CIOS(uint32_t *res, const uint32_t *a, const uint32_t *b, const uint32_t *n, uint32_t n0_prime, uint32_t len) {
    uint64_t t[2*len+1];
    uint32_t i, j;

    for (i=0; i<2*len+1; i++) {
        t[i] = 0;
    }

    // algorithm
    for (i=0; i<len; i++) {
        uint64_t C = 0;
        for (j=0; j<len; j++) {
            uint64_t prod = (uint64_t)a[j] * b[i] + t[j] + C;
            t[j] = (uint32_t)prod;
            C = prod >> 32;
        }
        uint64_t prod = t[len] + C;
        t[len] = (uint32_t)prod;
        t[len+1] = prod >> 32;
        uint32_t m = (uint32_t)((uint64_t)t[0] * n0_prime);
        prod = (uint64_t)t[0] + (uint64_t)m * n[0];
        C = prod >> 32;
        for (j=1; j<len; j++) {
            prod = (uint64_t)t[j] + (uint64_t)m * n[j] + C;
            t[j-1] = (uint32_t)prod;
            C = prod >> 32;
        }
        prod = (uint64_t)t[len] + C;
        t[len-1] = (uint32_t)prod;
        t[len] = (t[len+1] + (prod >> 32));
    }

    // Step 3
    for (i=0; i<len; i++) {
        res[i] = t[i];
    }
    uint64_t borrow = 0;
    for (i=0; i<len; i++) {
        uint64_t diff = (uint64_t)res[i] - n[i] - borrow;
        res[i] = (uint32_t)diff;
        borrow = (diff >> 32) & 1;
    }
    if (borrow) {
        for (i=0; i<len; i++) {
            res[i] = t[i];
        }
    }
}

// Function to perform Montgomery multiplication using the SOS approach
void SOS(uint32_t *res, const uint32_t *a, const uint32_t *b, const uint32_t *n, uint32_t n0_prime, uint32_t len) {
    uint64_t t[2*len];
    uint32_t i, j;

    for (i=0; i<2*len; i++) {
        t[i] = 0;
    }

    // algorithm
    for (i=0; i<len; i++) {
        uint64_t C = 0;
        for (j=0; j<len; j++) {
            uint64_t prod = (uint64_t)a[j] * b[i] + t[i+j] + C;
            t[i+j] = (uint32_t)prod;
            C = prod >> 32;
        }
        t[i + len] = C;
    }
    for (i=0; i<len; i++) {
        uint64_t C = 0;
        uint32_t m = (uint32_t)((uint64_t)t[i] * n0_prime);
        for (j=0; j<len; j++) {
            uint64_t prod = (uint64_t)m * n[j] + t[i+j] + C;
            t[i+j] = (uint32_t)prod;
            C = prod >> 32;
        }
        uint64_t sum = (uint64_t)t[i+len] + C;
        t[i+len] = (uint32_t)sum;
        t[i+len+1] += sum >> 32;
    }

    // Step 3
    for (i=0; i<len; i++) {
        res[i] = t[i+len];
    }
    uint64_t borrow = 0;
    for (i=0; i<len; i++) {
        uint64_t diff = (uint64_t)res[i] - n[i] - borrow;
        res[i] = (uint32_t)diff;
        borrow = (diff >> 32) & 1;
    }
    if (borrow) {
        for (i=0; i<len; i++) {
            res[i] = t[i+len];
        }
    }
}


// Utility function to print an array of integers
void print_array(const char *name, const uint32_t *arr, uint32_t len) {
    printf("%s = ", name);
    for (uint32_t i = 0; i < len; i++) {
        printf("%08x ", arr[len - 1 - i]);
    }
    printf("\n");
}

int main() {
    uint32_t len = 4;  // Example length (number of 32-bit words)

    Counter counter;

    uint32_t a[] = {0x12345678, 0x23456789, 0x3456789a, 0x456789ab};
    uint32_t b[] = {0xabcdef01, 0xbcdef012, 0xcdef0123, 0xdef01234};
    uint32_t n[] = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

    uint32_t n0_prime = xbinGCD(0x10000000, n[0]);
    uint32_t res[len];

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