xy
#include <stdlib.h> // system
#include <stdbool.h> // true variable
#include <pthread.h> // pthread_create
#include <stdio.h> // printf
#include <string.h> // idk bruh a lot of methods
#include <math.h> // rand
#define JOBNUM 5

#ifdef BORDER 
#include "headers/declarations.h" // CLEAR bash script location n more probably
#endif

#include "headers/helperfuncs.h"

pthread_t thread;

void * gameLoop();
void printMenu();
void beg();
void work();
void shop();
void rob();
void scanEmployers();
void shopSelection(char a);
void applicationMenu();

Player* player;
char* characters[4];

char nameBuff[40];

char* news;

Job* jobs[JOBNUM];

int main(void) {
  Player p;
  player = &p;
  player->gun = NULL;
  player->work = NULL;
  scanEmployers();
  
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

  int characterSelection;
  scanf("%i", &characterSelection);
  while (characterSelection < 1 || characterSelection > 4) {
    scanf("%i", &characterSelection);
  }
  player->asciiPerson = characters[characterSelection - 1];

  scanf("%s", nameBuff);

  player->name = &nameBuff[0];
  player->health = 100;
  
  //pthread_create(&thread, NULL, gameLoop, NULL);

  gameLoop();
  
  //pthread_join(thread, NULL);
  
  for (int i = 0; i < 5; i++) {
    free(characters[i]);
  }

  for (int i = 0; i < JOBNUM; i++) {
    free(jobs[i]->employer);
    free(jobs[i]);
  }
  
  return 0;
}

void * gameLoop() {
  void selection(char a);
  
  while (player->health > 0) {
    system(CLEAR);
    printfile(BORDER);
    printf("Name: %s\n", player->name);
    printfile(player->asciiPerson);
    printfile(MINISEPAR);
    printf("Health: %i\nMoney: %f\nWantedLevel: %i\n", player->health, player->money, player->wantedLevel);
    printfile(MINISEPAR);
    printf("Rob: r | Work: %c | Shop: s | Beg: (Anything Else)\n", (player->work == NULL ? 'a' : 'w'));
    printfile(MINISEPAR);
    if (news != NULL) 
      printf("%s", news);
    printfile(BORDER);    
    char selec;
    char garbage;
    
    scanf("%c", &garbage);
    scanf("%c", &selec);
    selection(selec);

  }

  return NULL;
}

void selection(char a) {
  switch (a) {
  case 'r':
    rob();
    return;
  case 'w':
    if (player->work != NULL) {
       work();
    }
    news = "You are unemployed.\n";
    return;
  case 's':
    shop();
    return;
  case 'a':
    if (player->work == NULL) {
      applicationMenu();
      return;
    }
  default:
    beg();    
    
  }
}

/*
 * JOBS SECTION
 *
 *
 */
void scanEmployers() {

  char* path = EMPLOYERS;

  FILE* file = fopen(path, "r");

  for (int i = 0; i < JOBNUM; i++) {    
    char* empl = malloc(50);

    char* localPay = malloc(sizeof(int));
    fgets(empl, 50, file);
    fgets(localPay, sizeof(localPay), file);
    
    double p = atof(localPay);


    free(localPay);

    Job* aJob = malloc(sizeof(Job));

    aJob->employer = empl;
    aJob->pay = p;

    jobs[i] = aJob;
  }
  
  fclose(file);
}

void applicationMenu() {
  system(CLEAR);
  printfile(BORDER);
  printfile(MINISEPAR);
  printf("Apply for:");
  for (int i = 0; i < JOBNUM; i++) {
    printf("\n%s (%i)\n", jobs[i]->employer, i);
  }
  printfile(BORDER);
  char garbage;
  char selection;
  scanf("%c", &garbage);
  scanf("%c", &selection);
}

void applySelection(char g) {
  // todo 
}

void apply(Job* job) {
  int randy = rand() % 101;

  if (player->wantedLevel > 0) {
    news = "You were reported to the authorities.";
    return;
  }

  if (randy <= 5) {
    news = "You were hired!";
    player->work = job;
  } else if (randy > 5 && randy <= 15) {
    news = "You failed the interview.";
    player->health -= 5;
  } else if (randy > 15 && randy <= 30) {
    news = "You got a interview but it was a scam.";
    player->health -= 10;    
  } else if (randy > 30 && randy < 50) {
    news = "The manager's cousin got the position!";
  } else {
    news = "You got no response.";
  }
}

