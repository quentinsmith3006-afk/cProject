#include <stdlib.h> // system
#include <stdbool.h> // true variable
#include <pthread.h> // pthread_create
#include <stdio.h> // printf
#include <string.h>

#ifdef BORDER
#include "headers/declarations.h" // CLEAR bash script location n more probably
#endif
#include "headers/helperfuncs.h"

pthread_t thread;

void * gameLoop();
void printMenu();

Player player;
char* characters[4];

int main(void) {
  
  system(CLEAR);
  printfile(BORDER);
  printfile(TITLE);    
  printfile(PLAY);
  printfile(BORDER);

  char resp;
  scanf("%c", &resp);
  while (resp != 'p') {
    scanf("%c", &resp);
  }

  system(CLEAR);
  printfile(BORDER);
  printfile(CHAR_SELECT_TITLE);


  for (int i = 1; i < 5; i++) {
    characters[i-1] = malloc(sizeof(char) * 40);
    char* ptr = characters[i-1];
    snprintf(ptr, sizeof(char)* 40, "%schar%i%s", F_STARTPOINT, i, ".txt\0");
    putchar('\n');

    printfile(ptr);
  }

  printfile(BORDER);

  pthread_create(&thread, NULL, gameLoop, NULL);
  //pthread_join(thread, NULL);

  for (int i = 0; i < 5; i++) {
    free(characters[i]);
  }
  
  return 0;
}

void * gameLoop() {

  printf("hi\n");
  while (true) {
    system(CLEAR);
    printfile(BORDER);
    
    printfile(BORDER);
    pthread_exit(NULL);
  }

  return NULL;
}

void printMenu() {
}
