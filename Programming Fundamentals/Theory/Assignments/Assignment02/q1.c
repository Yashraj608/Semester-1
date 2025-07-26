#include<stdio.h>
int main()
{
	int x[5],i,j=0;
	int temp[5];
	int min=9999,second_min=9999;
	printf("please input  5 values\n");
	for (i=0;i<5;i++){
		scanf("%d", &x[i]);
		if (x[i]>=9999){
			printf("\nplease enter value less than 9999\n");
			i--;
		}
		if (x[i]<min){
		    min=x[i];
		}
	
	}
	for (i=0;i<5;i++){
		if (x[i]<second_min && x[i]!=min){
			second_min=x[i];
		}
	}
	for (i=0;i<5;i++){
			printf("\nelement-%d:%d\n", i, x[i]);
	}
	printf("THE SECOND SMALLEST ELEMENT IN ARRAY IS :%d", second_min);
	
}
