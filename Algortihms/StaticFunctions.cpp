#include <string>
#include <bitset>

using namespace std;

static string toBinary(int n) {
    const int BITS = 4;
    std::bitset<BITS> binary(n);
    return binary.to_string();
}

static void xbinGCD(unsigned short a, unsigned short b, unsigned short* pu, unsigned short* pv){
    unsigned short alpha, beta, u, v;
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
