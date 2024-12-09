#include<stdio.h>
#include<string.h>

typedef struct Player
{
    int ball_scores[12];
    char player_name[50];
    int total_score;
} Player;


int validate_score(int strike) 
{
    return (strike >= 0 && strike <= 6);
}

void playGame(Player *player) 
{
    printf("\n%s, it's your turn!\n", player->player_name);
    player->total_score = 0;

    for (int i = 0; i < 12; i++) 
	{
        printf("enter score for ball: ");
        int strike;
        scanf("%d", &strike);

        if (validate_score(strike)) 
		{
            player->ball_scores[i] = strike;
            player->total_score += strike;
        } 
		else 
		{
            player->ball_scores[i] = 0;
            printf("invalid score, score = o");
        }
    }
}

void findWinner(Player player1, Player player2) 
{
    printf("\n\tMatch Result \n");
    if (player1.total_score > player2.total_score) 
	{
        printf("winner: %s with %d runs!\n", player1.player_name, player1.total_score);
    } 
	
	else if (player2.total_score > player1.total_score) 
	{
        printf("winner: %s with %d runs!\n", player2.player_name, player2.total_score);
    } 
    
	else 
	{
        printf("tie");
    }
}

void displayMatchScoreboard(Player player1, Player player2) 
{
    printf("\n\tscoreboard\n");

    for (int i = 0; i < 2; i++) 
	{
        Player player = (i == 0) ? player1 : player2;
        printf("\n%s's Performance:\n", player.player_name);
        printf("Ball scores: ");
        
        for (int j = 0; j < 12; j++)
            printf("%d ", player.ball_scores[j]);
        
        double average_score = (double)player.total_score / 12;
        printf("\ntotal score: %d\n", player.total_score);
        printf("average score: %.2f\n", average_score);
    }
}

int main() {
    Player player1, player2;

    printf("enter Player 1's name: ");
    fgets(player1.player_name, sizeof(player1.player_name), stdin);
    player1.player_name[strcspn(player1.player_name, "\n")] = '\0';

    printf("Enter Player 2's name: ");
    fgets(player2.player_name, sizeof(player2.player_name), stdin);
    player2.player_name[strcspn(player2.player_name, "\n")] = '\0';

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    return 0;
}

