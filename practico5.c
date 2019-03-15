#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<unistd.h>

int main()
{
	int pid=fork();
	int status;
	int returnst;


	if(pid==-1){
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	if(pid==0){
		//hijo
		printf("\n%s\n\n","Proceso hijo:" );
		printf("%s%d\n","Pid: " ,getpid());
		//exit(1);
		while(1){

			// ESpera que muera

		}
}
	else{
		returnst=wait(&status);
		printf("%s\n","Su hijo murio" );
		if(returnst==-1){
			perror("Pid");
		}

		if(WIFEXITED(status)){
			printf("%s%d\n","El proceso hijo finalizo correctamente, status=",WEXITSTATUS(status) );
		}
		if(WIFSIGNALED(status)){
			printf("%s%d\n","El proceso hijo termino debido a una señal, signal= ",WTERMSIG(status));
		}
	}



	return 0;
}
