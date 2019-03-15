#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


void sigmanager(int sig_num) {

	signal(sig_num, sigmanager);

  if ( sig_num == SIGSTOP ) {
		exit(sig_num);
	}
	else {
		printf("\n%s%d\n","Señal recibida: ",sig_num);
		if(sig_num==SIGINT){
			printf("%s\n","Ctrl^C");
		}
	}

	fflush(stdout);
}



	int main(){
		signal(SIGINT,sigmanager);
		signal(SIGSTOP,sigmanager);

		printf("%s\n","Esperando señal...");
		while(1){

		}
	}
