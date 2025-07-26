#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int validateEmail(char *email, int size) {
    if (email == NULL || size==0) 
	{
        return 0; 
    }

    int count = 0;
    int index = -1;
    int i;

    for (i=0;i<size;i++)
	 {
        if (email[i] == '@') {
            count++;
            index=i;
        }
    }

    if (count!=1) {
        return 0;
    }
    
    for (i=index + 1;i<size;i++) {
        if (email[i] == '.') {
            return 1;
        }
    }

    return 0;
}

	int main() 
{
    char *email;

    email = (char *)calloc(100, sizeof(char));
    if (email == NULL) {
    printf("Memory allocation failed\n");
    return 1;
    }
    
	printf("Enter the email: ");
	fgets(email, 100, stdin);
	
	size_t length=strlen(email);
	
	if(email[length-1]='\n'){
		email[length-1]='\0';
		--length;
	}
	email=(char*)realloc(email,(length+1)*sizeof(char));
	if(email==NULL){
		printf("Reallocation failed");
		exit(1);
	}
	int validate=validateEmail(email,length);
	
	if(validate==1){
	printf("\n Valid Email");
	}
	else
	printf("\nInvalid Email");
	
	free(email);

    return 0;
}

