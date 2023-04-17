/* Implementation of a simple circular queue using a static array */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* create the queue data structure and initialize it */
queue *queue_init(int n) {
 	queue *q = (queue *)malloc(sizeof(queue)*n);
	for(int i=0; i< n ;i++)
	{
	q[i].size = n;
	//q->buffer = malloc(sizeof(char *)*n);
	q[i].start = 0;
	q[i].end = 0;
	q[i].count = 0;
	q[i].status = NULL;
	q[i].starttime =malloc(sizeof(char)*20);
	q[i].endtime =malloc(sizeof(char)*20);
	}
	return q;
}

/* insert an item into the queue, update the pointers and count, and
   return the no. of items in the queue (-1 if queue is null or full) */
int queue_insert(queue *q, char * item,int index) {
	if ((q == NULL) || (index >= q->size))
	{
        	printf("%p,%d\n",q,index);
	return -1;
	}

	q->buffer = item;	
	q->end = (q->end + 1) % q->size;
	q->status = "waiting";
	q->count = index +1;
	q->jobid = q->count;
	printf("job %d  %s added to the queue\n",q->jobid, q->buffer);

	return q->count;
}

/* delete an item from the queue, update the pointers and count, and 
   return the item deleted (-1 if queue is null or empty) */
int queue_delete(queue *q) {
	if ((q == NULL) || (q->count == 0))
	   return -1;

	int x = q->buffer[q->start];
	q->start = (q->start + 1) % q->size;
	q->count--;

	return x;
}
void queue_display_2(queue *q) {
	int i;
	if (q != NULL && q->count != 0) {

	    	printf("%5s %-20s %-10s\n","Jobid", "Command", "Status");
		for (i = 0; q[i].status !=NULL; i++)
		{
			if(strcmp(q[i].status,"completed") != 0)
	    		printf("%5d %-20s %-10s\n", q[i].jobid,q[i].buffer,q[i].status);
		}
	} else
		printf("queue empty, nothing to display\n");
}

/* display the contents of the queue data structure */
void queue_display(queue *q) {
	int i;
	if (q != NULL && q->count != 0) {

	    	printf("%5s %-20s %-10s %s %s\n","Jobid", "Command", "Status", "Starttime", "Endtime");
		for (i = 0; q[i].status !=NULL; i++)
		{
			if(strcmp(q[i].status,"completed") == 0)
	    		printf("%5d %-20s %-10s %s %s\n", q[i].jobid,q[i].buffer,q[i].status, q[i].starttime, q[i].endtime);
		}
	} else
		printf("queue empty, nothing to display\n");
}

/* delete the queue data structure */
void queue_destroy(queue *q) {
//	free(q->buffer);
	free(q);
}

