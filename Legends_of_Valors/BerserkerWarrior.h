#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Warrior.h"
using namespace std;
class BerserkerWarrior : public Warrior {
public:
	BerserkerWarrior(string name);
	void useSkill() override;
};

