#include<stdio.h>
#include<stdlib.h>
int main(){
int frame=3;
int page=8;
int pageFault=0;
int pageRef[10]={7,0,1,2,0,3,0,4,2,3};
int s,i,j,k;
int hit=0;
int temp[frame];
for(i=0;i<frame;i++){
	temp[i]=-1;
	}
for(j=0;j<page;j++){
		s=0;
		for(k=0;k<frame;k++){
				if(pageRef[j]==temp[k]){
					s++;
					//pageFault--;
					hit++;
				}
			}

		pageFault++;
		if((pageFault<=frame) &&(s==0)){
				temp[j]=pageRef[j];
			}
		else if(s==0){
			temp[(pageFault-1)%frame]=pageRef[j];
			}
		for(i=0;i<frame;i++){
			printf("%d\t",temp[i]);
		}
		printf("\n");
		}
		printf("page miss=%d",pageFault);
		printf("page hit=%d",hit);
}
