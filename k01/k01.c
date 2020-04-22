#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i){
    return(ave*(i-1)) + val/i)
}
extern double var_online(double val,double ave, double square_ave, int i){
    return(((i-1)*square_ave/i) + pow(val,2)/i-pow((i-1)*ave/i+(val/i)))
}

int main(void)
{
    double val,ave,var,square_ave;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double average;
    int i;


    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
i=0
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        i++;
        var = var_online(val,ave,square_ave,i);
        ave = ave_online(square_ave,pow(val,2),i);

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("ave=%1f\n",ave);
printf("var=%1F\n",var);

}

