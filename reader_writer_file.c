#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *write,*read,*copy;
	char ch;
	write=fopen("open.txt","w");
	printf("Enter the data to write in the file");
	while((ch=getc(stdin))!='/'){
		fprintf(write,"%c",ch);
		
	}
	fclose(write);

	//read
	read=fopen("file_name.txt","r");
	copy=fopen("copy.txt","w");
	while((ch=getc(read))!=EOF){
		printf("%c",ch);
		fprintf(copy,"%c",ch);
	}

}
