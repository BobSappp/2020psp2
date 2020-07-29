#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

#define Mu_A 170.8
#define Mu_B 169.7
#define sigma_A 5.43
#define sigma_B 5.5

int main(void)
{
    double Likelihood_A=1, Likelihood_B=1;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        Likelihood_A=Likelihood_A*p_stdnorm((val-Mu_A)/sigma_A);
        Likelihood_B=Likelihood_B*p_stdnorm((val-Mu_B)/sigma_B);


    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",Likelihood_A);
    printf("L_B: %f\n",Likelihood_B);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
    
}

