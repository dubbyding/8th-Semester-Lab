#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
float* dp(float* arr, int N){
    int i;
    float calc;
    float* a = malloc(N*sizeof(float));
    for(i=0;i<N;i++){
        calc = ((float)(i+1)/N) - arr[i];
        a[i] = calc;
    }
    return a;
}
float* dm(float* arr, int N){
    int i;
    float* a = malloc(N*sizeof(float));
    for(i=0;i<N;i++){
        a[i] = arr[i] - ((float)(i)/N);
    }
    return a;
}
// Swapping values
void swap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
// Sorting values
void sort(float* a){
    int i, j;
    for(i=0;i<100;i++){
        for(j=0;j<99-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
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
// Counting numbers in random number array and keeping it in a range
int *count_amount_in_range(float *arr, int total,int div){
    int i, j;
    int *O = malloc(div*sizeof(int));
    for(i=0; i<div; i++){
        O[i]=0;
    }
    int hop_count = total/div;
    for(i = 0; i < 100; i++){
        for(j = 0; j<hop_count;j++){
            if(arr[i] <= ((float)(j+1)/hop_count)){
                O[j]++;
                break;
            }
        }
    }
    return O;
}
void display_array_int(int *array){
    int i;
    for(i=0; i < 100; i++){
        fprintf(fptr,"%d ", array[i]);
    }
    fprintf(fptr,"\n");
}

void display_array_float(float *array){
    int i;
    for(i=0; i < 100; i++){
        fprintf(fptr,"%0.2f ", array[i]);
    }
    fprintf(fptr,"\n");
}
int main(){
    int i, m;
    float totalT = 0, d_p_max, d_m_max, d;
    int *O, *E;
    float *d_plus, *d_minus;
    int xn[100];
    float T[0];
    float rn[100];
    int total_number_random = 100;
    int total_range = 10;
    fprintf(fptr,"Enter two seed values and modulus operator: \n");
    fprintf(fptr,"Seed Values(x0 and x1):");
    scanf("%d%d",&xn[0],&xn[1]);
    fprintf(fptr,"Modulus Operator (m):");
    scanf("%d", &m);
    for(i = 0; i < total_number_random-2; i++){
        xn[i+2] = (xn[i] + xn[i+1]) % m;
    }
    for(i = 0; i< total_number_random; i++){
        rn[i] = (float)xn[i]/m;
    }
    // Displaying the random Integers
    fprintf(fptr,"Random Integers are:-\n");
    display_array_int(xn);
    // Displaying the Random Numbers
    fprintf(fptr,"Random Numbers are:-\n");
    display_array_float(rn);
    fprintf(fptr,"\n");
    // for chi squared test
    O = count_amount_in_range(rn, total_number_random, total_range);
    E = fill_values(10, total_range);
    for(i=0;i<total_range;i++){
        T[i] = pow((O[i] - E[i]), 2) / E[i];
        totalT += T[i];
    }
    // Displaying the result
    fprintf(fptr,"Range\tO[n]\tE[n]\tT[n]\n");
    for(i=0; i<total_range; i++){
        fprintf(fptr,"%0.1f-%0.1f\t%d\t%d\t%0.1f\n",(float)i/10,(float)(i+1)/10, O[i], E[i], T[i]);
    }
    fprintf(fptr,"Chi Square = %0.2f\n", totalT);
    fprintf(fptr,"\n");
    // Kolmogorov-smirnov test
    // Sorting values for Kolmogorov-smirnov test
    sort(rn);
    d_plus = dp(rn, total_number_random);
    d_minus = dm(rn, total_number_random);
    d_p_max = maximum(d_plus, total_number_random);
    d_m_max = maximum(d_minus, total_number_random);
    d = d_p_max;
    if(d_m_max > d){
        d = d_m_max;
    }
    fprintf(fptr,"i\tD+\tD-\n");
    for(i=0; i<total_number_random;i++){
        fprintf(fptr,"%d\t%0.2f\t%0.2f\n", i+1, d_plus[i], d_minus[i]);
    }
    fprintf(fptr,"\n D0 = %0.2f",d);
    return 0;
}
