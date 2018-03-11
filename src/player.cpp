#include "player.h"
using namespace std;
using namespace LimT_Drawing;
using namespace LimT_Menu;
int Player::openList()
{
	ifstream inFile("database.txt");
	string fdata;
	char fname[50];
	char fpw[50];
	int fscore;
	int count=3;
	if(inFile.fail())
	{
		//pnt(0,26); cout <<"File not opened!";
		ofstream outFile("database.txt");
		outFile.close();
	}
	else
	{
		//pnt(0,26); cout <<"File opened!";
		while(getline(inFile,fdata))
		{
			//pnt(110,count); cout <<"fdata (before if): " <<fdata; ++count;
			if(fdata==string("ENTRY"))
			{
				//pnt(110,count); cout <<"Entered If.."; ++count;
				getline(inFile,fdata); strcpy(fname,fdata.c_str());
				getline(inFile,fdata); strcpy(fpw,fdata.c_str());
				getline(inFile,fdata); stringstream(fdata)>>fscore;
				addtotail(fname,fpw,fscore);
				//pnt(0,27); cout <<"New Node Created!";
			}
		}
		inFile.close();
	}
}
void Player::saveList()
{
	ofstream outFile("database.txt");
	if(outFile.fail()) cout <<"FILE NOT OPENED!";
	else
	{
		if(head==0){ outFile <<" ";outFile.close();}
		else
		{
			Node *temp;
			for(temp=head;temp!=0;temp=temp->next)
			{
				outFile <<"////////////////////////\n";
				outFile <<"ENTRY\n";
				outFile <<temp->name <<"\n";
				outFile <<temp->password <<"\n";
				outFile <<temp->score <<"\n";
			}
			outFile.close();
		}
		
	}	
}
int Player::sortScore()
{
	Node *k;
	Node *l;
	Node *high;
	Node *low;
	int a,b;
	char tmpname[50],tmpass[50];
	int tmpscore;
	bool exist=false;
	if(head==0) return -1;
	else if(head==tail) return -2;
	else
	{
		for(a=50,b=0,k=head;k!=0;k=k->next)
		{
			for(l=k;l!=0;l=l->next)
			{
				if( (l->score)>(k->score) )
				{
					high=l; exist=true;
				}
			}
			if(exist&&k!=high)
			{
				low=k;
				//saving the "lower data"
				strcpy(tmpname,low->name);
				strcpy(tmpass,low->password);
				tmpscore=low->score;
				//transfering data from high to low
				strcpy(low->name,high->name);
				strcpy(low->password,high->password);
				low->score=high->score;
				//transfering data from saved data to high
				strcpy(high->name,tmpname);
				strcpy(high->password,tmpass);
				high->score=tmpscore;	
				//set flags and temps to default
				exist=false;
				high=0;
				low=0;
			}
		}
	}
}
void Player::displayNode(int startx,int starty,char f[50])
{
	Node *temp;
  int x=startx;
  int y=starty;
   for(temp=head;temp!=0;temp=temp->next)
   {
   		if(strcmp(temp->name,f)==0)
   		{
   		 CreateBox(x,y,30,8);
			 pnt(x+1,y+2); cout <<"Name: " <<temp->name;
			 pnt(x+1,y+3); cout <<"Score: " <<temp->score;
   		}
	 }
}
void Player::displayList(int limit)
{
   Node *temp;
   int x,y,k;
   int xtext=XMENU3;
   int ytext=YMENU3;
   if(head==0) {pnt(10,6); cout <<"No List";}
   else
   for(k=1,x=9,y=5,temp=head;temp!=0;temp=temp->next,++k)
   {
			 pnt(xtext,ytext); cout <<k <<": " <<temp->name;
			 pnt(xtext,ytext+1); cout <<"Score: " <<temp->score;
			 menu3("create",x,y); y+=4;
			 ytext+=4;
			 if(k>=limit) break; //limit up to certain number of people
			 if(y>32)
			 {
			 	 x+=21; y=5;
			 	 xtext+=21 ; ytext=YMENU3;
			 }
	 }
}
void Player::destroyList()
{
	Node *temp;
	for(temp=head;!isEmpty();)
	{
		temp=temp->next;
		if(temp!=0) temp->prev=0;
		delete head;
		head=temp;
	}
}
void Player::addtotail(char f[50],char addpw[50], int p_score)
{
	if(head==0)
	{
		head=tail=new Node(f,addpw,p_score,0,0);
	}
	else if(head!=0&&tail!=0)
	{
		tail=new Node(f,addpw,p_score,tail,0);
		tail->prev->next=tail;
	}
}
bool Player::isInList(char f[10])
{
	if(head!=0)
	{
		Node *tmp;
		for(tmp=head;tmp!=0;tmp=tmp->next)
		{
			if(strcmp(tmp->name,f)==0) return true;
		}
	}
	else
	{
		return false;
	}
}
bool Player::checkPassword(char check[50],char cname[50])
{
	if(head!=0)
	{
		Node *tmp;
		for(tmp=head;tmp!=0;tmp=tmp->next)
		{
			if(strcmp(tmp->name,cname)==0&&strcmp(tmp->password,check)==0) return true;
		}
	}
	return false;
}
void Player::editNode(char f[50],int p_score)
{
	if(head!=0)
	{
		Node *tmp;
		Node *tmp2;
		for(tmp=head;tmp!=0;tmp=tmp->next)
		{
			if(strcmp(tmp->name,f)==0)
			{
				tmp2=tmp; break;
			}
		}
    if(p_score!=-1) //if not default
		{ //change score IF its higher than previous
			if((p_score)>(tmp2->score))
				tmp2->score=p_score;
		}
	}
	else
	{
		cout <<"No List";
	}
}
int Player::delNode(char f[10])
{
	Node *temp, *temp2;
	if(isEmpty()) return 0;
	for(temp=head;temp!=0;temp=temp->next)
	{
		if(strcmp(temp->name,f)==0)
		{
			temp2=temp;
			break;
		}
	}
	if(temp2!=0)
	{
		if(temp2==head&&temp2==tail)
		{
			delete temp2;
			head=tail=0;
		}
		else if(temp2==head)
		{
			head=temp2->next;
			head->prev=0;
			delete temp2;
			temp2=0;
		}
		else if(temp2==tail)
		{
			tail=temp2->prev;
			tail->next=0;
			delete temp2;
			temp2=0;
		}
		else if(temp2->prev!=0&&temp2->next!=0)
		{
			temp2->prev->next=temp2->next;
			temp2->next->prev=temp2->prev;
			delete temp2;
			temp2=0;
		}
	}
	else
	{
		 pnt(0,26);cout <<"Not Found";
	}
}
