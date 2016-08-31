#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	PQUEUE Q , R ;
	int  *e  = malloc(1*sizeof(int));
	R = initialize(Q);
	if(isEmpty(R))
	{
		printf("\n\t\tQueue was found  empty !\n\n");
	}
	int t = 0 ; int return_insert = 0 ; int m = 0 ;
	while(1)
	{
		printf("here are some  choices  for  you   : \n");
		printf("\t\t1 :  insert \n\t\t2 :  destroy  the queue \n");
		printf("Enter the choice : \t");
		int choice = 0 ;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : 
				printf("Enter  the value to be inserted :\t");
				scanf("%d",&t);
				return_insert =  insert(R,t);
				if(return_insert == 0 && !isEmpty(R))
					extractMax(R,e);
					printf("Maximum in the queue is : %d\n" , *e);
					printf("\n");
			break ;
			case 2 :
				destroy(R);
				R = NULL ;
				m = extractMax(R,e);
				printf("After destroying the queue , status of extractMax is  %d\n",m );
				printf("Thank you for using\n");
				return 0 ;
				exit(0);
			break ;
		}
	}
}