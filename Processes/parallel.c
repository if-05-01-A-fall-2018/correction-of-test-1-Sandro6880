#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char* arguments[4] = {"ls","df","ps","pwd"};
char* modes[2] = {" ", 0};


int main(int argc, char const *argv[]) {
  printf("Forking ls thread\n");
  pid_t pid_ls = fork();
  if(pid_ls == 0){
    modes[0] = arguments[0];
    execvp(arguments[0],modes);
  }
  printf("Forking df thread\n");
  pid_t pid_df = fork();
  if(pid_df == 0){
    modes[0] = arguments[1];
    execvp(arguments[1],modes);
  }
  printf("Forking ps thread\n");
  pid_t pid_ps = fork();
  if(pid_ps == 0){
    modes[0] = arguments[2];
    execvp(arguments[2],modes);
  }
  printf("Forking pwd thread\n");
  pid_t pid_pwd = fork();
  if(pid_pwd == 0){
    modes[0] = arguments[3];
    execvp(arguments[3],modes);
  }
  if(pid_ls != 0||pid_df != 0||pid_ps != 0||pid_pwd != 0){
    printf("Wait for threads to finish!\n");
  }
  waitpid(-1,0,0);
  waitpid(-1,0,0);
  waitpid(-1,0,0);
  waitpid(-1,0,0);

  printf("Done\n");

  return 0;
}
