#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
	srand(time(NULL));
	printf("%d about to create 2 child processes\n", getpid());
	pid_t child1PID;
	pid_t child2PID;

	child1PID = fork();
	if (child1PID != 0) {
		pid_t child2PID = fork();
	}

	if (child1PID == 0 || child2PID == 0) {
		childInstructions();
	}
	else {
		int status;
		wait(&status);
	}
}
