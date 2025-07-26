#include<stdio.h>
int matchstickwin(int n){
	if (n%5==0){
		return -1;
	}
		if(n<5){
		
		return n;
	}
	
	else{
		return 4;
	}
}
int main()
{
	int n;
	int x;
	printf("\nINPUT THE TOTAL NUMBER OF MATCHSTICKS\n");
	scanf("%d", &n);
	x=matchstickwin(n);
	printf("%d", x);
}
