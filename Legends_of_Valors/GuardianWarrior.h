#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Warrior.h"
using namespace std;
class GuardianWarrior : public Warrior {
public:
	GuardianWarrior(string name);
	void useSkill() override;
};

