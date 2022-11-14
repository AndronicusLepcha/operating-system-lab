/********************************CPU SCHEDULING --> Bankers Algorithm***********************/

#include<stdio.h>
#include<stdlib.h>
void main(){
int n=5;
int m=3;
int ans[5];
int index=0;
int i,j,y,k;
int f[5]={0};
for(i=0;i<5;i++){
	printf("%d",f[i]);
}
printf("\n");
int alloc[5][3]={{0,1,0},
		{2,0,0},
		{3,0,2},
		{2,1,1},
		{0,0,2}};
int max[5][3]={{7,5,3},
		{3,2,2},
		{9,0,2},
		{2,2,2},
		{4,3,3}};
int need[5][3];

int avail[3]={3,3,2};

for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		need[i][j]=max[i][j]-alloc[i][j];
		//printf("%d",need[i][j]);
	}
}

//for(i=0;i<n;i++){
//	for(j=0;j<m;j++){
//		printf("%d\t",need[i][j]);
//	}	
//	printf("\n");
//}

for(k=0;k<n;k++){
	for(i=0;i<n;i++){
		if(f[i]==0){
			int flag=0;
			for(j=0;j<m;j++){
				if(need[i][j]>avail[j]){
					flag=1;
					break;
				}
			}

			if(flag==0){
				ans[index++]=i;
				for(y=0;y<m;y++){
					avail[y]=avail[y]+alloc[i][y];
					printf("%d\t",avail[y]);
					}
				f[i]=1;
				printf("\n");
			}
		}
	}
	}
	for(i=0;i<n;i++){
		printf("%d",f[i]);	
	}

int flag=1;
for(i=0;i<n;i++){
	if(f[i]=0){
		flag=0;
		printf("DEADLOCK");
	}	
}	

if(flag==1){
	printf("No Deadlock\n");
	for(i=0;i<n;i++){
		printf("p%d-->",ans[i]);
	}
}
	
}
