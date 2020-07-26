#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(int i,double val,double ave){
    ave=((i-1)*ave+val)/i;
    return ave;
    }
extern double var_online(int i,double val, double save, double ave){
    return(((i-1)*save+pow(val,2))/i-pow(ave,2));
}

int main(void)
{
    double val,var=0,ave=0,pm,samplevariance,samplemean,populationmaen,populationvariance,save=0,ave3=0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int i=0;


    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    i=0;
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);
        i++;
    
        var = var_online(i,val,save,ave);
        ave = ave_online(i,val,ave);

        save=((i-1)*save+pow(val,2))/i;

    }
    samplemean=ave;
    samplevariance=var;

    populationmaen=samplemean;
    populationvariance=i*samplevariance/(i-1);

    pm=pow(populationvariance/i,0.5);
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("sample mean=%1f\n",samplemean);
    printf("sample variance=%1f\n",samplevariance);
    printf("population mean(estimated)=%1f,  pm=%1f\n",populationmaen,pm);
    printf("population variance(estimated)=%1F\n",populationvariance);
    return 0;
}

