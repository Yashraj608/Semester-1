#include <stdio.h>

void count(int a[], int x) {
    int max = -9999, count = 0, i;
    for (i = 0; i < x; i++) {
        scanf("%d", &a[i]);
        count++;
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("COUNT = %d\n", count);
    horizontalhistogram(a, x);  
    verticalhistogram(a, max, x); 
}

void horizontalhistogram(int a[], int count) {
    int i, j;
    printf("HORIZONTAL HISTOGRAM\n");
    for (i = 0; i < count; i++) {
        printf("Value %d  ", i + 1);
        for (j = 0; j < a[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void verticalhistogram(int a[], int max, int count) {
    int i, j;
    printf("VERTICAL HISTOGRAM\n");
    for (i = max; i > 0; i--) { 
        for (j = 0; j < count; j++) {
            if (a[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int x;
    printf("PLEASE ENTER HOW MANY NUMBERS WILL YOU INPUT\n");
    scanf("%d", &x);
    printf("PLEASE INPUT NUMBERS\n");

    int a[x];
    count(a, x);  

    return 0;
}

