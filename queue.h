/* Header file for the simple circular queue example */
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<sys/types.h>
#include<string.h>
#if 0
typedef struct _queue {
	int size;    /* maximum size of the queue */
	int *buffer; /* queue buffer */
	int start;   /* index to the start of the queue */
	int end;     /* index to the end of the queue */
	int count;   /* no. of elements in the queue */
	int jobid;
	char *command;
	char *starttime;
	char *endtime;
	char *status;
} queue;
#endif
typedef struct _queue {
	int size;    /* maximum size of the queue */
	char *buffer; /* queue buffer */
	int start;   /* index to the start of the queue */
	int end;     /* index to the end of the queue */
	int count;   /* no. of elements in the queue */
	pid_t pid;
	pthread_t th_id;
	char *starttime;
	int jobid;
	char *endtime;
	char *status;

} queue;
queue *queue_init(int n);
int queue_insert(queue *q, char *item,int );
int queue_delete(queue *q);
void queue_display(queue *q);
void queue_display_2(queue *q);
void queue_destroy(queue *q);

#endif
