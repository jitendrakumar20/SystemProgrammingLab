#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

struct pqueue
{
	int  value ;
	struct pqueue *left ;
	struct pqueue *right ;
	struct pqueue *parent ;
};
typedef struct pqueue *PQUEUE ;
void heapify(PQUEUE node) ;

PQUEUE  initialize(PQUEUE Q)
{
	Q =(PQUEUE)malloc(1*sizeof(struct pqueue));
	Q->value = -32767 ;
	Q->left = NULL ;
	Q->right = NULL ;
	Q->parent = NULL ;
	return (Q);
}

int isEmpty(PQUEUE Q)
{
	if((Q->value == -32767) && (Q->left==NULL)&&(Q->right==NULL))
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
int insert(PQUEUE Q , int x)
{
	if(Q->value == -32767)
	{
		Q->value = x ;
		return 0 ;
	}
	else 
	{
		PQUEUE newnode =  (PQUEUE)malloc(1*sizeof(struct pqueue));
		newnode->value = x ;
		newnode->left = NULL ;
		newnode->right = NULL ;
		if(Q->left ==NULL)
		{
			Q->left = newnode ;
			newnode->parent = Q ;
			heapify(newnode);
			return 0 ;
		}
		if(Q->right ==NULL)
		{
			Q->right = newnode ;
			newnode->parent = Q ;
			heapify(newnode);
			return 0 ;
		}
		else
		{
			int x1 = insert(Q->left,x);
			if(x1==0)
			{
				return 0 ;
			}
			int x2 = insert(Q->right,x);
			if(x2==0)
			{
				return 0 ;
			}
			else 
			{
				return -1 ;
			}
		}
	}
}
void heapify(PQUEUE node)
{
	int temp ;
	while(node->parent != NULL)
	{
		if((node->parent->value) <= (node->value))
		{
			temp = node->parent->value ;
			node->parent->value = node->value ;
			node->value = temp ;
		}
		node = node->parent ;
	}
}

int extractMax(PQUEUE Q , int *x )
{
	if(Q== NULL)
	{
		return -2 ;
	}
	else if(isEmpty(Q))
	{
		return -1 ;
	}
	else
	{
		*x = Q->value ;
		return 0 ;
	}
}
void destroy(PQUEUE Q)
{
	if(Q->left != NULL)
	{
		destroy(Q->left);
	}
	if(Q->right != NULL)
	{
		destroy(Q->right);
	}
	free(Q);
}