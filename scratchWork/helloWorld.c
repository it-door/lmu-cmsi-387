#include <stdio.h>
#include <stdlib.h>


int main( int argc, char* argv[] ){
  char name[25];
  printf("Input your name!\n> ");
  gets(name);
  printf("Your name is: %s\n", name);
  exit(0);
}
