//Kyle Kennedy
//Final Project

#include <stdio.h>

#define MAX_LENGTH 200
#define MAX_ROWS 200

void file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH], char *filename);
void stringCopy(char[], char[]);
void stringSwap(char str1[], char str2[], int length);
void condition_A(char adj[], char row[], int *countA);
void condition_N(char non[], char row[], int *countN);
void condition_V(char ver[], char row[], int *countV);

int main(int argc, char*argv[]){
	char *filename=argv[1];
	int  a, v, n, j, num_rows, countA=0, countN=0, countV=0;
	char row[MAX_ROWS][MAX_LENGTH], adj[MAX_ROWS][MAX_LENGTH],ver[MAX_ROWS][MAX_LENGTH], non[MAX_ROWS][MAX_LENGTH], temp[MAX_ROWS][MAX_LENGTH];
	
	file_store(&num_rows, row, filename);
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
		int length=0;
		while(row[j][length] != '\0'){
			if(row[j][length] == '\n'){
				row[j][length]= ' ';
			}
			length++;
		}
		printf("%s", row[j]);
	}
	printf("\n");
	return 0;
}
void file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH],char *filename){
	FILE*fptr;
	fptr= fopen(filename, "r");

	if(fptr==NULL){
		printf("nope!\n");
	}
	*num_rows=0;
	while(*num_rows<MAX_ROWS && fgets(row[*num_rows], MAX_LENGTH, fptr) !=NULL){
		(*num_rows)++;
	}
	fclose(fptr);
}
void stringCopy(char source[], char dest[]){
	int index = 0;
	while (source[index] != '\0'){
		dest[index] = source[index]; 
		index++;
	}
	dest[index] = '\0';
}
void stringSwap(char str1[], char str2[], int length){
	int i = 0;
	while (str1[i] != '\0' && i < length){
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
}
void condition_A(char adj[], char row[], int *countA){
	printf("please enter an adjective: ");
	scanf("%s", adj);
	stringSwap(adj, row, MAX_LENGTH);
	int len = 0;
	while (row[len] != '\0'){
		len++;
	}
	row[len] = ' '; 
	row[len + 1] = '\0';	
	*countA++;
}
void condition_N(char non[], char row[], int *countN){
	printf("please enter an noun: ");
	scanf("%s", non);
	stringSwap(non, row, MAX_LENGTH);
	int len = 0;
	while (row[len] != '\0'){
		len++;
	}
	row[len] = ' ';
	row[len + 1] = '\0'; 
	*countN++;
}
void condition_V(char ver[], char row[], int *countV){
	printf("please enter an verb: ");
	scanf("%s", ver);
	stringSwap(ver, row, MAX_LENGTH);
	int len = 0;
	while (row[len] != '\0'){
		len++;
	}
	row[len] = ' '; 
	row[len + 1] = '\0'; 
	*countV++;
}

