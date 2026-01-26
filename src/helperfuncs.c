#include "declarations.c"
#include <stdio.h>
#include <stdlib.h>

void printfile(char* path) {
  FILE* myFile;
  myFile = fopen(path, "r");
  char c;
  while ((c = getc(myFile)) != EOF) {
    printf("%c", c);
  }
  
  fclose(myFile);
}
