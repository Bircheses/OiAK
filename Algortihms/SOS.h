#ifndef OIAK_SOS_H
#define OIAK_SOS_H

class SOS {
private:
    unsigned int a[1];
    unsigned int b[1];
    unsigned int n[1];
    unsigned int n_[1];
    unsigned int r[1];
    unsigned int r_[1];
    unsigned int c = 0;
    unsigned int t[2] = {0,0};
    unsigned int u[2] = {0,0};
public:
    SOS(unsigned int a, unsigned int b, unsigned int n);
    void multiplication();
};


#endif
