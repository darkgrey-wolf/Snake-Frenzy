#ifndef SNAKEPLAY_H
#define SNAKEPLAY_H
#include "resource.h"
#include "snake.h"
#include "player.h"
#include "playermanip.h"
int checkbody(SnakeChain*,int,int); //checks if snake hits the body
int checkfood(SnakeChain*,int*,int*,int*,int,int); //checks if snake hits the food. Calls genfood and increments the score
int checkwall(int,int); //check if it hits the wall
int gameover(int *); //erase the main box and all other text
int play(int,Player *,string playername); //initializes important things
int snakemove(SnakeChain *,int*,int*,int*,int,int); //moves the snake
void coordtracker(int,int); //debugging purposes
void genfood(SnakeChain*,int*,int*);
#endif
