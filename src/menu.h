// menu boxes
#ifndef MENU_H
#define MENU_H
#include "resource.h"
using namespace std;
using namespace LimT_Drawing;
namespace LimT_Menu
{
	void menu1(string operation); //main menu box
	void menu2(string operation); //Difficulty/Change player/Help Menu
	void menu3(string operation,int j, int k); //highScore boxes
	void menu4(string operation); //Stat viewing menu
	void gameField(string operation); //General game field
}
#endif
