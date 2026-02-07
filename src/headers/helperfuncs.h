#ifndef HELPERFUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

void printfile(char* path) {
  FILE* myFile;
  myFile = fopen(path, "r");
  char c;
  while ((c = getc(myFile)) != EOF) {
    printf("%c", c);
  }
  
  fclose(myFile);
}
#endif
