# Sample Makefile to compile C programs

CC = gcc
CFLAGS = -Wall -g #replace -g with -O when not debugging

DEPS	= queue.h Makefile
OBJS	= queue.o qdriver.o

EXECS	= run

all:	$(EXECS)

%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

run:	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline -lpthread

clean:	
	/bin/rm -i *.o $(EXECS)
