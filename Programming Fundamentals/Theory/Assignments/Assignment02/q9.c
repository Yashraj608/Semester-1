#include<stdio.h>
#include<conio.h>
int main()
{
	char grid[5][5]={{' ', ' ', 'I', 'X', ' '},
                    {' ', 'X', ' ', ' ', ' '},
                    {'I', ' ', 'X', 'X', ' '},
                    {' ', ' ', ' ', 'I', 'X'}, 
					{' ', 'X', ' ', ' ', 'P'}};
	int k,i,j,a,b;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			printf(" %c || ", grid[i][j]);
		}
		printf("\n----------------------------\n");
	}
    for (i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
        	if (grid[i][j]=='P'){
        		a=i;
        		b=j;
			}
}
}
    char move;
    printf("\n PLEASE ENTER YOUR MOVE W FOR UP S FOR DOWN A FOR  LEFT AND D FOR RIGHT\n");
     printf("\n PLEASE PRESS Q IF YOU WANT TO QUIET THE GAME\n");
     
   do {
move=getch();//used for responsive input in console
   
     if (move=='W' || move =='w'){
     	if (grid[a-1][b]=='X' || ((a==0)&&(b==0))||((a==0)&&(b==1))||((a==0)&&(b==2))||((a==0)&&(b==3))||((a==0)&&(b==4)))
		 {
     		printf("\n INVALID MOVE\n");
		 }
		 else{
		  grid[a][b] = ' ';  
                a =a-1;             
                grid[a][b] = 'P';
		 }
	 }
	 if (move=='S' || move =='s'){
	 	if (grid[a+1][b]=='X' || ((a==4)&&(b==0))||((a==4)&&(b==1))||((a==4)&&(b==2))||((a==4)&&(b==3))||((a==4)&&(b==4)) ){
		 	printf("\n INVALID MOVE\n");
			 }
		 	else {
		 	 grid[a][b] = ' ';  
                a =a+1;            
                grid[a][b] = 'P';
			 }
		}
		if (move=='A' || move=='a'){
			if (grid [a][b-1]=='X' ||((a==0)&&(b==0))||((a==1)&&(b==0))||((a==2)&&(b==0))||((a==3)&&(b==0))||((a==4)&&(b==0))){
				printf("\n INVALID MOVE\n");
			}
			else {
				
			 grid[a][b] = ' ';  
                b=b-1;             
                grid[a][b] = 'P';
			}
		}
			if (move=='D' || move=='d'){
			if (grid [a][b+1]=='X' ||((a==0)&&(b==4))||((a==1)&&(b==4))||((a==2)&&(b==4))||((a==3)&&(b==4))||((a==4)&&(b==4))){
				printf("\n INVALID MOVE\n");
			}
			else {
				
			 grid[a][b] = ' '; 
                b=b+1;             
                grid[a][b] = 'P';
			}
}

			for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			printf(" %c || ", grid[i][j]);
		}
		printf("\n----------------------------\n");
	}
	printf("\n");
	
}

while (move!='Q' && move!='q');	
		
	 }
	 
	 
	 
	 
	 
   
    



