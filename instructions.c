#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "instructions.h"

void childInstructions() {
  int time = rand() % 5;
  printf("%d %dsec\n", getpid(), time);
  sleep(time);
  printf("%d finished after %d seconds\n", getpid(), time);
  exit(time);
}

void parentInstructions() {

}
