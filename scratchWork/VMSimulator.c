#include <stdio.h>
#include <stdlib.h>

int page [4096];

int randomInt(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main() {
  for(int i = 0; i < 4096; i++){
    page[i] = randomInt(0, 65535);
  }
}
