#include "CIOS.h"
#include <cmath>
#include <iostream>

using namespace std;

CIOS::CIOS(unsigned int a, unsigned int b, unsigned int n) {
    this->a[0] = a;
    this->b[0] = b;
    this->n[0] = n;
}

void CIOS::multiplication() {
    r[0] = 1<<((int)log2(n[0])+1); //znajdujemy pierwsza potege 2 po n

    //    a[0]=(a[0]*r[0])%n[0];    //  _ nie potrzeba zamieniać na przestrzeń montgomery'ego jeżeli obydwa a i b < n
    //    b[0]=(b[0]*r[0])%n[0];    //  _

//    BRUTE FORCE SZUKANIE WARTOŚCI DO EUKLIDESA
    for(int x=0;x<n[0]*n[0];x++){
        bool end = false;
        for(int y=0;y<n[0]*n[0];y++){
            if(x*r[0] - y*n[0] == 1){
                cout<<"\neuk "<<x<<" "<<y;
                n_[0]=y;
                r_[0]=x;
                end= true;
                break;
            }
        }
        if(end){
            break;
        }
    }
    cout<<"\n"<<n_[0]<<" "<<r_[0]<<endl;

    for (int i = 0; i < 1; i++) {
        c = 0;
        for (int j = 0; j < 1; j++) {
            int S = t[i + j] + a[j] * b[i] + c;
            t[j] = S;
        }
        int S = t[1] + c;
        t[1] = S;
        t[1+1] = c;
        c = 0;
        int m = t[0] * n_[0];
        m = m & (r[0] - 1);
        cout << "\nWynik: " << t[2] << " " << t[1] << " " << t[0] << " \n";   //wynik
        for (int j = 0; j < 1; j++){
            int S = t[j] + m*n[j] + c;
            t[j] = S;
        }
        cout << "\nWynik: " << t[2] << " " << t[1] << " " << t[0] << " \n";   //wynik
        S = t[1] + c;
        t[1] = S;
        t[1+1] = t[1+1] + c;
        for (int j = 0; j < 1; j++){
            t[j] = t[j+1];
        }
    }

    cout << "\nWynik: " << t[2] << " " << t[1] << " " << t[0] << " \n";   //wynik
}
