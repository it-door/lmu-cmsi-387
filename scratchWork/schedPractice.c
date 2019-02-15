#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ){
  if (argc % 2 != 1 || argc == 1){
    printf("improper number of arguments\n");
    exit(1);
  }

  int timeRemaining[(argc - 1) / 2];
  int numberOfThreads = (argc - 1) / 2;
  int totalTimeRemaining = 0;

  for(int i = 2; i < argc; i+= 2){
    timeRemaining[((i/2) - 1)] = atoi(argv[i]);
    totalTimeRemaining += atoi(argv[i]);
  }
  while(totalTimeRemaining > 0){
    for(int i = 0; i < numberOfThreads; i++ ){
      if (timeRemaining[i] > 40){
        timeRemaining[i] -= 40;
        totalTimeRemaining -= 40;
        printf("%s:40:%d\n", argv[(2 * i) + 1], timeRemaining[i]);
      } else {
        if(timeRemaining[i] > 0){
          printf("%s:%d:DONE\n", argv[(2 * i) + 1], timeRemaining[i]);
          totalTimeRemaining -= timeRemaining[i];
          timeRemaining[i] = 0;
        }
      }
    }
  }

}
