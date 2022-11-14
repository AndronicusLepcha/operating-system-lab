#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *write,*read,*copy;
	int arrival[5],s2[30];
	int a,b,i;
	read=fopen("table.txt","r");
	//printf("Enter the data to write in the file");
	//fscanf(read,"%s\t %s",a,b);
	//printf("%s \t %s\n",a,b);
	for(i=0;i<5;i++)
	{
		fscanf(read,"%d,",&arrival[i]);
		//printf("%d",s1[3]);
	}
	for(i=0;i<5;i++)
	{
	//	fscanf(read,"%d",&s2[30]);
	printf("%d",arrival[i]);
	}
	fclose(read);

}
