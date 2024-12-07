//Kyle Kennedy
//Final Project

#include <stdio.h>
#define FILE_NAME "madlib1.txt"
#define MAX_LENGTH 200
#define MAX_ROWS 200

void print_file();
void file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH]);
void stringCopy(char[], char[]);
void stringSwap(char[], char[]);
//fucntion to pull from document(scan)
//function to display madlib
int main(){
	int  a, v, n, j, num_rows, countA=0, countN=0, countV=0;
	char row[MAX_ROWS][MAX_LENGTH], i, adjective[MAX_ROWS][MAX_LENGTH], noun[MAX_ROWS], verb[MAX_ROWS], adj[MAX_ROWS][MAX_LENGTH], ver[MAX_ROWS][MAX_LENGTH], non[MAX_ROWS][MAX_LENGTH];
	
	file_store(&num_rows, row);
	for(j=0; j<num_rows;j++){
		
		if(row[j][0] ==  'A'){
			printf("please enter an adjective: ");
			scanf("%s", adj[countA]);
			stringSwap(adj[countA],row[j]);
			countA++;
		}
		else if(row[j][0] ==  'N'){
			printf("please enter an noun: ");
			scanf("%s", &non[countN]);
			stringSwap(non[countN],row[j]);
			countN++;
		}
		else if(row[j][0] ==  'V'){
			printf("please enter an verb: ");
			scanf("%s", &ver[countV]);
			stringSwap(ver[countV],row[j]);
			countV++;
		}
//		else{
//			printf("%s", row[j]);
//		}
	}
	
	printf("countA: %d, countN: %d, countV: %d\n" , countA, countN, countV);
	for(j=0; j<num_rows;j++){
		printf("%s ", row[j]);
	}
	printf("\n");
	return 0;
}

void file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH]){

	
	FILE*fptr;
	fptr= fopen(FILE_NAME, "r");

	if(fptr==NULL){
		printf("nope!\n");
	}
	*num_rows=0;
	while(*num_rows<MAX_ROWS && fgets(row[*num_rows], MAX_LENGTH, fptr) !=NULL){
		
		(*num_rows)++;
	}
	fclose(fptr);
	
	printf("file_store\n");

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
	printf("print_file\n");
	}
void stringCopy(char source[], char dest[]) {
    int index = 0;
    while (source[index] != '\0') {
        dest[index] = source[index]; 
        index++;
    }
	dest[index] = '\0';
}
void stringSwap(char str1[], char str2[]) {
    char temp[MAX_LENGTH];
    stringCopy(str1, temp);
    stringCopy(str2, str1);
    stringCopy(temp, str2); 
}
