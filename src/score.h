#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Score
{
	private:
		int score;
	public:
		Score()
		{
			ifstream file("ASDF98SFY298YFSD6F7.dat"); //opens/creates the file in input mode
			file>>score; //reads the score
			if(score==-1) score=0; //sometimes empty files contains -1 values
			//pnt(3,16); cout <<"Constructor:    "; //debugging purposes
			//pnt(3,16); cout <<"Constructor:" <<score;
			file.close();
		}
		~Score()
		{
			ofstream file("ASDF98SFY298YFSD6F7.dat"); //opens the file in output mode
			//pnt(3,17); cout <<"Destruct:    ";
			//pnt(3,17); cout <<"Destruct:" <<score;
			file <<score;
			file.close();
		}
		int getScore()
		{ return score;}
		void setScore(int s)
		{ score=s;}
};
#endif
