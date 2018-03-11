#include "drawing.h"
using namespace std;
namespace LimT_Drawing
{
		void CreateTable(int x,int y,int c,int r, int cs,int rs)
		{
				CreateBox(x,y,(c*cs+c+1),(r*rs+r+1));
				for(int h=y,k=0; k<r-1;k++)
				{
					h=1+h+rs; hzline(x,h,(c*cs+c+1));
					pnt(x,h);        cout <<char(204);
					pnt(x+c*cs+c,h); cout <<char(185);
				}
				for(int l=x,k=0; k<c-1;k++)
				{
					l=1+l+cs; vtline(l,y,(r*rs+r+1));
					pnt(l,y);        cout <<char(203);
					pnt(l,y+r*rs+r); cout <<char(202);
				}
				for(int k=1;k<r;k++)
					{for(int l=1;l<c;l++){pnt(l*(cs+1)+x,k*(rs+1)+y); cout <<char(206);}}
				pnt(0,0);
			}
	void CreateBox(int x,int y,int l, int h)
		{
			hzline(x,y,l); hzline(x,h+y-1,l);
			vtline(x,y,h);   vtline(l+x-1,y,h);	
			pnt(x,y);    cout <<char(201);    pnt(l+x-1,y);     cout <<char(187);
			pnt(x,h+y-1);cout <<char(200);    pnt(l+x-1,h+y-1); cout <<char(188);
			pnt(0,0);
		}
	void CreateTexture(int x, int y, int l, int h)
		{
			for(int k=y;k<(h+y);k++)for(int m=x;m<(l+x);m++){ pnt(m,k); cout <<char(176);} pnt(0,0);
		}
	void EraseBoxMass(int x, int y, int l, int h)
		{
			for(int k=y;k<(h+y);k++)
		  	for(int m=x;m<(l+x);m++)
					{ pnt(m,k); cout <<" ";} pnt(0,0);
		}
	void EraseBox(int x, int y, int l, int h)
		{
			int k,m;
			for(k=x;k<l+x;k++)
			{
				pnt(k,y); cout <<" ";
				pnt(k,y+h-1); cout <<" ";
			}
			for(m=y;m<h+y;m++)
			{
				pnt(x,m); cout <<" ";
				pnt(x+l-1,m); cout <<" ";
			}
		}
	void hzline(int x,int y,int l) 
		{
			for(int k=x;k<(l+x);k++) {pnt(k,y);cout <<char(205);}
		}
	void vtline(int x,int y,int l)
		{
			 for(int k=y;k<(l+y);k++) {pnt(x,k); cout <<char(186); }
		}
	void pnt(int x, int y)
	{COORD point = {x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);}
}
