#include <cs50.h>
#include <stdio.h>

int calculate(int startPopulation, int endPopulation){
  int year = 0;
  while(startPopulation < endPopulation){
    startPopulation = startPopulation + (int)(startPopulation/3) - (int)(startPopulation/4); 
    ++year;
    //printf("Population: %d -- Year: %d",startPopulation,year);

  }
  return year;
}

int main(void)
{
  int startPopulation = 0;
  int endPopulation = 0;
  int takeYears = 0;
   // TODO: Prompt for start size
  do
  {
    printf("Start size: ");
    scanf(" %d",&startPopulation);
  }
  while (startPopulation < 9 ); 
  printf("Start size: %d\n",startPopulation);
   
   // TODO: Prompt for end size
  do
  {
    printf("End size: ");
    scanf("%d",&endPopulation);
  }
  while (endPopulation < startPopulation);
  printf("End Size: %d\n",endPopulation);
    
    // TODO: Calculate number of years until we reach threshold
  takeYears = calculate(startPopulation,endPopulation);

    // TODO: Print number of years
  printf("Years: %d",takeYears);
}
