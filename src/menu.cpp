#include "menu.h"
using namespace std;
using namespace LimT_Drawing;
namespace LimT_Menu
{
	void menu1(string operation)
	{
		if(operation==CREATE)
			CreateBox(134,1,15,12);
		else if(operation==DESTROY)
		  EraseBoxMass(134,1,15,12);
	}
	void menu2(string operation)
	{
		if(operation==CREATE)
			CreateBox(50,5,50,15);
		else if(operation==DESTROY)
		  EraseBoxMass(50,5,50,15);
	}
	void menu3(string operation, int j, int k)
	{ // (9,5) by default
		if(operation==CREATE)
			CreateBox(j,k,20,4);
		else if(operation==DESTROY&&j==-1&&k==-1)
			EraseBoxMass(9,5,20,32);
	}
	void menu4(string operation)
	{
		if(operation==CREATE)
			CreateBox(1,29,15,4);
		else if(operation==DESTROY)
		  EraseBoxMass(1,29,40,4);
	}
	void gameField(string operation)
	{
		if(operation==CREATE)
			CreateBox(1,1,148,28);
		if(operation==DESTROY)
			EraseBox(1,1,148,28);
	}
}
