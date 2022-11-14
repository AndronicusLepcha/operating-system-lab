#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *in ,*out;
	in=fopen("fcfs.txt","r");
	int arr[5];
	int bt[5];
	int ct[5]={0},tt[5]={0},wt[5]={0};
	float tavg,wavg;
	int i;
	//reading the arrival time;
	for(i=0;i<5;i++){
		fscanf(in,"%d,",&arr[i]);
	}
	//reading brust time;
	for(i=0;i<5;i++){
		fscanf(in,"%d,",&bt[i]);
	}
	fclose(in);
	out=fopen("result.txt","w");

	for(i=0;i<5;i++){
		if(i==0){
			ct[i]=bt[i];
		}
		else{
			ct[i]=ct[i-1]+bt[i];
		}
	tt[i]=ct[i]-arr[i];
	wt[i]=tt[i]-bt[i];

	}
	printf("AT\t BT\t CT\t TT\t WT\t");
	for(i=0;i<5;i++){
		fprintf(out,"\n%d\t%d\t%d\t%d\t%d\t\n",arr[i],bt[i],ct[i],tt[i],wt[i]);
	}
	fclose(out);
	
}
