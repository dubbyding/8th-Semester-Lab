#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, d, years;
   	float I, T, G, C, Y;

	FILE *fptr;
	fptr = fopen("./Distributed_lag_model_output.txt", "w");

   	fprintf(fptr,"Enter Current Year:- ");
   	scanf("%d", &d);
	fprintf(fptr,"%d\n", d);
	fprintf(fptr,"Enter Total year to simulate:- ");
	scanf("%d", &years);
	fprintf(fptr,"%d\n", years);
   	fprintf(fptr,"Enter Previous Year's National income:- ");
   	scanf("%f",&Y);
	fprintf(fptr,"%f\n", Y);
   	fprintf(fptr,"Enter Previous Year's Goverment Expences:- ");
	scanf("%f", &G);
	fprintf(fptr,"%f\n", G);
	fprintf(fptr,"\t\t\tNational Economy Simulation\n\t\t\tUsing Distributed Lag Model\n");
	fprintf(fptr,"\n");
	fprintf(fptr,"National Income from %d = %0.2f\t",d, Y);
	fprintf(fptr,"Government Expences from %d = %0.2f\n",d, G);
	fprintf(fptr,"\n\n");
	fprintf(fptr,"Sn. \t Year \t I \t T \t G \t C \t\t Y\n");
	for(i=0;i<years;i++){
		I = 2 + 0.1 * Y;
		T = 0.2*Y;
		G = 0.15*G + G;
		C = 45.45 + 2.27*(I+G);
		Y = C + I + G;
		fprintf(fptr,"%d \t %d \t %0.2f \t %0.2f \t %0.2f \t %0.2f \t %0.2f \n", i+1, d+i+1,I, T, G, C, Y);
	}
	fprintf(fptr,"\n\nI = Investment\n");
	fprintf(fptr,"T = Tax\n");
	fprintf(fptr,"Government Expenses = G\n");
	fprintf(fptr,"Consumption = C\n");
	fprintf(fptr,"National income = Y\n");
}
