#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef CONST_SEED
#define RAND_SEED 2020
#else
#include <time.h>
#define RAND_SEED ((unsigned) time(NULL))
#endif

extern double r_unif(void);
extern double r_stdnorm(void);

int main(int argc, char* argv[])
{
    int num_dummy;
    double mu;
    double sigma;
    int i,n;
    double dummy;


    
    



    printf("============================================\n");
    sscanf(argv[1],"%lf",&mu);
    printf("template mean: %4.1lf\n",mu);
    sscanf(argv[2],"%lf",&sigma);
    printf("template standard deviation: %3.2lf\n",sigma);
    sscanf(argv[3],"%d",&num_dummy);
    printf("Num of dummy data: %d\n",num_dummy);
    printf("============================================\n");
        
    

    srand(RAND_SEED);
    for( i=0;i<num_dummy;i++){
        /* r_stdnormを使って，1人のデータを捏造 */
        dummy =r_stdnorm()*sigma+mu;
        printf("%5.2lf\n",dummy);
    }

    return EXIT_SUCCESS;
}

double r_unif(void)
{
    return (double)(rand()+1)/(RAND_MAX+2);
}

double r_stdnorm(void)
{
    return sqrt( -2.0*log(r_unif()) ) * sin( 2.0*M_PI*r_unif() );
}
