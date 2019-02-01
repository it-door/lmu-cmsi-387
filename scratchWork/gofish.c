#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ){
  int numbers[25]; 
  int numbersPointer = 0;
  int inputNum = 0;
  while (1){
    printf("Input a number to include: ");
    scanf("%d", &inputNum);
    if( inputNum == -9999) break;
    numbers[numbersPointer] = inputNum;
    numbersPointer += 1;
  }
  
  int numbersOperations = 0;
  for(int i = 0; i < numbersPointer; i++){
    numbersOperations += numbers[i];
  }
  printf("Sum of Numbers: %d\n", numbersOperations);
  printf("Average of Numbers: %f\n", (double)(numbersOperations / numbersPointer));
  
  char finalString[sizeof(char) * numbersPointer];
  for(int i = 0; i <= numbersPointer; i++){
    finalString[i] = (char)(numbers[i] + 48);
  }
  printf("string of numbers: %s\n", finalString);
}
