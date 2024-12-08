//Kyle Kennedy
//Final Project

#include <stdio.h>
#define FILE_NAME "madlib2.txt"
#define MAX_LENGTH 200
#define MAX_ROWS 200

void file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH]);
void stringCopy(char[], char[]);
void stringSwap(char[], char[]);
void condition_A(char adj[], char row[], int *countA);
void condition_N(char non[], char row[], int *countN);
void condition_V(char ver[], char row[], int *countV);
int length(char str[]);
//fucntion to pull from document(scan)
//function to display madlib
int main(){
	int  a, v, n, j, num_rows, countA=0, countN=0, countV=0;
	char row[MAX_ROWS][MAX_LENGTH], adj[MAX_ROWS][MAX_LENGTH], ver[MAX_ROWS][MAX_LENGTH], non[MAX_ROWS][MAX_LENGTH];
	file_store(&num_rows, row);
	for(j=0; j<num_rows;j++){
		if(row[j][0] ==  'A'){
			condition_A(adj[countA],row[j], &countA);
		}
		else if(row[j][0] ==  'N'){
			condition_N(non[countN],row[j], &countN);
		}
		else if(row[j][0] ==  'V'){
			condition_V(ver[countV],row[j], &countV);
		}
	}
	for(j=0; j<num_rows;j++){
		printf("%s", row[j]);
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
		int length=0;
		while(row[*num_rows][length] != '\0'){
			if(row[*num_rows][length] == '\n'){
				row[*num_rows][length]= ' ';
			}
			length++;
		}
		(*num_rows)++;
	}
	fclose(fptr);
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
void condition_A(char adj[], char row[], int *countA){
	printf("please enter an adjective: ");
	scanf("%s", adj);
	int len= length(adj);
	adj[len]= ' ';
	adj[len+1]= '\0';
	stringSwap(adj,row);
	*countA++;
}
void condition_N(char non[], char row[], int *countN){
	printf("please enter an noun: ");
	scanf("%s", non);
	int len= length(non);
	non[len]= ' ';
	non[len+1]= '\0';
	stringSwap(non,row);
	*countN++;
}
void condition_V(char ver[], char row[], int *countV){
	printf("please enter an verb: ");
	scanf("%s", ver);
	int len= length(ver);
	ver[len]= ' ';
	ver[len+1]= '\0';
	stringSwap(ver,row);
	*countV++;
}
int length(char str[]){
	int length=0;
	while(str[length] != '\0')
		length++;
	return length;
}
