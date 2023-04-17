/* Driver program to test the queue implementation */
/* Use the Makefile provided or compile using: gcc -Wall queue.c qdriver.c */

#include <stdio.h>
#include "queue.h"
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#define True 1
#define False 0
#define MAX_INDEX 200
queue *q;
int Index =0;
int range_processors = 0;
int running_processors = 0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int evaluate_cmd(char *command)
{
	 int RetValue =0;
	 char *where_to_go = strtok(command," ");
	 char *actual_cmd = strtok(NULL,"");
	  //printf("cmd:%s  %s\n",where_to_go,actual_cmd);

	  if(strcmp(where_to_go,"submit") == False)
	  {
		  RetValue = queue_insert(&q[Index], actual_cmd,Index);
		  if(RetValue < 0)
			  printf("queue is full\n");
		  else
			  Index = RetValue;
	  }

	  if(strcmp(where_to_go,"showjobs") == False)
		  queue_display_2(q);
	  if(strcmp(where_to_go,"submithistory") == False)
		  queue_display(q);

return 0;
}
char *time_run( char *mem)
{
	time_t t;
       char *q_time =NULL;
       time(&t);
       q_time = ctime(&t);
       q_time[strlen(q_time)-1] = '\0';
       
       strcpy(mem,q_time);
       return q_time;
  

}
void * n_thread_exec(void *arg)
{
     queue *qq = (queue *)arg;
     int id_out=0, id_err=0;
     char out[20]={0};
     char err[20]={0};
     sprintf(out,"%d.out",qq->jobid);
     sprintf(err,"%d.err",qq->jobid);
     id_out = open(out,O_CREAT| O_WRONLY,0777);
     id_err = open(err,O_CREAT| O_WRONLY,0777);
   // printf("exec-> %s %d\n",qq->buffer,getpid());
       qq->status = "running";
        time_run(qq->starttime);
       qq->pid = fork();
	       if(qq->pid == 0)
	       {
		       dup2(id_out,1);
		       dup2(id_err,2);
		   execl("/bin/sh","sh","-c",qq->buffer,NULL);
	       }
       		else
		{
	          wait(NULL);
		  pthread_mutex_lock(&mutex);
		  running_processors -=1;
		 pthread_mutex_unlock(&mutex);
       		  qq->status = "completed";
        	  time_run(qq->endtime);
		}
   		  return (NULL); 
}
void *monitoring_fun(void * arg)
{
	int exec_index =0;
	do {

	      if((exec_index < Index) &&(running_processors < range_processors))
	      {
                 // printf("execIndex %d Index=%d %d\n",exec_index, Index,getpid());
		  pthread_create(&q[exec_index].th_id,NULL, n_thread_exec,(void *)&q[exec_index]);
		  running_processors +=1;
		  exec_index +=1;
	      }

	}while(1);
}
int main(int argc, char **argv) {
	//int i;
	char Time_to_Quit = 0;
        char *cmd;
	pthread_t running_thread;
	if(argc != 2)
	{
	  printf("arg missing\n");
	  return -1;
	}
	range_processors = atoi(argv[1]);

	q = queue_init(MAX_INDEX);
	
	//while(Time_to_Quit == False)
//	{

	pthread_create(&running_thread, NULL, monitoring_fun,NULL);

	while((cmd = readline("Enter command> ")) !=NULL)
	{
		if(cmd[0] == '\0')
			continue;
	  if( strcmp(cmd,"quit") == False)
		  Time_to_Quit = True;
	  if(Time_to_Quit == True)
		  exit(0);

	  evaluate_cmd(cmd);

        
	
	}

	/* create a queue data structure */

        queue_destroy(q);
	return 0;
	
}

