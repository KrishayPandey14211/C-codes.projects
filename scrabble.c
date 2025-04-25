#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string s);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string s)
{
    int score = 0;
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
        {
            int point = toupper(s[i]) - 65;
            score = score + POINTS[point];
        }
    }
    return score;
}
