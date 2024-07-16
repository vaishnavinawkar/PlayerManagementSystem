#include "Player.h"
#include <iostream>
//#include <cstring>
//#include <iomanip>
using namespace std;

//constuctors
Player::Player() {
	jersey_no=0;
	strcpy(name,"Not given");
	runs=0;
	wickets=0;
	no_matches=0;
}

/*--------------------------------------------------------------------------------*/
Player::Player(int jr_no,char* nm,int r,int w,int m) {

	jersey_no=jr_no;
	strcpy(name,nm);
	runs=r;
	wickets=w;
	no_matches=m;

}

/*--------------------------------------------------------------------------------*/
//setters
void Player::setName(char* nm) {
	strcpy(this->name,nm);
}
void Player::setJersey_no(int jr_no) {
	this->jersey_no=jr_no;
}
void Player::setRun(int r) {
	this->runs=r;
}
void Player::setWickets(int w) {
	this->wickets=w;
}
void Player::setMatches(int m) {
	this->no_matches=m;
}
/*--------------------------------------------------------------------------------*/
//getters
char* Player::getName() {
	return this->name;
}
int Player::getJersey_no() {
	return this->jersey_no;
}
int Player::getRun() {
	return this->runs;
}
int Player::getWickets() {
	return this->wickets;
}
int Player::getMatches() {
	return this->no_matches;
}
/*--------------------------------------------------------------------------------*/

//functions

void Player::Display() {
   cout<<"\n";

	cout<<"\n---------------------------------------------------------------------------------------------------------\n";
	cout<<"|  JERSEY NO.   |  PLAYER NAME                    |  Total Matches  |  Runs           |  Wickets        |\n";
	cout<<"--------------------------------------------------------------------------------------------------------\n";

	printf("| %8d     |  %-30s |  %10d     |  %10d     |  %10d     |\n", this->getJersey_no(), this->getName(), this->getMatches(), this->getRun(), this->getWickets());
	cout<<"-------------------------------------------------------------------------------------------------------\n";

}






//	cout<<"\nName of player : "<<this->getName();
//	cout<<"\nJersey number of  player : "<<this->getJersey_no();
//	cout<<"\nRuns : "<<this->getRun();
//	cout<<"\nWickets : "<<this->getWickets();
//	cout<<"\nNumber of Matches : "<<this->getMatches();

