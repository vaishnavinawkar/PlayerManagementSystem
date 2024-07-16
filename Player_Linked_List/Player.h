#include <iostream>
#include <string.h>
//#include <fstream>
//using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
		int jersey_no;
		char name[30];
		int runs;
		int wickets;
		int no_matches;


	public:
		//constuctors
		Player();
		Player(int,char*,int,int,int);

		//setters
		void setName(char*);
		void setJersey_no(int);
		void setRun(int);
		void setWickets(int);
		void setMatches(int);
		//getters
		char* getName();
		int getJersey_no();
		int getRun();
		int getWickets();
		int getMatches();

		//functions
		void Display();


};

#endif