#include <omp.h>
#include <stdio.h>
#define N 1000
#define CHUNKSIZE 100

void doforex()
{
    int i, chunk;
    float a[N], b[N], c[N];

    /* Some initializations */
    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;
    chunk = CHUNKSIZE;

#pragma omp parallel shared(a,b,c,chunk) private(i)
    {

#pragma omp for schedule(dynamic,chunk) nowait
        for (i = 0; i < N; i++)
            c[i] = a[i] + b[i];

    } /* end of parallel region */

}
void sectionsex()
{
    int i;
    float a[N], b[N], c[N], d[N];

    /* Some initializations */
    for (i = 0; i < N; i++) {
        a[i] = i * 1.5;
        b[i] = i + 22.35;
    }

#pragma omp parallel shared(a,b,c,d) private(i)
    {
#pragma omp sections nowait
        {
#pragma omp section
            for (i = 0; i < N; i++)
                c[i] = a[i] + b[i];

#pragma omp section
            for (i = 0; i < N; i++)
                d[i] = a[i] * b[i];
        } /* end of sections */
    } /* end of parallel region */
}
void singleex()
{
    //由单个线程执行
}
//int main() {
//    doforex();
//    return 0;
//}