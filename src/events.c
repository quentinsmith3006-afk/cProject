#include <string.h>
#include <stdlib.h>
#include "./headers/helperfuncs.h"
#include "./headers/events.h"

void eventRun(int frames, Event* event) {
  system(CLEAR);
  printfile(BORDER);
  for (int i = 0; i < frames; i++) {
    if (i >= 11) {
      printf("eventRun missuse");
    }

    printfile(event->frame[i]);
  }
  printfile(BORDER);
} 

