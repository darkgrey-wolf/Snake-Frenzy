#ifndef DRAWING_H
#define DRAWING_H
#include <iostream>
#include <windows.h> //Only in windows platforms
namespace LimT_Drawing
{
	void CreateTable(int,int,int,int,int,int); // x coordinate, y coordinate , columns, rows, column length, row length
  void CreateTexture(int,int,int,int);// x coordinate, y coordinate, horizontal length, vertical length
	void CreateBox(int,int,int,int);// x coordinate, y coordinate, horizontal length, vertical length
	void EraseBoxMass(int,int,int,int);// x coordinate, y coordinate, horizontal length, vertical length , erase the whole area
	void EraseBox(int,int,int,int);// x coordinate, y coordinate, horizontal length, vertical length, erase only the outline
	void hzline(int,int,int);  //arguments: x coordinate,y coordinate, length of line (horizontally)
	void vtline(int,int,int);//arguments: x coordinate,y coordinate, length of line (vertically)
	void pnt(int,int); //arguments: x coordinate ,y coordinate
}
#endif
