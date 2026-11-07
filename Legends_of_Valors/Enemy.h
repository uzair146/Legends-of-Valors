#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "character.h"
using namespace std;
class Enemy : public Character {
private:
	string enemyType;
	int dropGold;
	bool isFrenzied;
public:
	Enemy(string name);
	Enemy(string type, int lvl);
	Enemy(string name, int lvl, int dG);
	void useSkill() override;
	void frenzyAttack(Character* target);
	int dropLoot();
	string getType() const;
	bool isAlive();
	void getStats();
	int getAttackPower();
	string getName();
};
