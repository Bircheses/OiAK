#ifndef OIAK_CIOS_H
#define OIAK_CIOS_H

class CIOS {
private:
    int s;
    int W;
    unsigned short* a;
    unsigned short* b;
    unsigned short n;
    unsigned short n_;
    unsigned short r;
    unsigned short r_;
    unsigned short* t;
    unsigned short* u;
public:
    CIOS(unsigned short* a, unsigned short* b, unsigned short n, int s, int w);
    ~CIOS();
    void multiplication();
};


#endif //OIAK_CIOS_H
