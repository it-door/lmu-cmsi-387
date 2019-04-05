#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){
  pid_t returnedValue = fork();
  if(returnedValue < 0){
    perror("error forking");
    return -1;
  } else if (returnedValue == 0){
    
    /*if(close(STDOUT_FILENO) < 0){
      perror("error closing standard output");
      return -1;
    }*/
    // When there is no error, open returns the smallest file
    // descriptor not already in use by this process, so having
    // closed STDOUT_FILENO, the open should reuse that number.
    int fd = open("/etc/passwd", O_RDONLY) ;
    if(fd < 0){
      perror("error opening /etc/passwd");
      return -1;
    }
    dup2(fd, 0);
    execlp("tr", "tr", "a-z", "A-Z", NULL); 

    perror("error executing ps");
    return -1;
  } else {
    if(waitpid(returnedValue, 0, 0) < 0){
      perror("error waiting for child");
      return -1;
   }
  printf("\nNote the parent still has the old standard output.\n");
  }
}
