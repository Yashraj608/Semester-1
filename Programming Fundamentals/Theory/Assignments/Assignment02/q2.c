#include<stdio.h>
#include<string.h>

void countFrequency(char slogan[]) {
    int f[256] = {0};  
    int i;

    for (i = 0; slogan[i] != '\0'; i++) {
        f[slogan[i]]++;
    }

    printf("For %s: {", slogan);

    for (i = 0; i < 256; i++) {
        if (f[i] > 0) {
            
            printf("'%c': %d,", i, f[i]);
        }
    }
    printf("}\n");
}

int main() {
    int x;
    printf("PLEASE ENTER NUMBER OF SLOGANS: ");
    scanf("%d", &x);
    getchar();  

    char slogan[x][100];  
    int i, j;

    for (i = 0; i < x; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogan[i], 100, stdin);
        if (slogan[i][strlen(slogan[i]) - 1] == '\n') {
            slogan[i][strlen(slogan[i]) - 1] = '\0';
        }
    }

    for (j = 0; j < x; j++) {
        countFrequency(slogan[j]);
    }

    return 0;
}

