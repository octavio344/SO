#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int pid;


void sigmanager(int sig_num) {

	signal(sig_num, sigmanager);

if(pid==0){

  if( sig_num == SIGTERM) {
    exit(sig_num);
  }

  if ( sig_num == SIGSTOP ) {
		exit( sig_num );
	}
	else {
		printf("\n%s%d\n","Señal recibida: ",sig_num);
		if(sig_num==SIGINT){
			printf("%s\n","Ctrl^C");
		}
	}
}else{
  printf("%s%d\n","Papa esta mandando la señal al hijo--->", sig_num );
  kill( pid, sig_num );
}
	fflush(stdout);
}




 int main ( int argc, char const *argv[] ) {

   int status;

   printf("%s\n","Esperando señales..." );

  pid=fork();

  //printf("%s%d\n"," PID: ",pid );


  signal(SIGTERM,sigmanager);


if( pid==0 ){
    while(1){
      //esperando
    }
}else{
    printf("%s%d\n","Pid: ", getpid() );
    wait(&status);
}

  return 0;
}
