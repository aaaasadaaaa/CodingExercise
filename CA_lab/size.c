#include <stdio.h>
#include <stdint.h>
#include <time.h>
int main(){
    char a ;
    short b;
    short int c;
    int d;
    long int e;
    unsigned int f;
    void * g;
    size_t h;
    float i;
    double j;
    int8_t k;
    int16_t l;
    int32_t m ;
    int64_t n;
    time_t o;
    clock_t p;
    struct tm q;
    int aa = sizeof(a);
    int bb = sizeof(b);
    int cc = sizeof(c);
    int dd = sizeof(d);
    int ee = sizeof(e);
    int ff = sizeof(f);
    int gg = sizeof(g);
    int hh = sizeof(h);
    int ii = sizeof(i);
    int jj = sizeof(j);
    int kk = sizeof(k);
    int ll = sizeof(l);
    int mm = sizeof(m);
    int nn = sizeof(n);
    int oo = sizeof(o);
    int pp = sizeof(p);
    int qq = sizeof(q);
    int rr = sizeof(NULL);
    printf("size of char: %d \nsize of short: %d \nsize of short int: %d \nsize of int: %d \nsize of long int: %d \nsize of unsigned int: %d \nsize of void *: %d \nsize of size_t: %d \nsize of float: %d \nsize of double: %d \nsize of int8_t: %d \nsize of int16_t: %d \nsize of int32_t: %d \nsize of int64_t: %d \nsize of time_t: %d \nsize of clock_t: %d \nsize of struct: %d \nsize of NULL: %d \n",aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr);
    return 0;
}

