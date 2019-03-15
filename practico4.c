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
		_exit(1);
	}else{
		returnst=wait(&status);
		if(returnst==-1){
			printf("%s\n", "Error proceso no creado");
			exit(0);
		}

		if(WIFEXITED(status)){
			printf("%s%d\n","Terminado, status=",WEXITSTATUS(status) );
		}
	}



	return 0;
}
