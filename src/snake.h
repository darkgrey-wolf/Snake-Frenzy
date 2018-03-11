//Snake.h - snake body linked list
#ifndef SNAKE_H
#define SNAKE_H
#include "resource.h"
using namespace LimT_Drawing;
using namespace std;

class SnakeChain //the one that holds SnakeOb
{
	private:
		class SnakeOb //represents the snake's single segment
		{
			public:
				SnakeOb *next,*prev;
				int xdata,ydata; //xdata and ydata stores the coordinates of the segment
				char direction; //direction of where the segment is going
				SnakeOb(int x, int y, SnakeOb *pntr1=0,SnakeOb *pntr2=0) //constructor
								{ xdata=x; ydata=y; prev=pntr1; next=pntr2; }
				void ShowSnakeSegment() //shows the segment with respect to xdata and ydata
								{pnt(xdata,ydata); cout <<char(254);}
		};
		SnakeOb *head,*tail; //head will point that first SnakeOb and tail will point the last.
	public:
		SnakeChain()  { head=tail=0;} //open creation of the object, head and tail points to nothing.
		~SnakeChain(){destroySnake();}
		bool empty()  {return (head==0);} //returns true if head is equal to 0.
		void addtohead(int,int);
		void addtotail(int,int);
		void addtotaildirection();
		void display();
		void ShowSnakeChain(int,int); //the two arguments are coordinates of the PREVIOUS tail//pass -1 for NULL
		void ShowSnakeUpdate(int,int);//arguments same with ShowSnakeChain but only updates the head,tail,and the first body segment.
		void ShowSnakeTail();
		void SnakePosChange(char);
		int destroySnake();
		int snakebodycoordcheck(int,int);
		int xhead() { return head->xdata;}
		int yhead() { return head->ydata;}
		int xtail() { return tail->xdata;}
		int ytail() { return tail->ydata;}
		int headdirect(){return head->direction;}
};
#endif
