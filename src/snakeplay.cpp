//Snake Play:
// - snake movements and mechanics
// - prompt to select user if not set
// score saving via player name
#include "snakeplay.h"
using namespace std;
using namespace LimT_Drawing;
using namespace LimT_Menu;

int play(int difficulty,Player *player, string playername)
{
	//if name has not been set yet, prompt player menu
	if(playername==string(STRNULL))playername=playerMenu(player);
	//if NULL again, exit.
	if(playername==string(STRNULL)) return 0;
	char cplayername[50];
	strcpy(cplayername,playername.c_str());
	SnakeChain snake; //Creates the doubly linked list object.
	int xfood=0; //safe values for some variable
	int yfood=0;
  int score=0;
	char key;
	char defdirection=RIGHT; //default directions is rightward
	char dir=defdirection;
	int deflength=5; //snake default length is 5
	gameField("create");
	menu4("erase");
	menu4("create");
	for(int k=0,l=30;k<=deflength;k++,l+=2) //Creates the body of the snake
	{
		snake.addtohead(l,15);
	}
	snake.ShowSnakeChain(-1,-1); //Show the snake.
	pnt(XMENU4,YMENU4); cout <<"Score:";
	pnt(XMENU4+7,YMENU4); cout <<score;
	pnt(3,12); cout <<"Press any key...";
	getch();
	pnt(3,12);cout <<"                 ";
	genfood(&snake,&xfood,&yfood); //Pass the address of the snake object.
	snakemove(&snake,&xfood,&yfood,&score,difficulty,dir); //for the snake to move
	/////GAME OVER/////
	menu2("erase");
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"G A M E  O V E R !";
	pnt(XMENU2,YMENU2+2); cout <<playername;
	pnt(XMENU2,YMENU2+3); cout <<"Score: " <<score;
	player->editNode(cplayername,score);
	player->saveList();
	getch();
	snake.destroySnake();
	gameField("erase");
	menu4("erase");
	menu2("erase");
	return score;
}
int snakemove(SnakeChain *snake,int *xfood, int* yfood, int* score, int difficulty, int dir)
{
	int checkw,checkb,checkf;
	int xprev,yprev; 
	char right='R';
	char left='L';
	char up='U';
	char down='D';
	do
	{
		//Save previous coordinates of the tail to erase it's trail sooner.
		xprev=snake->xtail();
		yprev=snake->ytail();
		Sleep(difficulty);         //Pause depends on difficulty.
		snake->SnakePosChange(dir); //Update the coordinates with respect to the direction.
		//Check if the NEW coordinates will hit the coordinates of the wall, the food, or its own body
		checkw=checkwall(snake->xhead(),snake->yhead());
		checkb=checkbody(snake,snake->xhead(),snake->yhead());
		checkf=checkfood(snake,score,xfood,yfood,snake->xhead(),snake->yhead());
		//Add a new tail if it hits the food.	
		if(checkf==1)
		{ snake->addtotaildirection(); }
		//Show to the player the new snake position if its valid.
		if(checkw!=1&&checkb!=1) //update to new coordinates
		{
			snake->ShowSnakeUpdate(xprev,yprev); //The two arguments passed are the coordinates of previous tail.
		}
	}while(kbhit()==0&&(checkw!=1&&checkb!=1)); //do them while no key was pressed and it did not hit the wall or its own body.
	if(checkw!=1&&checkb!=1) //If a key was pressed and it did not hit the wall or its own body.
	{
		switch(getch())//Get the key from kbhit().
		{
			case 'd':
				if(dir!=LEFT) { dir=RIGHT;} //The snake should not move to the right if its still moving to the left.
				break;
			case 'a':
				if(dir!=RIGHT) { dir=LEFT;} //Vice versa.
				break;
			case 'w':
				if(dir!=DOWN) { dir=UP;}//Same goes for up and down
				break;
			case 'x':
				if(dir!=UP) { dir=DOWN;}
				break;
			case 32:
				pnt(3,12); cout <<"Paused.";
				pnt(3,13); cout <<"Press Esc to quit.";
				if(getch()==27)
					return 0;
				else
				{
					pnt(3,13); cout <<"                  ";
					break;
				}	
			default: break;
		}
		snakemove(snake,xfood,yfood,score,difficulty,dir); //repeat movement.(Direction might be new)
  }
  else 
	{
		pnt(*xfood,*yfood); cout <<" ";
		pnt(xprev,yprev); cout <<" ";
	}
}
int checkwall(int xhead,int yhead)
{
	if((xhead<=1||xhead>=149)||((yhead<=1||yhead>=29))) return 1;
	else  return 0;
}
int checkfood(SnakeChain *s,int *scr,int*xf,int*yf,int xhead,int yhead)
{
	if((xhead==*xf)&&(yhead==*yf))
	{
		(*scr)+=1;
		pnt(XMENU4,YMENU4); cout <<"Score:      ";
		pnt(XMENU4+7,YMENU4); cout <<(*scr);
		genfood(s,xf,yf); return 1;
	}
	else return 0;
}
int checkbody(SnakeChain *s,int xhead, int yhead)
{
	int k;
	k=s->snakebodycoordcheck(xhead,yhead);
	return k;
}

void genfood(SnakeChain *s,int *xf,int *yf)
{
	int xcache=(*xf), ycache=(*yf);
	long long sec;
	time(&sec);
	srand(unsigned(sec));
	repeat:
	(*xf)=((rand()%70+1)*2)+2;
	(*yf)=((rand()%10+1)*2)+2;
	if((xcache==(*xf))&&(ycache==(*yf))) goto repeat;
	if(s->snakebodycoordcheck(*xf,*yf)==1) goto repeat;
	else
	pnt(*xf,*yf); cout <<'o';
}
