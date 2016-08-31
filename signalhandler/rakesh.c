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

	//printf("test4\n");

	signal(SIGUSR2,handler);
	kill(parentid,SIGUSR2);
	pause();
	kill(parentid,SIGUSR2);
	return 0;
} 