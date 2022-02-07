#include<stdio.h>
#include<stdlib.h>
int main(){
    float pi = 3.14159265;
    int i, m, pn, index;
    float r, avg, err;

    FILE *fptr;
    fptr = fopen("./monte_carlo_output.txt", "w");

    int iter;
    fprintf(fptr,"Enter how many times do you want to iterate? ");
    ffprintf(fptr,fptr,"Enter how many times do you want to iterate? ");
    scanf("%d", &iter);
    ffprintf(fptr,fptr, "%d", iter);
    float *value = malloc(iter*sizeof(float));
    int n;
    fprintf(fptr,"Enter total number of random numbers to be calculated:- ");
    ffprintf(fptr,fptr,"Enter total number of random numbers to be calculated:- ");
    scanf("%d",&n);
    ffprintf(fptr,fptr, "%d", n);
    int *xn = malloc(n*sizeof(int));
    int *yn = malloc(n*sizeof(int));
    float *xfn = malloc(n*sizeof(float));
    float *yfn = malloc(n*sizeof(float));
    for(index=0;index<iter;index++){

        fprintf(fptr,"\nEnter two seed values and modulus operator: \n");
        fprintf(fptr,"Seed Values(x0 and x1): ");
        ffprintf(fptr,fptr,"\nEnter two seed values and modulus operator: \n");
        ffprintf(fptr,fptr,"Seed Values(x0 and x1): ");
        scanf("%d%d",&xn[0],&xn[1]);
        ffprintf(fptr,fptr,"%d\n%d", xn[0], xn[1]);
        fprintf(fptr,"Seed Values(y0 and y1): ");
        ffprintf(fptr,fptr,"Seed Values(y0 and y1): ");
        scanf("%d%d", &yn[0], &yn[1]);
        ffprintf(fptr,fptr,"%d\n%d", yn[0], yn[1]);
        fprintf(fptr,"Modulus Operator (m): ");
        ffprintf(fptr,fptr,"Modulus Operator (m): ");
        scanf("%d", &m);
        ffprintf(fptr,fptr, "%d", m);

        for(i = 0; i<n-2;i++){
            xn[i+2] = (xn[i]+xn[i+1]) % m;
            yn[i+2] = (yn[i]+yn[i+1]) % m;
        }
        for(i=0; i < n; i++){
            xfn[i] = (float)xn[i]/m;
            yfn[i] = (float)yn[i]/m;
        }
        for(i=0;i<n;i++){
            fprintf(fptr,"(%f, %f) ", xfn[i], yfn[i]);
            ffprintf(fptr,fptr,"(%f, %f) ", xfn[i], yfn[i]);
        }
        pn = 0;
        for(i=0;i<n;i++){
            r = xfn[i] * xfn[i] + yfn[i] * yfn[i];
            if(r <= 1){
                pn++;
            }
        }
        value[index] = ((float)pn / n) * 4;
    }
    avg = 0;
    fprintf(fptr,"\nThe value of pi in each iteration is:-\n");
    ffprintf(fptr,fptr,"\nThe value of pi in each iteration is:-\n");
    for(index = 0; index<iter;index++){
        avg += value[index];
        fprintf(fptr,"\n%d iteration:- Pi = %f",index+1, value[index]);
        ffprintf(fptr,fptr,"\n%d iteration:- Pi = %f",index+1, value[index]);
    }
    avg /= iter;
    fprintf(fptr,"\nThe Value of Pi is:- %f", avg);
    ffprintf(fptr,fptr,"\nThe Value of Pi is:- %f", avg);
    if(pi>avg){
        err = (pi - avg) / pi * 100;
    }else{
        err = (avg - pi) / pi * 100;
    }
    fprintf(fptr,"\nThe Error percent is %f\%", err);
    ffprintf(fptr,fptr,"\nThe Error percent is %f\%", err);
    fclose(fptr);
    return 0;
}
