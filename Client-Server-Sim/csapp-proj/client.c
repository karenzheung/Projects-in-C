#include "csapp.h"
#include <stdio.h>

int MIN(int x, int y){
	if(x > y) return y;
	else
		return x;
}

int main (){
	int clientfd = Open_clientfd("flamingo.jacelridge.com", 48579);
	if(clientfd!=-1)
		printf("Connected to server.\n");
	else
		printf("Failed to connect to server.\n");
	FILE *file = fdopen(clientfd, "a+");
	printf("Sending Spire ID 28246420\n");
	fprintf(file, "28246420");
	char *line = NULL;
	size_t count;
	getline(&line, &count, file);
	int x, y;
	count = sscanf(line, "MIN%d%d", &x, &y);
	free(line);
	printf("Recieved problem: MIN %d %d\n", x, y);
	int solution = MIN(x, y);
	fprintf(file, "%d\n", solution);
	printf("Sending Solution: %d\n", solution);	
	getline(&line, &count, file);
	printf("%s", line);
	//free(line);
	//line = NULL;
	printf("Sending bonus: HW9\n");
	fprintf(file, "HW9");
	getline(&line, &count, file);
	printf("%s", line);
	printf("Disconnected from server.\n");
	fclose(file);
	free(line);
	exit(0);
	return (0);
}