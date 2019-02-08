#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
static void *child(void *ignored){
  while(1){
    sleep(5);
    printf("Child Thread Sleeping\n");
  }
}

int main(int argc, char *argv[]){
  pthread_t child_thread;
  int code = pthread_create(&child_thread, NULL, child, NULL);
  printf("Child has spanwed\nHit ENTER to kill the child\n");
  scanf("Waiting User Input");
  pthread_cancel(child_thread);
  printf("The child is dead\n");
}
