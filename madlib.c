//Kyle Kennedy
//Final Project

#include <stdio.h>
#define FILE_NAME "madlib2.txt"
int row_count();
void print_file();
//fucntion to pull from document(scan)
//function to display madlib
int main(){
	int i, row;
	char character[256], ch;
		row_count();
		print_file();
	//	character[i]=i;
	//	printf("%c", character[i]);
	printf("row=%d\n", row);
	
//if row contains A||N||V replace with a== adverb n==noun v==verb... if string==
	
	return 0;
}
int row_count(){
int i, row;
	char character[256], ch;
	FILE*fptr;
	fptr= fopen(FILE_NAME, "r");
	if(fptr==NULL){
		printf("nope!\n");
	}
while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			row++;
		}
	}
	printf("\n");
	printf("%d\n", row);
	printf("end\n");
	fclose(fptr);
	return row;
}
void print_file(){
	int i;
FILE*fptr;
	fptr= fopen(FILE_NAME, "r");
	if(fptr==NULL){
		printf("nope!\n");
	}
	while(fscanf(fptr, "%c", &i)==1){
		printf("%c", i);
	}
	fclose(fptr);
}
