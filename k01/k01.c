#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(int i,double val,double ave2){
    ave2=((i-1)*ave2+val)/i;
    return ave2;
}
extern double var_online(int i,double val, double save, double ave3){
    return((i-1)*save+val)/i - pow(val,2)/i-pow((((i-1)*ave3+val)/i),2);
}

int main(void)
{
    double val,ave=0,pm,samplevariance,samplemean,populationmaen,populationvariance,save=0,ave3=0;
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
    
        ave = ave_online(i,val,ave);
        samplevariance=var_online(i,val,save,ave3);

        save=((i-1)*save+val)/i;
        ave3=((i-1)*ave3+val)/i;

        samplemean=ave;



    }

    populationmaen=samplemean;
    populationvariance=i*samplevariance/(i-1);

    pm=pow(populationvariance/i,0.5);
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("sample mean=%1f\n",samplemean);
printf("sample variance=%1f\n",samplevariance);
printf("population mean=%1f,  pm=%1f\n",populationmaen,pm);
printf("population variance=%1F\n",populationvariance);
return 0;
}

