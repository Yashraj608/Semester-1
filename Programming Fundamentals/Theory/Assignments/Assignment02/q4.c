#include <stdio.h>
#include <string.h>

int main() {
    int size;
    printf("How many transaction strings do you have? : ");
    scanf("%d", &size);
    getchar();
    
    char str[size][100], temp[size][100];
    int i, j, k;  
    char tempv;
    int len;
    int arr[size][size];
    
    // Input strings
    for (i = 0; i < size; i++) {
        printf("Enter transaction string %d : ", i + 1);
        scanf("%s", str[i]);
        strcpy(temp[i], str[i]);
    }

    
    for (i = 0; i < size; i++) {
        len = strlen(temp[i]);
        for (j = 0; j < len - 1; j++) {
            for (k = 0; k < len - j - 1; k++) {
                if (temp[i][k] > temp[i][k + 1]) {
                    tempv = temp[i][k + 1];
                    temp[i][k + 1] = temp[i][k];
                    temp[i][k] = tempv;
                }
            }
        }
    }

    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            arr[i][j] = -1;
        }
    }

    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (strcmp(temp[i], temp[j]) == 0) {
                arr[i][j] = j;
            }
        }
    }

    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            for (k = 0; k < size; k++) {
                if (arr[i][k] == arr[j][k]) {
                    arr[j][k] = -1;
                }
            }
        }
    }

    
    printf("\n\nThe anagrams grouped are: ");
    for (i = 0; i < size; i++) {
        int present = 0;
        for (j = 0; j < size; j++) {
            if (arr[i][j] != -1) {
                present++;
            }
        }
        if (present) printf("[");
        for (j = 0; j < size; j++) {
            if (arr[i][j] != -1) {
                printf(" '%s' ", str[j]);
            }
        }
        if (present) printf("]  ");
    }

    return 0;
}

