#include <stdio.h>
#include <string.h>

void compress(char a[])
{
    int i, j, k;
    int size=strlen(a);
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; a[j] != '\0'; j++)
        {
            if(a[j] == a[i])  
            {
                for(k = j; a[k] != '\0'; k++)
                {
                    a[k] = a[k + 1];
                }
                j--; 
            }
        }
    }
}

int main()
{
	int i;
	int x;
	printf("PLEASE INPUT THE NUMBER OF WORDS\n");
	scanf("%d", &x);
	getchar();
    char words[x][100];
    
   
    for ( i = 0; i < x; i++) {
    	  printf("Enter word %d: ", i + 1);
        fgets(words[i], 100, stdin);
		  words[i][strcspn(words[i], "\n")] = '\0'; 	
		}
    printf("\n");

    for ( i = 0; i < x; i++) {
        compress(words[i]);
    }
printf("output");
  printf("[");
    for ( i = 0; i < x; i++) {
        printf( "\"%s\"", words[i]);
         if (i < x - 1){
		  printf(", ");}
    }
     printf("]");


    return 0;
}

