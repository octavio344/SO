#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	
	int pid=fork();

	if(pid==0){
		printf("%s\n", "Hijo");
	}else{
		printf("%s\n","Padre");
	}

	return 0;

}