#ifndef EVENTS_H
typedef struct {
  char* frame[11];
  int size;
  char* message;
} Event;


void eventRun(int frames, Event* event);
#endif
