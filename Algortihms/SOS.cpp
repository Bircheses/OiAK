#include "SOS.h"
#include <iostream>
#include <cmath>

using namespace std;

SOS::SOS(unsigned int a, unsigned int b, unsigned int n) {
    this->a[0] = a;
    this->b[0] = b;
    this->n[0] = n;
    fun();
}

void SOS::fun() {
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
    cout<<"\n"<<n_[0]<<" "<<r_[0];

    for (int i = 0; i < 1; i++) {                   //  _
        c = 0;                                      //  |
        for (int j = 0; j < 1; j++) {               //  |
            int S = t[i + j] + a[j] * b[i] + c;     //  |
            if (S < a[j] && S < b[j]) {             //  |   zwykle mnozenie, jezeli liczba sklada sie z 1 - itegera
                c = 1;                              //  |   to wykona sie tylko raz: a*b+0
            }                                       //  |
            t[i + j] = S;                           //  |
        }                                           //  |
        t[i + 1] = c;                               //  -
    }

    //cout << t[1] << " c" << t[0];

    for (int i = 0; i < 1; i++) {                                   //  _
        c = 0;                                                      //  |
        int m = t[i] * n_[0];                                       //  |
        m = m & (r[0] - 1); //01111 // mod(r)                       //  |
        //cout << "\n" << t[i] << " " << n_[0] << " " << m << "em"; //  |
        for (int j = 0; j < 1; j++) {                               //  |
            int S = t[i + j] + m * n[j] + c;                        //  |
            if (S < m && S < n[j]) {                                //  |
                c = 1;                                              //  |
            }                                                       //  |
            t[i + j] = S;                                           //  |
        }                                                           //  |
        t[i + 1] += c;                                              //  |
    }                                                               //  -

    //cout << "\nm" << t[1] << " " << t[0] << "\n";

    for (int j = 0; j < 1; j++) {                   //dzielimy przez r np. poprzez ignorowanie poczatkowych bitow
        //u[j] = t[j]>>(int)log2(r[0]);
        u[j] = t[j] / r[0];
    }

    //cout << "\n" << u[0] << " " << u[1] << "\n";

    int B = 0;
    unsigned int D;
    for (int i = 0; i < 1; i++) {
        D = u[i] - n[i] - B;
        //cout << D << endl;
        if (D > u[i]) {
            B = 1;
        }
        //cout << D << endl;
        t[i] = D;
    }
    D = u[1] - B;
    //cout << D << endl;
    if (D > u[1]) {
        B = 1;
    }
    t[1] = D;
    if (B == 0) {
        cout << "\nWynik: " << t[1] << " " << t[0] << " \n";   //wynik
    } else {
        cout << "\nWynik: " << u[1] << " " << u[0] << " \n";   //wynik
    }
}
