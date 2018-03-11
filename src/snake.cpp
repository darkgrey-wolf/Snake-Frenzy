#include "snake.h"
int SnakeChain::destroySnake()
{
	for(SnakeOb *temp;!empty();)
		{
			//access xdata and ydata and erase the previous characters at that location
			pnt(head->xdata,head->ydata); cout <<" ";
			//temp points to the SnakeOb next to the head
			temp=head->next;
			if(head->next!=0) head->next->prev=0; //You cannot access head->next->prev if head->next points to nothing
			delete head;//delete head
			head=temp; //the temp becomes the head.
		}
		return 0;
}
void SnakeChain::addtohead(int x, int y)
{
	if(head==0) 
	{
		head=tail=new SnakeOb(x,y);
	}
	else
	{
		head=new SnakeOb(x,y,0,head);
		head->next->prev=head;
	}
}
void SnakeChain::addtotail(int x, int y)
{
	if(head!=0)
			{
				tail=new SnakeOb(x,y,tail,0);
				tail->prev->next=tail;
			}
			else
			head=tail= new SnakeOb(x,y);
}
void SnakeChain::addtotaildirection()
{
	//creates a new tail depending on 
	//the directions of head and tail
	/////////////////////////////////
	//copy all the data of tail
	int x =tail->xdata;
	int y =tail->ydata;
	char dir=tail->direction;
	//create new tail with coordinates that 
	//depends on the direction of the old tail
	switch(tail->direction)
	{
		//y is constant in left-right direction
		case RIGHT: tail=new SnakeOb(x-2,y,tail,0);
		          tail->prev->next=tail;
		          tail->direction=dir;
		          break;
		case LEFT: tail=new SnakeOb(x+2,y,tail,0);
		          tail->prev->next=tail;
		          tail->direction=dir;
		          break;
		//x is constant in up-down direction
		case UP: tail=new SnakeOb(x,y-1,tail,0);
		          tail->prev->next=tail;
		          tail->direction=dir;
		          break;
		case DOWN: tail=new SnakeOb(x,y+1,tail,0);
		          tail->prev->next=tail;
		          tail->direction=dir;
		          break;
		default: break;
	}
}
void SnakeChain::display()
{
	if(head!=0)
			{
				SnakeOb *tmp; int x=1,y=1;
				for(tmp=head;tmp!=0;tmp=tmp->next)
				{
					
					CreateBox(x,y,10,7);
					pnt(x+1,y+1); cout <<tmp->xdata;
					pnt(x+1,y+2); cout <<tmp->ydata;
					pnt(x+1,y+3); cout <<tmp;
					pnt(x+1,y+4); cout <<tmp->next;
					pnt(x+1,y+5); cout <<tmp->prev;
					if(tmp==tail) //Just for delete from tail methods.
					{EraseBox(x+15,y,10,7);}
					x+=15;
					if(x==106)
					{y+=9;x=1;}
				}
			}
			else cout <<"Empty List.";
}
void SnakeChain::ShowSnakeChain(int x =-1, int y= -1)
{
	  int a,b;
	  //Show the body
		for(SnakeOb *tmp=head;tmp!=0;tmp=tmp->next)
		{
			a=tmp->xdata;
			b=tmp->ydata;
			if(tmp==head)
			{
				pnt(a,b); cout <<char(219);
			}
			else if(tmp==tail)
			{
				pnt(a,b); cout <<'O';
			}
			else
			{
				pnt(a,b); cout <<'O'; //220 or 254 default
			}
				
		}
		//delete the previous tail(if specified)
		if(x!=-1&&y!=-1)
		{
			pnt(x,y); cout <<" ";
		}
}
void SnakeChain::ShowSnakeUpdate(int x = -1,int y = -1)
{
		pnt(head->xdata,head->ydata); cout <<char(219); //219 default
		pnt(head->next->xdata,head->next->ydata); cout <<'O'; //220 or 254 default
		pnt(tail->xdata,tail->ydata); cout <<'O';
		if(x!=-1&&y!=-1)
		{
			pnt(x,y); cout <<" ";
		}
		
}
void SnakeChain::ShowSnakeTail()
{
	SnakeOb *t=tail;
	pnt(tail->xdata,tail->ydata); cout <<'O';
}
void SnakeChain::SnakePosChange(char direction)
{
	//recieves a char argument then modifies the whole coordinates
	//of snake depending on the direction
	switch (direction)
		{
			case RIGHT:
								for(SnakeOb *p=tail->prev;p!=0;p=p->prev)
								{
									p->next->xdata=p->xdata;
									p->next->ydata=p->ydata;
									p->next->direction=p->direction;
								}
								head->xdata=head->xdata+2;
								head->direction=RIGHT;
								break;
			case LEFT:
								for(SnakeOb *p=tail->prev;p!=0;p=p->prev)
								{
									p->next->xdata=p->xdata;
									p->next->ydata=p->ydata;
								  p->next->direction=p->direction;
								}
								head->xdata=head->xdata-2;
								head->direction=LEFT;
								break;
			case UP:
								for(SnakeOb *p=tail->prev;p!=0;p=p->prev)
								{
									p->next->xdata=p->xdata;
									p->next->ydata=p->ydata;
								  p->next->direction=p->direction;
								}
								head->ydata=head->ydata-1;
								head->direction=UP;
								break;
			case DOWN:
								for(SnakeOb *p=tail->prev;p!=0;p=p->prev)
								{
									p->next->xdata=p->xdata;
									p->next->ydata=p->ydata;
									p->next->direction=p->direction;
								}
								head->ydata=head->ydata+1;
								head->direction=DOWN;
								break;
			default: break;
		}
}
int SnakeChain::snakebodycoordcheck(int x, int y)
{
	int xfirst,xlast,xmid;
	for(SnakeOb *tmp=head->next;tmp!=0;tmp=tmp->next)
	{ 
	  //Check if coordinates is within the body.
		if(tmp->xdata==x&&tmp->ydata==y) return 1;
		//Check if in between 2 segment along x-axis.
		if(tmp!=tail) //stop this algorithm at tail
		{
			xfirst=tmp->xdata;
			xlast=tmp->next->xdata;
			if(tmp->ydata==tmp->next->ydata) //make sure the two segments have same y coordinates.
					xmid = xfirst-xlast; //get the xcoord in between segments.
			else continue;
			if((xmid==x)&&(tmp->ydata==y))
				return 1;
		}
	}
	return 0;
}
