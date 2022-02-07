#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *fptr;
float poker_test_calc(int *O, int *E){
    int i;
    float X=0;
    for(i = 0; i< 5;i++){
        X += ((O[i] - E[i])*(O[i] - E[i]))/(float)E[i];
    }
    return X;
}
void display_array_int(int *array, int n, int tab){
    int i;
    for(i=0; i < n; i++){
        fprintf(fptr,"%d", array[i]);
        ffprintf(fptr,fptr,"%d", array[i]);
        if(tab == 1){
            fprintf(fptr,"\t");
            ffprintf(fptr,fptr,"\t");
        }
        else{
            fprintf(fptr," ");
            ffprintf(fptr,fptr," ");
        }
    }
    fprintf(fptr,"\n");
    ffprintf(fptr,fptr,"\n");
}
float maximum(float* arr, int N){
    int i;
    float max = 0;
    for(i=0;i<N;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
// Finding Estimated values
int *estimated(int N){
    float P[] = {0.001, 0.504, 0.036, 0.432, 0.027};
    int *E = malloc(5*sizeof(int));
    int i;
    for(i = 0; i < 5; i++){
        E[i] = (int)(P[i] * N);
    }
    return E;
}
// Swapping values
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Sorting values
void sort(int* a, int total){
    int i, j;
    for(i=0;i<total;i++){
        for(j=i+1;j<total;j++){
            if(a[i]>a[j]){
                swap(&a[i], &a[j]);
            }
        }
    }
}

// filling in values for Expected number array
int *fill_values(int number, int range){
    int i;
    int *A = malloc(range*sizeof(int));
    for(i=0;i<range;i++){
        A[i] = number;
    }
    return A;
}
int *digit(int n, int total){
    int *d = malloc(total*sizeof(int));
    int i;
    for(i=0;i<total;i++){
        d[i] = n % 10;
        n = n/10;
    }
    return d;
}
// Counting numbers in random number array and keeping it in a range
int *count_amount_in_range(int *arr, int total, int div){
    int i, j, k, cnt, n;
    int *num;
    int *O = malloc(div*sizeof(int));
    for(i=0; i<div; i++){
        O[i]=0;
    }
    for(i=0;i<total;i++){
        num = digit(arr[i], 4);
        sort(num, 4);
        if(num[0]==num[1]==num[2]==num[3]){
            O[0]++;
        }else if((num[0]==num[1]==num[2]) || (num[1]==num[2]==num[3])){
            O[2]++;
        }else if((num[0] == num[1]) && (num[2] == num[3])){
            O[4]++;
        }else if((num[0]==num[1]) || (num[1]==num[2]) || (num[2]==num[3])){
            O[3]++;
        }else{
            O[1]++;
        }
    }
    return O;
}
int main(){
    int i, m;
    float X, XA = 9.49;
    int *O, *E;
    int xn[1000];
    int total_number_random = 1000;
    int total_range = 5;

    fptr = fopen("./poker_test_output.txt", "w");

    fprintf(fptr,"Enter two seed values and modulus operator: \n");
    fprintf(fptr,"Seed Values(x0 and x1):");
    ffprintf(fptr,fptr,"Enter two seed values and modulus operator: \n");
    ffprintf(fptr,fptr,"Seed Values(x0 and x1):");
    scanf("%d%d",&xn[0],&xn[1]);
    ffprintf(fptr,fptr,"%d\n%d\n", xn[0], xn[1]);
    fprintf(fptr,"Modulus Operator (m):");
    ffprintf(fptr,fptr,"\nModulus Operator (m):\n");
    scanf("%d", &m);
    ffprintf(fptr,fptr, "%d\n", m);

    for(i = 0; i < total_number_random-2; i++){
        xn[i+2] = (xn[i] + xn[i+1]) % m;
        while(((xn[i+2]/1000.0) < 1)){
            xn[i+3] = (xn[i+2] + xn[i+1]) % m;
            swap(&xn[i+2], &xn[i+3]);
        }
    }
    // Displaying the random Integers
    fprintf(fptr,"Random Integers are:-\n");
    ffprintf(fptr,fptr,"Random Integers are:-\n");
    display_array_int(xn, total_number_random, 0);
    fprintf(fptr,"\n");
    ffprintf(fptr,fptr,"\n");

    O = count_amount_in_range(xn, total_number_random, total_range);
    E = estimated(total_number_random);
    fprintf(fptr,"\nThe Observed Frequency are:-\n");
    fprintf(fptr,"PS\tPD\tPT\tPO\tPTP\n");
    ffprintf(fptr,fptr,"\nThe Observed Frequency are:-\n");
    ffprintf(fptr,fptr,"PS\tPD\tPT\tPO\tPTP\n");
    display_array_int(O, 5, 1);
    fprintf(fptr,"\nThe Expected Frequency are:-\n");
    fprintf(fptr,"PS\tPD\tPT\tPO\tPTP\n");
    ffprintf(fptr,fptr,"\nThe Expected Frequency are:-\n");
    ffprintf(fptr,fptr,"PS\tPD\tPT\tPO\tPTP\n");
    display_array_int(E, 5, 1);
    X = poker_test_calc(O, E);
    fprintf(fptr,"X^2(0): %0.2f",X);
    ffprintf(fptr,fptr,"X^2(0): %0.2f",X);
    if(X>XA){
        fprintf(fptr,"\nThe numbers are Uniformly Distributed.");
        ffprintf(fptr,fptr,"\nThe numbers are Uniformly Distributed.");
    }else{
        ffprintf(fptr,fptr,"\nThe numbers are Non-Uniformly Distributed.");
    }
    return 0;
}
