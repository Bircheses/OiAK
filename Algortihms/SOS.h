#ifndef OIAK_SOS_H
#define OIAK_SOS_H

class SOS {
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
    SOS(unsigned short* a, unsigned short* b, unsigned short n, int s, int w);
    ~SOS();
    void multiplication();
};


#endif
