#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emmintrin.h> /* where intrinsics are defined */


#define CLOCK_RATE_GHZ 2.0e9   /* just a wild guess ... */

/* Time stamp counter */
static __inline__ unsigned long long RDTSC(void) {
    unsigned hi,lo;
    __asm__ volatile("rdtsc" : "=a"(lo),"=d"(hi));
    return ((unsigned long long) lo)| (((unsigned long long)hi) << 32);
}

int sum_naive( int n, int *a )
{
    int sum = 0;
    for( int i = 0; i < n; i++ )
        sum += a[i];
    return sum;
}

int sum_unrolled( int n, int *a )
{
    int sum = 0;

    /* do the body of the work in a faster unrolled loop */
    for( int i = 0; i < n/4*4; i += 4 )
    {
        sum += a[i+0];
        sum += a[i+1];
        sum += a[i+2];
        sum += a[i+3];
    }

    /* handle the small tail in a usual way */
    for( int i = n/4*4; i < n; i++ )   
        sum += a[i];

    return sum;
}

int sum_vectorized( int n, int *a )
{
    /* VECTORIZE YOUR CODE HERE*/
    __m128i sum = _mm_setzero_si128();
    int * p = a;
    int * pp;
    int s = 0;
    __m128i load_num;
    for( int i = 0; i < n/4*4; i += 4,p += 4 )
    {
    	load_num = _mm_loadu_si128((__m128i*)p);
        sum = _mm_add_epi32(sum,load_num);
    } 
    pp = (int*)&sum;
    s = pp[0] + pp[1] + pp[2] + pp[3];
    for( int i = n/4*4 ; i < n; i++ )   
        s += a[i]; 
    return s;
}
int sum_vectorized_unrolled( int n, int *a )
{
    /* UNROLL YOUR VECTORIZED CODE HERE*/
    __m128i sum = _mm_setzero_si128();
    int * p = a;
    int * pp;
    int s = 0;
    __m128i load_num0;
    __m128i load_num1;
    __m128i load_num2;
    __m128i load_num3;
    for( int i = 0; i < n/16*16; i += 16,p += 16 )
    {
    	load_num0 = _mm_loadu_si128((__m128i*)p);
        sum = _mm_add_epi32(sum,load_num0);
        load_num1 = _mm_loadu_si128((__m128i*)(p+4));
        sum = _mm_add_epi32(sum,load_num1);
        load_num2 = _mm_loadu_si128((__m128i*)(p+8));
        sum = _mm_add_epi32(sum,load_num2);
        load_num3 = _mm_loadu_si128((__m128i*)(p+12));
        sum = _mm_add_epi32(sum,load_num3);
    } 

    pp = (int*)&sum;
    s = pp[0] + pp[1] + pp[2] + pp[3];
    for( int i = n/16*16; i < n; i++ )   
        s += a[i];
    return s;
}

void benchmark( int n, int *a, int (*computeSum)(int,int*), char *name )
{
    /* warm up */
    int sum = computeSum( n, a );

    /* measure */
    unsigned long long cycles = RDTSC();
    sum += computeSum( n, a );
    cycles = RDTSC()-cycles;
    
    double microseconds = cycles/CLOCK_RATE_GHZ*1e6;
    
    /* report */
    printf( "%20s: ", name );
    if( sum == 2*sum_naive(n,a) ) 
        printf( "%.2f microseconds\n", microseconds );
    else
        printf( "ERROR!\n" );
} 

int main( int argc, char **argv )
{
    const int n = 7777; /* small enough to fit in cache */
    
    /* init the array */
    int a[n] __attribute__ ((aligned (32))); /* align the array in memory by 32 bytes (good for 256 bit intrinsics) */
    for( int i = 0; i < n; i++ ) a[i] = rand( );
    
    /* benchmark series of codes */
    benchmark( n, a, sum_naive, "naive" );
    benchmark( n, a, sum_unrolled, "unrolled" );
    benchmark( n, a, sum_vectorized, "vectorized" );
    benchmark( n, a, sum_vectorized_unrolled, "vectorized unrolled" );

    return 0;
}
