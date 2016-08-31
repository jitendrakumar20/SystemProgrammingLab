#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

pid_t ravi,rakesh;

void handler(int sig){
	//printf("test5\n");
}

void sighandler1(int sig){
	printf("I can hear you, Ravi!\n");
	//sleep(1);
	signal(SIGUSR1,handler);
}

void sighandler2(int sig){
	printf("I can hear you, Rakesh!\n");
	//sleep(1);
	signal(SIGUSR2,handler);
}

int main(){

	int ravirun = 0,rakeshrun = 0;

	ravi = fork();

	signal(SIGUSR1,sighandler1);
	signal(SIGUSR2,sighandler2);

	if(ravi == 0){
		char *args[] = {NULL};

		execv("./ravi",args);

		pause();
		
		kill(ravi,SIGUSR1);
		printf("test3\n");
		
		pause();
		ravirun = 1;
	}

	else if(ravi > 0){
		
		/*kill(getpid(),SIGUSR1);*/
		pause();
		rakesh = fork();

		if(rakesh == 0){
			char *args[] = {NULL};

			execv("./rakesh",args);
			pause();
			kill(rakesh,SIGUSR2);
			pause();
			rakeshrun = 1;
		}

		else if (rakesh > 0)
		{	pause();
			kill(ravi,SIGUSR1);
			pause();
			kill(rakesh,SIGUSR2);
			pause();
			printf("Lost and found, going home now\n");
			/*if(ravirun && rakeshrun){

			}
			else{
				sleep(1);
			}*/

		}
		else{
			printf("fork failed\n");
			_exit(2);
		}
	}


	else{
		printf("fork failed\n");
		_exit(2);
	}

	return 0;
}