/*
 * ACTIONS SECTION
 *
 *
 */
void beg() {
  int randy = rand() % 101;
  
  if (randy <= 10) {
    (*player).money += 50;
    news = "Very productive day.\n";
  } else if (randy > 10 && randy <= 30) {
    (*player).money -= 5;
    (*player).health -= 10;
    news = "You were robbed and punched.\n";    
  } else if (randy > 30 && randy <= 50) {
    (*player).money -= 10;
    (*player).health -= 15;    
    news = "You stepped into another person's territory.\n";    
  } else if (randy > 50 && randy <= 90) {
    (*player).money += 3;
    news = "You found money on the ground.\n";    
  } else {
    news = "Nothing happened\n";    
  }

  if ((*player).money < 0) {
    (*player).money = 0;
    (*player).health -= 5;
  }

}

void work() {
  int randy = rand() % 101;
  double modifier = 1;
  if (randy <= 10) {
    (*player).money += 50;
    news = "Very productive day, the boss gave you a bonus.\n";
  } else if (randy > 10 && randy <= 15) {
    news = "You spilled soup on someone, the boss is withholding your pay.\n";    
  } else if (randy > 15 && randy <= 40) {
    (*player).money += 10;
    news = "The boss is on vacation.\n";    
  } else if (randy > 40 && randy <= 90) {
    (*player).money += 15;
    news = "Normal day at work.\n";    
  } else {
    (*player).money += 4;
    news = "The day was slow, boss is not happy.\n";    
  }
}

void rob() {
  if ((*player).gun == NULL || player->gun->bullets == 0) {
    news = "You are cooked bruh, never do tis again\n";
    return;
  }

  if (player->gun->bullets == 0) {
    if (player->gun->magazines == 0) {
      news = "You don't have any ammo.";
      return;
    }

    player->gun->magazines -= 1;
    player->gun->bullets = player->gun->magCapacity;
  }
  
  int randy = rand() % 101;
  
  if (randy <= 10) {
    (*player).money += 200;
    (*player).wantedLevel++;
    news = "The robbery was successful but the police are coming.\n";
  } else if (randy > 10 && randy <= 15) {
    news = "Robbery gone terribly wrong. You killed someone!\n";
    (*player).health -= 15;
    (*player).wantedLevel += 2;
    player->gun->bullets -= 5;
    (*player).money += 5;
  } else if (randy > 15 && randy <= 40) {
    player->gun->bullets -= 2;    
    (*player).money += 10;
    news = "Robbery was a bust. Barely anything!\n";    
  } else if (randy > 40 && randy <= 90) {
    (*player).health -= 4;
    news = "Nothing good to rob.\n";
  } else if (randy == 91) {
    (*player).health -= 90;
    player->gun->bullets -= player->gun->magCapacity;    
    news = "You were shot.\n";
  } else {
    (*player).money += 4;
    news = "You found money on the floor\n";    
  }

  if (player->gun->bullets <= 0) {
    player->gun->bullets = 0;
  }
}

/*
 * SHOP SECTION
 *
 *
 */
void shop() {
  void shopSelection(char a);
  
  system(CLEAR);
  printfile(BORDER);
  printfile(SHOPNAME);
  printfile(SHOPKEEPER);
  printfile(MINISEPAR);
  printf("Firearm: $150\n");
  printf("Food: $5\n");
  printf("food (f) | firearm (g) | exit (anything else)\n");
  printfile(BORDER);
  char garbage;
  char selection;
  scanf("%c", &garbage);
  scanf("%c", &selection);

  shopSelection(selection);
}

void shopSelection(char a) {
  void buyWeapon();
  void buyFood();

  switch (a) {
  case 'g':
    buyWeapon();
    return;
  case 'f':
    buyFood();
    return;
  }
}

void buyWeapon() {
  if (player->money < 1500) {
    news = "You are too poor to buy a weapon.\n";
  } else {
    player->money -= 1500;
    player->gun = malloc(12);
    player->gun->magazines = 1;
    player->gun->magCapacity = 15;
    player->gun->bullets = 15;        
  }
}

void buyFood() {
  if (player->money < 10) {
    news = "You are too poor to buy food\n";
  } else {
    player->money -= 10;
    player->health += 5;
  }
}


