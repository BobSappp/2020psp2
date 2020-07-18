#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

#define Mu_A 170.8
#define Mu_B 169.7
#define sigma_A 5.43
#define sigma_B 5.5
#define M_PI 3.14

int main(void)
{
    int z1, z2, x1, x2, u1, u2, b1, b2, max_val=1, min_val=1;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

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

        z1=(val-u1)/b1;
        z2=(val-u2)/b2;
        x1=p_stdnorm(z1);
        x2=p_stdnorm(z2);
        max_val=max_val*x1;
        min_val=min_val*x2;

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",max_val);
    printf("L_B: %f\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

