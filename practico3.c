#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(){
	
	int pid=fork();

	if(pid==0){
		//hijo
		printf("\n%s\n\n","Proceso hijo:" );
		printf("%s%d\n","Pid: " ,getpid());
		printf("%s%d\n\n","Pid Padre: ",getppid());

	}
	else{
		//padre
		printf("\n%s\n\n","Proceso Padre:" );
		printf("%s%d\n","Pid: ",getpid());
		printf("%s%d\n","Pid Padre: ",getppid());
	}

	return 0;
}