#include <stdio.h>
#include <windows.h> 
#include <string.h> 
//return wali chizein samajh ni ayin is program mein
char game[3][3]; //main ke bahir kese declare kr rahe char or int
int currentplayer=1;

void loadingScreen() {
    printf("\n\n\n\n\t\t\t\tTic-Tac-Toe\n\n\t\t\tLoading ");
    for (int i = 0; i < 20; i++) {
        printf("=");
        fflush(stdout);  // Ensure each '#' prints immediately
        Sleep(100);      // Delay for loading animation in milliseconds
    }
    printf("\n\n");
    Sleep(1000);         // Pause before moving to the next screen
    system("cls");       // Clear screen for Windows CLI
}
void InitializeBoard()  //Used to initialize the board.Declared n as char
						//n is incremented as all the numbers in ASCII table are in sequence
{
	char n='1';
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			game[i][j]=n;
			n=n+1;
		}
	}  
}

void DisplayBoard()
{
	printf("+---+---+---+\n"); //upper header line
	for (int i=0;i<3;i++)
	{
		printf("|");//intial column break
		for (int j=0;j<3;j++)
		{
			printf(" %c |",game[i][j]); //next column break + last column break
		}
		printf("\n");
		printf("+---+---+---+\n"); //Footer line
	}
}

int PlayerMove(char name1[],char name2[])
{
	int position,row,col;
	if (currentplayer==1) // Name 1 's turn
	{
		printf(" -) Where would you like to place your 'X' %s : ",name1);
	}
	else if (currentplayer==2)  // Name 2 's turn
	{
		printf(" -) Where would you like to place your 'O' %s : ",name2);
	}
	scanf("%d", &position);
	if (position<1 || position>9)  //check validity of the input if it is between 1 & 9 accept itelse display invalid position entered
	{
		printf(" -) Invalid position entered\n");
		return 0;
	}
	else
	{ //ye samjha pura
		row=(position-1)/3;  //row=(position-1)/3 (formula for calculating row number)
		col=(position-1)%3; //col=(position-1)%3  (formula for calculating col number)
		if (game[row][col]=='X'||game[row][col]=='O') //check if the position is already occupied
		{
			printf(" -) Already occupied\n");
			return 0;  //if already occupied return 0
		}
		else
		{
			if (currentplayer==1)// if currentplayer is 1 insert X at the calculated row and col and update value of current player to 2
			{
				game[row][col]='X';
				currentplayer=2;
			}
			else// if currentplayer is 2 insert O at the calculated row and col and update value of current player to 1
			{
				game[row][col]='O';
				currentplayer=1;
			}
			return 1;  // if insertion successful return 1
		} 
	}

}

int CheckWin()
{
	if (game[0][0]==game[0][1] && game[0][1]==game[0][2])  // checking row 0 
	{
		if (game[0][0]=='X')
		{
			return 1;  //checking who won
		}
		else
		{
			return 2;
		}
	}
	else if (game[1][0]==game[1][1] && game[1][1]==game[1][2]) //checking row 1 
	{
		if (game[1][0]=='X')
		{
			return 1;//checking who won
		}
		else
		{
			return 2;
		}
	}
	else if (game[2][0]==game[2][1] && game[2][1]==game[2][2]) //checking row 2
	{
		if (game[2][0]=='X')
		{
			return 1;  //checking who won
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][0]==game[1][0] && game[1][0]==game[2][0]) //checking col 0
	{
		if (game[0][0]=='X')
		{
			return 1; //checking who won  return 1 if player 1 won
		}
		else
		{
			return 2;  //else return 2 as player 2 won
		}  
	}
	else if (game[0][1]==game[1][1] && game[1][1]==game[2][1]) //checking col 0
	{
		if (game[0][1]=='X')
		{
			return 1; //checking who won
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][2]==game[1][2] && game[1][2]==game[2][2]) //checking col 1
	{
		if (game[0][2]=='X')  //checking who won
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][0]==game[1][1] && game[1][1]==game[2][2]) //checking col 2
	{
		if (game[0][0]=='X')   //checking who won
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][2]==game[1][1] && game[1][1]==game[2][0]) //checking diagonally
	{
		if (game[0][2]=='X')   //checking who won
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{	 
		return 0; //return 0 if no one won
	} 
	
}

int CheckTie()
{
	int flag=0;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (game[i][j]>='1' && game[i][j]<='9')  //checking is there is any grid left where there is niether X nor O
			{
				flag=1; //if a single such grid is found flag will be updated to 1 loop will be force stopped and at the end of function 0 will be returned meaning game is not tied 
				break;
			}
		}
		if (flag==1)
		{
			break;
		}
	}
	if (flag==0) //game has tied
	{
		return 1;
	}
	else
	{
		return 0; // game is stil left
	}
}
int main() 
{
	loadingScreen();
	printf("\t\t\t\t---- Welcome to Tic Tac Toe ---\n\n");
	printf(" -) Creators : Syed Sultan Ahmed | Muhammad Taha Anwar | Yash Raj\n\n");
	InitializeBoard();
	char player1[50];
	char player2[50];
	printf(" -) Enter the name of Player 1 : ");
	gets(player1);
	printf(" -) Enter the name of Player 2 : ");
	gets(player2);
	Sleep(1000);         // Short pause before starting game
    system("cls");
	printf("\n\t The Game begins\n\t==================\n\n");
	printf("Player 1 : %s\nPlayer 2 : %s\n\n", player1, player2);
	int flag=0;
	while(flag==0)
	{
		DisplayBoard();
		if (PlayerMove(player1,player2)==0)
		{
			continue;  //position occupied leave next part of iteration restart it
		}
		if (CheckWin()==1) // if is returned from check win it means that Player 1 has won
		{
			DisplayBoard();
			printf("\t%s wins\n",player1);
			flag=1;
		}
		else if(CheckWin()==2) //if 2 is returned from Check Win it means that Player 2 has won
		{
			DisplayBoard();
			printf("\t%s wins\n",player2);
			flag=1;
		}
		else if(CheckTie()==1)  //if check tie returns 1 break the loop as the game has ended
		{
			DisplayBoard();
			printf("\t Game is tied\n");
			flag=1;
		}
	}
}