#include <cs50.h>
#include <stdio.h>

unsigned char SPACE = 32;
unsigned char HASHTAG = 35;

void writer(char character, int repeat){
  for(int i=0; i < repeat; i++){
    printf("%c",character);
  }
}

int main(void) 
{
    int height = 0;
    do
    {
      printf("Input Height (1->9): ");
      scanf("%i",&height);
    }
    while(height > 8 || height <1);
    //printf("Height: %i\n",height);
    for(int i= 1; i <= height; ++i){ 
      writer(SPACE,height-i);
      writer(HASHTAG,i);
      printf("  ");
      writer(HASHTAG,i);
      //writer(SPACE,height-i);
      printf("\n");
    }
}