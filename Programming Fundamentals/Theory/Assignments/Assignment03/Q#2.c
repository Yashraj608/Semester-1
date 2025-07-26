#include<stdio.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalscore;
};

int validateScore(int score) {
    if (score >= 0 && score <= 6) {
        return 1;
    }
    return 0;
}

void playGame(struct Player *player) {
    (*player).totalscore = 0;
    int i;
    for ( i = 0; i < 12; i++) {
        printf("Score for %s's ball %d: ", (*player).playerName, i + 1);
        scanf("%d", &(*player).ballScores[i]);
        if (validateScore((*player).ballScores[i])) {
            (*player).totalscore += (*player).ballScores[i];
        } else {
            printf("\nInvalid score! Marking as 0.\n");
            (*player).ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalscore > player2.totalscore) {
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalscore);
    } else if (player2.totalscore > player1.totalscore) {
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalscore);
    } else {
        printf("Oh! It is a tie. Both players scored %d.\n",
		 player1.totalscore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) 
{
    printf("%s Scores: ", player1.playerName);
    int i;
    for ( i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score for %s: %d\n", player1.playerName, player1.totalscore);

    printf("%s's Scores: ", player2.playerName);
    for ( i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score for %s: %d\n", player2.playerName, player2.totalscore);
}

int main() {
    struct Player Player1, Player2;

    printf("Enter the name for Player 1: ");
    scanf("%s", Player1.playerName);
    playGame(&Player1);

    printf("\nEnter the name for Player 2: ");
    scanf("%s", Player2.playerName);
    playGame(&Player2);
    
    printf("\nWinner!!!!!!!:\n");
    findWinner(Player1, Player2);

    printf("\nMatch Scorecard:\n");
    displayMatchScoreboard(Player1, Player2);


    return 0;
}

