#include <cs50.h>
#include <stdio.h>

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
      int spaceTour;  
      for(spaceTour=0; spaceTour < height-i; ++spaceTour){
        printf(" ");
      }
      for (int hasTour = 0; hasTour < height-spaceTour; ++hasTour){
        printf("#");
      }
      printf("  ");
      for (int hasTour = 0; hasTour < height-spaceTour; ++hasTour){
        printf("#");
      }
      for(spaceTour=0; spaceTour < height-i; ++spaceTour){
        printf(" ");
      }
    printf("\n"); 
    }
}