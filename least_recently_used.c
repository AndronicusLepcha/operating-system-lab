int findUrl(int time[],int n){
	int i,min=time[0],pos=0;	
	for(i=1;i<n;++i){
		if(time[i]<min){
			min=time[i];
			pos=i;
		}
	}
	return pos;
}

#include<stdio.h>
#include<stdlib.h>
int main(){
int frame=3;
int page=6;
int pageFault=0;
int pageRef[6]={5,7,5,6,7,3};
int s,i,j,k,pos;
int counter=0;
int flag1=0,flag2=0;
int hit=0;
int temp[frame];
int time[10];
for(i=0;i<frame;++i){
	temp[i]=-1;
	}

for(j=0;j<page;++j){
	flag1=flag2=0;
	for(i=0;i<frame;++i){
		if(pageRef[j]==temp[i]){
			counter++;
			time[i]=counter;
			flag1=flag2=1;
			hit++;
			break;
		}
	if(flag1==0){
		for(i=0;i<frame;++i){
			if(temp[i]== -1){
				counter++;
				pageFault++;
				temp[i]=pageRef[j];
				time[i]=counter;
				flag2=1;
				break;
				}
			}
	
		}
	if(flag2==0){
		pos=findUrl(time,frame);
		counter++;
		pageFault++;
		temp[pos]=pageRef[j];
		time[pos]=counter;	
		}

		for(i=0;i<frame;i++){
			printf("%d\t",temp[i]);
		}
		printf("\n");
	}
}
		printf("page miss=%d",pageFault);
		printf("page hit=%d",hit);

}
