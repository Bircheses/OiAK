#ifndef OIAK_SOS_H
#define OIAK_SOS_H

typedef unsigned long long uint64;

class SOS {
private:
    int s;
    int W;
    uint64* a;
    uint64* b;
    uint64 n;
    uint64 n_;
    uint64 r;
    uint64 r_;
    uint64* t;
    uint64* u;
    const int w =  64; //64 bitowa liczba
public:
    SOS(const uint64* a, const uint64* b, uint64 n, int s);
    ~SOS();
    void multiplication();
};


#endif
