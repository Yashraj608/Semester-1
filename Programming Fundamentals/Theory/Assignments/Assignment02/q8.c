#include <stdio.h>
#include <math.h>
#include <string.h>

int decimaltobinary(int number) {
    int binary = 0, rem = 0, x = 1;
    int temp = number;
    while (number != 0) {
        rem = number % 2;
        number = number / 2;
        binary = binary + (rem * x);
        x = x * 10;
    }
    printf("The binary equivalent of %d is %d\n", temp, binary);
    return binary;  
}

int binarytodecimal() {
    int binary, decimal = 0, x = 1, rem;
    printf("Please enter a binary number: ");
    scanf("%d", &binary);
    int temp = binary;

    while (binary != 0) {
        rem = binary % 10;
        decimal = decimal + rem * x;
        binary = binary / 10;
        x = x * 2;
    }
    printf("The decimal equivalent of %d is %d\n", temp, decimal);
    return decimal;  
}

void decimaltohexadecimal(int number) {
    int rem, j,i = 0, temp = number;
    char hexa[50];
    
    while (number != 0) {
        rem = number % 16;
        if (rem < 10) {
            hexa[i] = rem + '0';
        } else {
            hexa[i] = rem - 10 + 'A';
        }
        number = number / 16;
        i++;
    }

    printf("The hexadecimal representation of %d is: ", temp);
    for ( j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

void hexadecimaltodecimal(char hexa[]) {
    int i,j = 0, decimal = 0;
    int size = strlen(hexa);

    for ( i = size - 1; i >= 0; i--) {
        if (hexa[i] >= '0' && hexa[i] <= '9') {
            decimal += (hexa[i] - '0') * pow(16, j);
        } else if (hexa[i] >= 'A' && hexa[i] <= 'F') {
            decimal += (hexa[i] - 'A' + 10) * pow(16, j);
        } else if (hexa[i] >= 'a' && hexa[i] <= 'f') {
            decimal += (hexa[i] - 'a' + 10) * pow(16, j);
        }
        j++;
    }
    printf("The decimal equivalent is %d\n", decimal);
}

void binarytohexadecimal(int number) {
    int decimal = 0, i = 0,k;
    char hex[20];
    int j = 0;


    while (number > 0) {
        int rem = number % 10;
        decimal += rem * pow(2, i);
        number = number / 10;
        i++;
    }

    
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[j] = '0' + remainder;
        } else {
            hex[j] = 'A' + (remainder - 10);
        }
        decimal = decimal / 16;
        j++;
    }

    printf("The hexadecimal equivalent is: ");
    for ( k = j - 1; k >= 0; k--) {
        printf("%c", hex[k]);
    }
    printf("\n");
}

void hexadecimaltobinary(char hexa[]) {
    int size = strlen(hexa);
    int i;

    printf("The binary equivalent is: ");
    for ( i = 0; i < size; i++) {
        switch (hexa[i]) {
            case '0':
			 printf("0000");
			  break;
            case '1':
			 printf("0001");
			  break;
            case '2':
			 printf("0010"); 
			 break;
            case '3':
			 printf("0011");
			  break;
            case '4':
			 printf("0100");
			  break;
            case '5':
			 printf("0101");
			  break;
            case '6':
			 printf("0110");
			  break;
            case '7':
			 printf("0111");
			  break;
            case '8':
			 printf("1000"); 
			 break;
            case '9':
			 printf("1001");
			  break;
            case 'A':
			 case 'a':
			  printf("1010"); 
			  break;
            case 'B':
			 case 'b':
			  printf("1011");
			   break;
            case 'C':
			 case 'c':
			  printf("1100"); 
			  break;
            case 'D':
			 case 'd':
			  printf("1101");
			   break;
            case 'E':
			 case 'e': 
			 printf("1110");
			  break;
            case 'F':
			 case 'f': 
			 printf("1111");
			  break;
            default:
			 printf("\nInvalid hexadecimal input.\n"); return;
        }
    }
    printf("\n");
}

int main() {
    int number;
    char hexa[50];
    int choice;

    printf("Choose a conversion:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            binarytodecimal();
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimaltobinary(number);
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimaltohexadecimal(number);
            break;
        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexa);
            hexadecimaltodecimal(hexa);
            break;
        case 5:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            binarytohexadecimal(number);
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexa);
            hexadecimaltobinary(hexa);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

