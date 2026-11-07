#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Warrior.h"
using namespace std;
class BattleMasterWarrior : public Warrior {
public:
	BattleMasterWarrior(string name);
	void useSkill() override;
};
