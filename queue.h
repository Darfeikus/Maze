/*
	Program: Library for the management of nodes
	Antonio Diaz Flores
	A01329256
	Oscar Barbosa Aquino
	A01329173
	Date: 16/11/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Definition of struct node
*/
struct node
{
	char dir;
};

/*
	Definition of struct Queue of nodes
*/
struct Queue{
	struct node* node;
	struct Queue *next;
	struct Queue *previous;
};


/*
	Function that prints the queue with the value of Id of a node
*/
void printQ(struct Queue *x){
	while(x){
		printf("%c ",x->node->dir);
		x = x->next;
	}
	printf("\n");
}

/*
	Function for comparing strings
*/
int strcmp2(char* a,char* b){
	if (strlen(a) != strlen(b)){
		return strlen(a)-strlen(b);
	}
	else
		return strcmp(a,b);
}

/*
	Function that returns the size of a Queue
*/
int sizeOfQueue(struct Queue *x){
	int l = 0;
	while(x){
		l++;
		x = x->next;
	}
	return l;
}

/*
	Function that returns for the las element of the queue
*/
struct Queue *searchLast(struct Queue *head){
	while(head){
		if(head->next == NULL)
			return head;
		head = head->next;
	}
}

/*
	Function that inserts a node at the beginning of the queue
*/
void iatb(struct Queue **pth,struct node* node){
	struct Queue *tmp = (struct Queue*)malloc(sizeof(struct Queue));
	tmp->node = node;
	tmp->next= *pth;
	tmp->previous= NULL;
	*pth = tmp;
}

/*
	Function that inserts a node at the end of the queue
*/
void push(struct Queue **pth,struct node* data){
	if(*pth==NULL)
		iatb(pth,data);
	else{
		struct Queue *tmp = (struct Queue*)malloc(sizeof(struct Queue));
		tmp->previous = searchLast(*pth);
		tmp->previous->next = tmp;
		tmp->next =NULL;
		tmp->node=data;
	}
}

/*
	Function that swaps elements in the queue
*/
void swap(struct Queue **pth){
	struct node* temp = (*pth)->node;
	(*pth)->node=(*pth)->previous->node;
	(*pth)->previous->node = temp;
}

/*
	Function to delete a node at the beggining of the queue and then returns it
*/
struct node* get(struct Queue **pth){
	struct node* x = NULL;
	struct Queue *p1 = *pth;
	x = (*pth)->node;
	if((*pth)->next!=NULL)
		(*pth) = (*pth)->next;
	else
		(*pth) = NULL;
	memset(p1,0,sizeof(struct Queue));
	free(p1);
	return x;
}

/*
	Function to delete a node at the end of the queue and then returns it
*/
struct node* pop(struct Queue **pth){
	struct node* x = NULL;
	struct Queue *p1 = NULL;
	p1 = *pth;
	while(p1->next)
		p1 = p1->next;

	x = p1->node;
	if(p1->previous)
		p1->previous->next = NULL;
	else
		*pth = NULL;
	memset(p1,0,sizeof(struct Queue));
	free(p1);
	return x;
}
