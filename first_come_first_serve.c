#include<stdio.h>
#include<stdlib.h>
void main(){
	int arr[5]={0,1,2,3,4};
	int bt[5]={2,3,4,5,6};
	int ct[5]={0},tt[5]={0},wt[5]={0};
	float tavg,wavg;
	int i;
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
		printf("\n%d\t%d\t%d\t%d\t%d\t\n",arr[i],bt[i],ct[i],tt[i],wt[i]);
	}
	
}
