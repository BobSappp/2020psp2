#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct D
{
    double ID;
    int gender;
    double height;
};

int main(void)
{
    int i, n, match, gender;
    double val, id, ID;
    char fname[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf[256];
    char buf2[256];
    FILE *fp, *fp2;
    double lower_bound, upper_bound;
    struct D date[14];

    printf("input the filename of sample hight:");
    fgets(fname, sizeof(fname), stdin);
    fname[strlen(fname) - 1] = '\0';
    printf("the filename of sample: %s\n", fname);

    printf("input the filename of sample ID:");
    fgets(fname2, sizeof(fname2), stdin);
    fname2[strlen(fname2) - 1] = '\0';
    printf("the filename of sample: %s\n", fname2);

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(fname2, "r");
    if (fp2 == NULL)
    {
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }
    i = 0;
    fgets(buf, sizeof(buf),fp);
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        sscanf(buf, "%d,%lf", &gender, &val);
        date[i].gender = gender;
        date[i].height = val;
        i++;
    }
    n = i;

    i = 0;
    while (fgets(buf2, sizeof(buf2), fp2) != NULL)
    {
        sscanf(buf2, "%lf", &id);
        date[i].ID = id;
        i++;
    }

    printf("whichi ID's data do you want? :");
    scanf("%lf", &ID);
    printf("---\n");

    match = 0;
    for (i = 0; i < n; i++)
    {
        if (date[i].ID == ID)
        {
            printf("ID:%.0lf\n", date[i].ID);
            printf("gender:");
            if (date[i].gender == 1)
            {
                printf("male\n");
            }
            else
            {
                printf("female\n");
            }
            printf("height:%.1lf\n", date[i].height);
            match=1;
        }
    }
    if (match == 0)
    {
        printf("No date\n");
    }
    printf("---");
}