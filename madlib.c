#include <stdio.h>

#define FILE_NAME "madlib2.txt"
#define MAX_LENGTH 200
#define MAX_ROWS 200

void file_store(int *num_rows, char row[MAX_ROWS][MAX_LENGTH]);
void stringCopy(char dest[], const char src[]);
void stringSwap(char str1[], char str2[]);
void condition_A(char adj[], char row[], int *countA);
void condition_N(char non[], char row[], int *countN);
void condition_V(char ver[], char row[], int *countV);
int length(const char str[]);
int punctuation(char p);

int main() {
    int a, v, n, j, num_rows, countA = 0, countN = 0, countV = 0;
    char row[MAX_ROWS][MAX_LENGTH], adj[MAX_ROWS][MAX_LENGTH], ver[MAX_ROWS][MAX_LENGTH], non[MAX_ROWS][MAX_LENGTH];

    file_store(&num_rows, row);

    // Process the rows and replace placeholders
    for (j = 0; j < num_rows; j++) {
        if (row[j][0] == 'A') {
            condition_A(adj[countA], row[j], &countA);
        } else if (row[j][0] == 'N') {
            condition_N(non[countN], row[j], &countN);
        } else if (row[j][0] == 'V') {
            condition_V(ver[countV], row[j], &countV);
        }
    }

    // Output the modified Madlib
    printf("\nYour Madlib:\n");
    for (j = 0; j < num_rows; j++) {
        printf("%s", row[j]);
    }

    return 0;
}

void file_store(int *num_rows, char row[MAX_ROWS][MAX_LENGTH]) {
    FILE *fptr;
    fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    *num_rows = 0;
    while (*num_rows < MAX_ROWS && fgets(row[*num_rows], MAX_LENGTH, fptr) != NULL) {
        int length = 0;
        while (row[*num_rows][length] != '\0') {
            if (row[*num_rows][length] == '\n') {
                row[*num_rows][length] = ' ';  // Replace newline with space
            }
            length++;
        }
        (*num_rows)++;
    }
    fclose(fptr);
}

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Null-terminate the string
}

void stringSwap(char str1[], char str2[]) {
    char temp[MAX_LENGTH];
    stringCopy(str1, temp);
    stringCopy(str2, str1);
    stringCopy(temp, str2);
}

void condition_A(char adj[], char row[], int *countA) {
    printf("Please enter an adjective: ");
    fgets(adj, MAX_LENGTH, stdin);

    // Remove newline character if present
    int len = length(adj);
    if (adj[len - 1] == '\n') {
        adj[len - 1] = '\0';
    }

    // Swap the input word with the placeholder
    stringSwap(adj, row);
    (*countA)++;
}

void condition_N(char non[], char row[], int *countN) {
    printf("Please enter a noun: ");
    fgets(non, MAX_LENGTH, stdin);

    // Remove newline character if present
    int len = length(non);
    if (non[len - 1] == '\n') {
        non[len - 1] = '\0';
    }

    // Swap the input word with the placeholder
    stringSwap(non, row);
    (*countN)++;
}

void condition_V(char ver[], char row[], int *countV) {
    printf("Please enter a verb: ");
    fgets(ver, MAX_LENGTH, stdin);

    // Remove newline character if present
    int len = length(ver);
    if (ver[len - 1] == '\n') {
        ver[len - 1] = '\0';
    }

    // Swap the input word with the placeholder
    stringSwap(ver, row);
    (*countV)++;
}

int length(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int punctuation(char p) {
    return (p == '!' || p == ',' || p == '.' || p == '?' || p == ';' || p == ':' || p == '"');
}


