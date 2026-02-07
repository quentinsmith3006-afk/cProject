#ifndef DECLARATIONS_H
#define CLEAR "./resources/gamehelpers/refresh"
#define BORDER "./resources/main/border.txt"
#define TITLE "./resources/main/title.txt"
#define PLAY "./resources/main/play.txt"
#define CHAR_SELECT_TITLE "./resources/characterSelection/charSelectTitle.txt"
#define F_STARTPOINT "./resources/characters/"
#define MINISEPAR "./resources/main/miniSep.txt"
#define SHOPKEEPER "./resources/shop/shopkeeper.txt"
#define SHOPNAME "./resources/shop/shopname.txt"


typedef enum {
  END,
  PROGRESSING,
  START,
} GameState;

typedef struct {
  int magazines;
  int bullets;
  int magCapacity;
} Firearm;

typedef struct {
  char* employer;  
  double satisfaction;
  double pay;
} Job;

typedef struct {
  char* name;
  double money;
  int health;
  int wantedLevel;
  Job* work;
  Firearm* gun;
  char* asciiPerson;
} Player;
#endif








