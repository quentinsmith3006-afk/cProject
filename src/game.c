#include <stdio.h> // printf
#include <stdlib.h> // system
#include <stdbool.h> // true variable
#include <pthread.h> // pthread_create

#include "declarations.c" // CLEAR bash script location n more probably
#include "helperfuncs.c"


pthread_t thread;

void * gameLoop();
void printMenu();

int main(void) {
  pthread_create(&thread, NULL, gameLoop, NULL);

  pthread_join(thread, NULL);
  return 0;
}

void * gameLoop() {
  while (1) {
    system(CLEAR);
    printfile(BORDER);
    printfile(TITLE);    
    printfile(PLAY);
    printfile(BORDER);    
    pthread_exit(NULL);
  }

  return NULL;
}

void printMenu() {
}
