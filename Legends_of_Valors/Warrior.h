#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "character.h"
using namespace std;
class Warrior : public Character {
protected:
	int rage = 100;
	bool boostPower = false;
	bool isBlocking = false;
	string warriorType;
public:
	Warrior(string name, string type);
	virtual void useSkill() = 0;
};
