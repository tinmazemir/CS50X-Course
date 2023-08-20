#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int gradeCalc(string text);

int main(void) 
{
   string text = get_string("Text: ");
   int grade = gradeCalc(text);

   if(grade > 0  && grade < 16){
      printf("Grade %d\n",grade);
   }
   else if(grade >= 16){
      printf("Grade 16+\n");
   }
   else{
      printf("Before Grade 1\n");
   }
}

int gradeCalc(string text){
   float index = 0; // grade level before
   float avgNumLetters = 0.0; // letters/words*100
   float avgNumSentence = 0.0; // sentence/words*100
   float numLetters = 0;
   float numSentence = 0;
   float numWords = 1;
   
   for(int i = 0; text[i] != '\0'; ++i){
      if(text[i] == '?' || text[i] == '!' || text[i] == '.'){
         numSentence++;
      }
      if(text[i] == ' ' ){
         numWords++;
      }
      if(text[i] != ' ' && text[i] != '?' && text[i] != '!' && text[i] != '.' && text[i] != ',' && text[i] != 39 && text[i] != '"'){
         // 39 is dec ASCII number of ' 
         //printf("%c",text[i]);
         numLetters++;
      }
   }

   //printf("Sentence: %f -- Words: %f -- Letters: %f\n",numSentence,numWords,numLetters);
   avgNumLetters = (numLetters/numWords)*100; 
   avgNumSentence = (numSentence/numWords)*100; 
   //printf("avgNumLetters: %f -- avgNumSentence %f\n",avgNumLetters,avgNumSentence);
   index =  0.0588 * avgNumLetters - 0.296 * avgNumSentence - 15.8;
   //printf("INDEX:%d\n",index);
   index = round(index);
   return index;
}