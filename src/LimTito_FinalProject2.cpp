//Programmed by: Lim, Tito Jr. C  >>>Main Program<<<
#include "resource.h"
#include "playermanip.h"
#include "snakeplay.h"
using namespace LimT_Drawing;
using namespace LimT_Menu;
using namespace std;
int chooseDifficulty();
int viewHigh(Player *);
int helpFunc();
int aboutFunc();
int mainMenu(Player *,string,int);
int main()
{
	system("title Snake Frenzy");
	system("color f9");system("cls");system("mode con: cols=150 lines=35");
	Player player;
	string name=STRNULL;
	int difficulty=70;
	mainMenu(&player,name,difficulty);
	return 0;
}
int mainMenu(Player *ms,string name, int difficulty)
{
	int cache;
	string name2;
	menu1("create");
	askMainMenu:
  if(name==STRNULL) name2=NAMEDEFAULT;
  else name2=name;
	pnt(3,1);cout <<MAINHEADER;
	cin.sync();
	pnt(XMENU1,YMENU1); cout <<"Welcome!";
	pnt(XMENU1,YMENU1+1); cout <<name2;
	pnt(XMENU1,YMENU1+3); cout <<"1 Start";
	pnt(XMENU1,YMENU1+4); cout <<"2 Player";
	pnt(XMENU1,YMENU1+5); cout <<"3 Difficulty";
	pnt(XMENU1,YMENU1+6); cout <<"4 High Scores";
	pnt(XMENU1,YMENU1+7); cout <<"5 Help";
	pnt(XMENU1,YMENU1+8); cout <<"6 About";
	pnt(XMENU1,YMENU1+9); cout <<"7 Exit";
	switch(getch())
	{
		case '1': menu1("erase"); play(difficulty,ms,name); break;
		case '2': menu1("erase"); name=playerMenu(ms); break;
		case '3': cache=chooseDifficulty(); 
		          if(cache!=-1) difficulty=cache;
		          break;
		case '4': viewHigh(ms); break;
		case '5': helpFunc(); break;
		case '6': aboutFunc();break;
		case '7': exit(0);
		default: goto askMainMenu;
	}
	mainMenu(ms,name,difficulty);
}
int chooseDifficulty()
{
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"Choose Difficulty";
	pnt(XMENU2,YMENU2+1); cout <<"1. Easy";
	pnt(XMENU2,YMENU2+2); cout <<"2. Very Hard";
	pnt(XMENU2,YMENU2+3); cout <<"3. Impossible";
	switch(getch())
	{
		case '1': menu2("erase");return 70;  break;
		case '2': menu2("erase");return 35; break;
		case '3': menu2("erase");return 10; break;
		case 27: menu2("erase");return -1;
		default: chooseDifficulty();
	}
}
int viewHigh(Player *vh)
{
	int e=vh->sortScore();
	pnt(XMENU3,YMENU3-2); cout <<"High Scores";
	vh->displayList(7);
	getch();
	pnt(XMENU3,YMENU3-2); cout <<"           ";
	EraseBoxMass(9,5,20,30);
}
int helpFunc()
{
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"HELP";
	pnt(XMENU2,YMENU2+2); cout <<"Hello! ";
	pnt(XMENU2,YMENU2+3); cout <<"A,D,W and X corresponds to left, right,";
	pnt(XMENU2,YMENU2+4); cout <<"up and down respectively.";
	pnt(XMENU2,YMENU2+5); cout <<"Please search on Google for more info";
	getch();
	menu2("erase");
}
int aboutFunc()
{
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"ABOUT";
	pnt(XMENU2,YMENU2+2); cout <<"daRkneSs Company CO.,LTD,INC,CORP ";
	pnt(XMENU2,YMENU2+4); cout <<"Core Enginerring:         Lim, Tito Jr. C";
	pnt(XMENU2,YMENU2+5); cout <<"Core Quality Engineering: Lim, Tito Jr. C";
	pnt(XMENU2,YMENU2+6); cout <<"Program Development:      Lim, Tito Jr. C";
	pnt(XMENU2,YMENU2+7); cout <<"Program Quality/Design:   Lim, Tito Jr. C";
	pnt(XMENU2,YMENU2+8); cout <<"No linked lists were hurt in the making of";
	pnt(XMENU2,YMENU2+9); cout <<"this program.";
	getch();
	menu2("erase");
}
