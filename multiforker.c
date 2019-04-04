#include <unistd.h>
int main(int argc, char **argv){
  int i;
  sleep(1);
  for(i = 0; i < 3; i++){ /* loops 3 times */
    sleep(1);
    fork(); /* each time calling fork */
  }
  sleep(30); /* then sleeps 30 seconds */
}
