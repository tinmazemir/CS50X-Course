#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{  
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2){
        printf("Player 1 wins!");
    }
    else if (score2 > score1){
        printf("Player 2 wins!");
    }
    else{
        printf("Tie!");
    }
  
    //printf("%d",compute_score("Code"));
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int point = 0;
    for (int i = 0; word[i] != '\0'; ++i)
    {
        //printf("%c",word[i]);
        for(int alp = 0; alp < 26; ++alp){
            if(word[i] == alphabet[alp]){
                point = point + POINTS[alp];
            }
            else if((int)word[i] - 32 == (int)alphabet[alp]){
                point = point + POINTS[alp];
            }
        }
    }  
    return point;
}
