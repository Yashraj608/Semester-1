#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char arr[6][5];
    int i, k = 0, j;
    int score = 0;
    srand(time(0));

   
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            arr[i][j] = 'A' + rand() % 26;  
        }
    }

    arr[5][0] = '1';
    arr[5][1] = '0';
    arr[5][2] = '3';
    arr[5][3] = '8';
    arr[5][4] = 'M';


    printf("SUBSCRIPT BLOCK\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    
    char str[50];
    size_t len;

    
    while (1) {
        printf("\nEnter string to search (type 'Q' to quit): ");
        fgets(str, 50, stdin);

       
        len = strlen(str);
        if (str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        // Exit condition
        if (strcmp(str, "Q") == 0) {
            break;
        }

       
        int found = 0;
        k = 0;

 
        for (i = 0; i < 6; i++) {
            k = 0; 
            for (j = 0; j < 5; j++) {
                if (str[k] == arr[i][j]) {
                    k++;
                    if (k == strlen(str)) {
                        score++;
                        printf("\n%s is present  Score: %d\n", str, score);
                        found = 1;
                        break;
                    }
                } else {
                    k = 0;
                }
            }
            if (found) break;
        }

      
        if (!found) {
            for (j = 0; j < 5; j++) {
                k = 0; 
                for (i = 0; i < 6; i++) {
                    if (str[k] == arr[i][j]) {
                        k++;
                        if (k == strlen(str)) {
                            score++;
                            printf("\n%s is present  Score: %d\n", str, score);
                            found = 1;
                            break;
                        }
                    } else {
                        k = 0;
                    }
                }
                if (found) break;
            }
        }
        if (!found) {
            score--;
            printf("\n%s is not present. Score: %d\n", str, score);
        }
    }

    printf("\nFinal Score: %d\n", score);
    return 0;
}

