#ifndef OIAK_SOS_H
#define OIAK_SOS_H

typedef unsigned long long uint64;

class SOS {
private:
    int s;
    int W;
    unsigned int* a;
    unsigned int* b;
    unsigned long long int n;
    unsigned long long int n_;
    unsigned long long int r;
    unsigned long long int r_;
    unsigned int* t;
    unsigned int* u;
    const int w =  64; //64 bitowa liczba
public:
    SOS(const unsigned int* a, const unsigned int* b, unsigned long long int n, int s, int w);
    ~SOS();
    void multiplication();
};


#endif
