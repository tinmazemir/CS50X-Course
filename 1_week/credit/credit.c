#include <cs50.h>
#include <stdio.h>


void whichCard(int numbers[],int arrayLength){
  //printf("arrayLength: %d -- start: %d%d\n",arrayLength,numbers[0],numbers[1]);
  if(arrayLength == 15 && numbers[0] == 3 && (numbers[1] == 4 || numbers[1] == 7)){ //American Express
    printf("AMEX\n");
  }
  else if( (arrayLength == 13 || arrayLength == 16) && numbers[0] == 4){ // Visa(arrayLength == 13 || arrayLength == 16) && 
    printf("VISA\n");
  }
  else if(arrayLength == 16 && numbers[0] == 5 && numbers[1] == 1 || numbers[1] == 2 || numbers[1] == 3 || numbers[1] == 4 || numbers[1] == 5){ //Master Card
    printf("MASTERCARD\n");
  }
  else{
    printf("--INVALID\n");
  }
}

void isValid(int numbers[],int arrayLength){
  int sumNum = 0;
  int multNum = 0;
  // for(int i=0; i < arrayLength; ++i){printf("%d",numbers[i]);} printf("\n"); //Card Numbers Control loop
  for(int i = 0; i < arrayLength; ++i){
    if(i % 2 != 0){
      //printf("sum__element: %d -- %d\n",i,numbers[i]);
      sumNum = sumNum + (numbers[i]);
    }
    else{
      //printf("mult__element: %d -- %d -- %d\n",i,numbers[i],(numbers[i]*2));       
      if(numbers[i]*2 > 9){
        multNum = multNum + (numbers[i]*2)/10 + (numbers[i]*2) % 10;
      }
      else{
        multNum = multNum + (numbers[i]*2);  
      }
    }
  }
  //printf("sumNum:%d -- multNum:%d -- checkSum:%d \n",sumNum,multNum,sumNum+multNum);
  
  if((sumNum + multNum) % 10 == 0){
    //printf("VALID\n");
    whichCard(numbers,arrayLength);
  }
  else{
    printf("INVALID\n");
  }
 
}


int main(void){
  long cardNum = get_long("Number: ");
  long tmpCardNum = cardNum;
  int counter = 0;
  do{ 
    tmpCardNum = tmpCardNum / 10; 
    ++counter; 
  }while(tmpCardNum != 0);

  //printf("Counter:-- %d --\n",counter);
  int cardNumArray[counter];
  int arrayLength = counter;
  tmpCardNum = cardNum;
  
  do{
    //printf("cardNumArray[%d]::%d ",counter-1,(int)tmpCardNum % 10);
    cardNumArray[counter-1] = tmpCardNum % 10;
    tmpCardNum = tmpCardNum / 10;
    --counter;
  }while(tmpCardNum != 0);

  isValid(cardNumArray,arrayLength);
}
