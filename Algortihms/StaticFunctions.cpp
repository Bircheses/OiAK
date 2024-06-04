#include <string>
#include <bitset>

typedef unsigned long long uint64;
typedef unsigned int uint32_t;

using namespace std;

static uint32_t hi(uint32_t x) {
    return x >> 16;
}

static uint32_t lo(uint32_t x) {
    return ((1ULL << 16) - 1) & x;
}

struct C_S{
    uint32_t Sum;
    uint32_t Carry;
};

struct C_M{
    uint32_t Mul;
    uint32_t Carry;
};

static C_S addc (uint32_t a, uint32_t b, uint32_t c){
    C_S result;
    result.Carry = __builtin_uadd_overflow(a, b, &result.Sum);
    a = __builtin_uadd_overflow(result.Sum, c, &result.Sum);
    result.Carry += a;
    return result;
}

static C_M mulc (uint32_t a, uint32_t b){
    C_M result;
    uint32_t s0, s1, s2, s3;

    uint32_t x = lo(a) * lo(b);
    s0 = lo(x);

    x = hi(a) * lo(b) + hi(x);
    s1 = lo(x);
    s2 = hi(x);

    x = s1 + lo(a) * hi(b);
    s1 = lo(x);

    x = s2 + hi(a) * hi(b) + hi(x);
    s2 = lo(x);
    s3 = hi(x);

    result.Mul = s1 << 16 | s0;
    result.Carry = s3 << 16 | s2;
    return result;
}

static string toBinary(int n) {
    const int BITS = 4;
    std::bitset<BITS> binary(n);
    return binary.to_string();
}

static void xbinGCD(uint64 a, uint64 b, uint64* pu, uint64* pv){
    uint64 alpha, beta, u, v;
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
