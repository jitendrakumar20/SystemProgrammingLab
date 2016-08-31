#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void handler(int sig){
	printf("I can also hear you, Raju!\n");

}

int main(){
	
	pid_t parentid;
	parentid = getppid();
	
	//printf("test1\n");

	signal(SIGUSR1,handler);

	kill(parentid,SIGUSR1);

	pause();
	
	kill(parentid,SIGUSR1);
	
	return 0;
}