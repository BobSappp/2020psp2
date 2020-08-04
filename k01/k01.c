#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double ave_online(int i,double val,double ave){
    return((i-1)*ave+val)/i;
    }

double var_online(double save, double ave,int i,double val){
    return((i-1)*save/i+(val*val)/i-pow((i-1)*ave/i+val/i,2));
}

int main(void)
{
    double val,var=0,ave=0,save=0,ave_high,ave_low,e;
    double  populationvariance;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
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
    i=0;

    
    printf("save:%f\n", save);
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);
        i++;
    
        var = var_online(save,ave,i,val);
        save = ave_online(i,val*val,save);
        ave = ave_online(i,val,ave);
      
       
    }

    populationvariance=i*var/(i-1);
    e=sqrt(populationvariance/i);
    ave_high=ave+e;
    ave_low=ave-e;


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("sample mean=%1f\n",ave);
    printf("sample variance=%1f\n",var);
    printf("population mean(estimated)%1f~%1f\n",ave_high, ave_low);
    printf("population variance(estimated)=%1f\n",populationvariance);
    return 0;
}

