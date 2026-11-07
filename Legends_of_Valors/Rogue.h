#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "character.h"
class Rogue : public Character {
protected:
	int energy = 100;
	bool isVanished;
	int comboPoints = 0;
	string rogueType;
public:
	Rogue(string name, string type);
	virtual void useSkill() = 0;
};
