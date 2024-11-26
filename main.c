#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	srand(time(NULL));
	FILE *file = fopen("/dev/urandom", "r");

	printf("%d about to create 2 child processes\n", getpid());
	pid_t child1PID, child2PID;

	child1PID = fork();
	
	if (child1PID == 0) {
		unsigned int time;
		fread(&time, sizeof(int), 1, file);
		time = time % 5;
		printf("%d %dsec\n", getpid(), time);
		sleep(time);
		printf("%d finished after %d seconds\n", getpid(), time);
		return time;
	}
	else {
		child2PID = fork();

		if (child2PID == 0) {
			unsigned int time;
			fread(&time, sizeof(int), 1, file);
			time = time % 5;
			printf("%d %dsec\n", getpid(), time);
			sleep(time);
			printf("%d finished after %d seconds\n", getpid(), time);
			return time;
		}
		else {
			int status;
			int childPID = wait(&status);
			printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), childPID, WEXITSTATUS(status));
		}
	}
}
