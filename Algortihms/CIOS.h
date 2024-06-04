#ifndef OIAK_CIOS_H
#define OIAK_CIOS_H

class CIOS {
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
public:
    CIOS(unsigned int* a, unsigned int* b, unsigned long long int n, int s, int w);
    ~CIOS();
    void multiplication();
};


#endif //OIAK_CIOS_H
