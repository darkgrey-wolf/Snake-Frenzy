//Playermanip
// -player menus
// - select/adding of player
// - checking if exist/ checking of password
// -returns player name to be used by snake play
#include "playermanip.h"
using namespace std;
using namespace LimT_Menu;
using namespace LimT_Drawing;
string playerMenu(Player *pm)
{
	string name;
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"Player";
	pnt(XMENU2,YMENU2+1); cout <<"1 Choose Player";
	pnt(XMENU2,YMENU2+2); cout <<"2 New Player";
	pnt(XMENU2,YMENU2+3); cout <<"3 Delete Player";
	pnt(XMENU2,YMENU2+4); cout <<"4 Clear Data";
	pnt(XMENU2,YMENU2+5); cout <<"ESC Go back";
	askPlayerMenu:
	switch(getch())
	{
		case '1': name=selectPlayer(pm); menu3("erase",-1,-1);break;
		case '2': name=addPlayer(pm);    menu3("erase",-1,-1);break;
		case '3': name=deletePlayer(pm); menu3("erase",-1,-1);break;
		case '4': name=clearPlayers(pm); menu3("erase",-1,-1);break;
		case  27: name=STRNULL;          menu3("erase",-1,-1); break;
		default: goto askPlayerMenu;
	}
	menu2("erase");
	return name;
}
string addPlayer(Player *as)
{
	string fn;
	char cfn[50];
	char password[50];
	menu2("erase");
	menu2("create");
	pnt(XMENU2,YMENU2); cout <<"Player";
	pnt(XMENU2,YMENU2+1); cout <<"Name: "; getline(cin,fn);
	strcpy(cfn,fn.c_str());
	if(as->isInList(cfn))
	{
		pnt(XMENU2,YMENU2+2); cout <<"Player already exist!";
		pnt(XMENU2,YMENU2+3); cout <<"ESC to go back";
		pnt(XMENU2,YMENU2+4); cout <<"Any key to try again";
		switch(getch())
		{
			case 27: return string(STRNULL);
			default: return fn=addPlayer(as);
		}
	}
	pnt(XMENU2,YMENU2+2);cout <<"Password: "; cin.getline(password,50);
	pnt(XMENU2,YMENU2+3);
	
	as->addtotail(cfn,password,0);
	as->saveList();
	menu2("erase");
	return fn;
}
string selectPlayer(Player *sp)
{
	string name;
	char cname[50];
	char cpassword[50];
	menu2("erase");
	menu2("create");
	if(sp->isEmpty()){pnt(XMENU2,YMENU2); cout <<"No Players";
	                  pnt(XMENU2,YMENU2+1); cout <<"Press any key...";
	                  getch(); return string(STRNULL);
	}
	pnt(XMENU3,YMENU3-2); cout <<"Players";
	sp->displayList(10); // display only 10 players
	pnt(XMENU2,YMENU2); cout <<"Select Player";
	pnt(XMENU2,YMENU2+1); cout <<"Input Name: "; getline(cin,name);
	///strings and c-strings is quite... exhausting
	strcpy(cname,name.c_str());
	if(!sp->isInList(cname))
	{
		pnt(XMENU2,YMENU2+5); cout <<"Not in the list!"; getch();
		pnt(XMENU2,YMENU2+5);  cout <<"                 ";
	}
	else if(sp->isInList(cname))
	{
		askPassword:
		pnt(XMENU2,YMENU2+2); cout <<"                  ";
		pnt(XMENU2,YMENU2+3);cout <<"                       ";
		pnt(XMENU2,YMENU2+4); cout <<"                             ";
		pnt(XMENU2,YMENU2+1); cout <<"Please Input Password:                    "; 
		pnt(XMENU2+23,YMENU2+1); cin.getline(cpassword,50);
		pnt(XMENU2,YMENU2+2);
		if( sp->checkPassword( cpassword, cname ) )
		{
			pnt(XMENU3,YMENU3-2); cout <<"       ";
			return name;
		}
		else
		{
			pnt(XMENU2,YMENU2+2); cout <<"Invalid Password!";
			pnt(XMENU2,YMENU2+3);cout <<"Press any key to retry";
			pnt(XMENU2,YMENU2+4); cout <<"and Esc to select new player.";
			switch( getch())
			{
				case 27:  return selectPlayer(sp);
				default: goto askPassword;
			}
		}
	}
	askSelectPlayer:
	pnt(XMENU2,YMENU2+1); cout <<"Press enter to try again or Esc to go back";
	switch(getch())
	{
		case 13: return selectPlayer(sp);
		case 27: return string(STRNULL);break;
		default: goto askSelectPlayer;
	}
	goto askSelectPlayer;
}
string deletePlayer(Player *dp)
{
	string name;
	string defpassword="admin";
	string cpassword;
	char cname[50];
	menu2("erase");
	menu2("create");
	if(dp->isEmpty()){pnt(XMENU2,YMENU2); cout <<"No Players";
	                  pnt(XMENU2,YMENU2+1); cout <<"Press any key...";
	                  getch(); return string(STRNULL);
	}
	dp->displayList(10); // display only 10 players
	pnt(XMENU2,YMENU2); cout <<"Select Player";
	pnt(XMENU2,YMENU2+1); cout <<"Input Name: "; getline(cin,name);
	strcpy(cname,name.c_str());
	if(!dp->isInList(cname))
	{
		pnt(XMENU2,YMENU2+5); cout <<"Not in the list!"; getch();
		pnt(XMENU2,YMENU2+5);  cout <<"                 ";
	}
	else if(dp->isInList(cname))
	{
		askDelPassword:
		pnt(XMENU2,YMENU2+1); cout <<"Administrative Password:"; 
		cin.sync();
		pnt(XMENU2+25,YMENU2+1); getline(cin,cpassword);
		pnt(XMENU2,YMENU2+2);
		if(cpassword==defpassword)
		{
			dp->delNode(cname);
			dp->saveList();
			pnt(XMENU2,YMENU2+1);cout <<"Player successfully deleted!             ";
			menu3("erase",-1,-1);
			dp->displayList(10);
			getch();
			return string(STRNULL);
		}
		else
		{
			pnt(XMENU2,YMENU2+2); cout <<"Invalid Password!";
			pnt(XMENU2,YMENU2+3);cout <<"Press any key to retry";
			pnt(XMENU2,YMENU2+4); cout <<"and Esc to select new player.";
			switch( getch())
			{
				case 27:  return deletePlayer(dp);
				default: goto askDelPassword;
			}
		}
	}
	askDeletePlayer:
	pnt(XMENU2,YMENU2+1); cout <<"Press enter to try again or Esc to go back";
	switch(getch())
	{
		case 13: return selectPlayer(dp);
		case 27: name=STRNULL; return name; break;
		default: goto askDeletePlayer;
	}
	goto askDeletePlayer;
}
string clearPlayers(Player *cp)
{
	string name;
	string defpassword="admin";
	string cpassword;
	menu2("erase");
	menu2("create");
	if(cp->isEmpty()){pnt(XMENU2,YMENU2); cout <<"No Players";
	                  pnt(XMENU2,YMENU2+1); cout <<"Press any key...";
	                  getch(); return string(STRNULL);
	}
	cp->displayList(10); // display only 10 players
	pnt(XMENU2,YMENU2); cout <<"Clearing all data.";
	askClearData:
	pnt(XMENU2,YMENU2+1); cout <<"Input Administrative Password:";
	pnt(XMENU2,YMENU2+2); cout <<"(Input -1 to cancel)";
	pnt(XMENU2+32,YMENU2+1); getline(cin,cpassword);
	if(cpassword==defpassword)
	{
		cp->destroyList();
		cp->saveList();
		pnt(XMENU2,YMENU2+3); cout <<"All players cleared!";
		return string(STRNULL);
	}
	else if(cpassword==string("-1"))
	{
		pnt(XMENU2,YMENU2+3); cout <<"Canceled!"; getch();
		return string(STRNULL);
	}
	else
	{
		pnt(XMENU2,YMENU2+3); cout <<"Invalid password!   "; getch();
		goto askClearData;
	}
}

