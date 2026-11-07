#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "character.h"
using namespace std;
class Mage : public Character {
protected:
	int mana = 100;
	Character* currentEnemy;
	string elementType;
public:
	Mage(string name, string element);
	void setCurrentEnemy(Character* enemy);
	virtual void useSkill() = 0;
};
