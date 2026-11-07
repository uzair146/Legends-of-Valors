#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Enemy.h"
using namespace std;
class BossEnemy :public Enemy {
	int phase;
	bool enraged;
	Character* currentTarget;
public:
	BossEnemy(string name);
	void setTarget(Character* target);
	void useSkill()override;
	void enterEnragedMode();
	void nextPhase();
	int getPhase();
};
