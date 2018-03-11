// Player.h - player linked list
#ifndef PLAYER_H
#define PLAYER_H
#include "resource.h"
class Player
{
	private:
		///
		struct Node
		{
			char name[50];
			char password[50];
			int score;
			Node *next, *prev;
			Node(char f[50],char pw[50], int p_score, Node *p, Node *n)
			{
				strcpy(name,f);
				strcpy(password,pw);
				score=p_score;
				prev=p;
				next=n;
			}
		};
		///
		Node *head,*tail;
	public:
		Player()
		{ head=tail=0; openList();}
		~Player()
		{ saveList(); destroyList();}
		bool isEmpty()
		{ return head==0;}
		bool isInList(char[]);
		bool checkPassword(char[],char[]);
		int openList();	
		int sortScore();
		void saveList();
		void displayNode(int,int,char[]);
		void displayList(int limit);
		void destroyList();
		void addtotail(char[],char[], int p_score);
		void editNode(char[],int p_score);
		int delNode(char[]);
};
#endif
