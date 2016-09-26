CC = gcc
CFLAGS = -pthread -Wall -g

client: client.o csapp.o
	$(CC) $(CFLAGS) client.o csapp.o -o client -lm

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c 

client.o: client.c csapp.h
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -f *.o
tar:
	tar czvf csapp-submit.tgz csapp-proj