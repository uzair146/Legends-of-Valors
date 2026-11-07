#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
class Character {
protected:
	bool isFrozen = false;
	string name;
	int level;
	int health;
	int mana;
	int experience;
	int attackPower;
	int defensePower;
	int gold = 0;
protected:
	bool canAct();
public:
	Character();
	void setName(string n);
	Character(string n);
	Character(int lvl, string n = "Unknown");
	void showStats()const;
	void levelUp();
	void Level(int lvl);
	virtual void useSkill() = 0;
	virtual void attack(Character* enemy);
	void heal(int amount);
	~Character();
	int getAttackPower();
	int getDefensePower();
	virtual void Attack(int damage);
	void setFrozen(bool status);
	bool getFrozen() const;
	void collectGold(int amount);
	string getName();
	void BuffAttack(int amount);
	void BuffDefense(int amount);
	int getHealth();
	bool isAlive();
};
