//Kyle Kennedy
//Final Project

#include <stdio.h>
#define FILE_NAME "madlib1.txt"
#define MAX_LENGTH 200
#define MAX_ROWS 200

void print_file();
char file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH]);
//fucntion to pull from document(scan)
//function to display madlib
int main(){
	int  a, v, n, j, num_rows, countA=0, countN=0, countV=0;
	char row[MAX_ROWS][MAX_LENGTH], i, adjective[MAX_ROWS], noun[MAX_ROWS], verb[MAX_ROWS], adj[MAX_ROWS][MAX_LENGTH], ver[MAX_ROWS][MAX_LENGTH], non[MAX_ROWS][MAX_LENGTH];
	
	file_store(&num_rows, row);
	for(j=0; j<num_rows;j++){
		
		if(row[j][0] ==  'A'){
			
			printf("please enter an adjective: ");
			scanf("%s", &adj[countA]);
			adjective[countA]=row[j][0];
			countA++;
		}
		else if(row[j][0] ==  'N'){
			printf("please enter an noun: ");
			scanf("%s", &non[countN]);
			noun[countN]=row[j][0];
			countN++;
		}
		else if(row[j][0] ==  'V'){
			printf("please enter an verb: ");
			scanf("%s", &ver[countV]);
			verb[countV]=row[j][0];
			countV++;
		}
		else{
		printf("%s", row[j]);
		}
	}
	printf("countA: %d, countN: %d, countV: %d\n" , countA, countN, countV);
	for(a=0;a<countA;a++){
		printf("%c\n", adjective[a]);
		printf("adjectives\n");
		}
	for(n=0;n<countN;n++){
		printf("%c\n", noun[n]);
		printf("nouns\n");
		}
	for(v=0;v<countV;v++){
		printf("%c\n", verb[v]);
		printf("verbs\n");
		}
	for(a=0;a<countA;a++){
		printf("%s\n", adj[a]);
		printf("adjective\n");
		}
	for(n=0;n<countN;n++){
		printf("%s\n", non[n]);
		printf("noun\n");
		}
	for(v=0;v<countV;v++){
		printf("%s\n", ver[v]);
		printf("verb\n");
		}	
	printf("\n");
	return 0;
}

char file_store(int*num_rows,char row[MAX_ROWS][MAX_LENGTH]){

	
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
