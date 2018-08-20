/*
 * QueueUsingStack.c
 *
 *  Created on: 19-Aug-2018
 *      Author: partha
 */

#include <stdio.h>
#include <stdlib.h>
#define size 1000

struct stack
{
    int stack[size];
    int SP;
};

struct queue
{
    struct stack mystack;
    struct stack temp;
};

int pop(struct stack *stk, int *status){

	if(stk -> SP < 1){
		*status = 0;
		return 0;//we cannot return 0 and know stack empty condition as 0 can be a valid stack element
	}

	else{
		*status = 1;
		int item = stk -> stack[--(stk -> SP)];
		return item;
	}
}

int push(struct stack *stk, int elem)
{
	if(stk->SP == size){
		printf("Queue full.\n");
		return -1;
	}

	else{//if(mystack -> SP < 1000)
        stk -> stack[stk -> SP++] = elem;
        return 0;
    }
}

int dequeue(struct queue *myqueue, int *status)
{
	if((myqueue->mystack).SP == 0 && (myqueue->temp).SP == 0){
        printf("Queue is empty");
        //return -1;
	}
	else if((myqueue->temp).SP == 0)
	{
		while((myqueue->mystack).SP != 0){
			int item = pop(&(myqueue->mystack),status);
			push(&(myqueue->temp),item);
			//return item;
		}
	}

	// below lines will run in every case of dequeue operations
	int item = pop(&(myqueue->temp),status);
	return item;

}

void enqueue(struct queue * myqueue, int elem)
{
	push(&(myqueue->mystack),elem);
}

void init(struct queue *myqueue)
{
    (myqueue -> mystack).SP = 0;
    (myqueue -> temp).SP = 0;
}

int main()
{
    int elem;
    struct queue myqueue;
    init(&myqueue);
    int choice;
    int val, status;
    while(-100)//any non-zero value makes condition true
    {
        printf("\nEnter:\n\t1 - to Insert to Queue\n\t2 - to Delete from Queue\n\t0 - to Exit: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Please enter the element: ");
                scanf("%d", &elem);
                enqueue(&myqueue, elem);
                break;
            case 2:
                val = dequeue(&myqueue, &status);
                if(status  == 1)
                {
                    printf("Removed element is: = %d\n", val);
                }
                break;
            case 0:
            	printf("Thank you.\n");
            	exit(0);

        }
    }
    printf("\n");
    return 0;

}
