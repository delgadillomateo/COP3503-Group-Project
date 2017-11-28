

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class PlayerClass
{
private:
	string name;
	int score;
	PlayerClass(string, int);

public:
	void setName(string);
	string getName();
	void printName();
	void addScore(int);
	int getScore(int);
	void printScore();
};

void PlayerClass::setName(string tempN)
{
	name = tempN;
}

string PlayerClass::getName()
{
	return name;
}

void PlayerClass::printName()
{
	cout << name << endl;
}

void PlayerClass::addScore(int tempS)
{
	score = tempS + score;
}

int PlayerClass::getScore(int tempS)
{
	return score;
}

void PlayerClass::printScore()
{
	cout << name << " score is " << score;
}


