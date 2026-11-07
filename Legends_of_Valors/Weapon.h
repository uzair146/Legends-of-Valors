#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
class Weapon : public Item {
protected:
	int damage;
	string weaponType;
	string specialEffect;
public:
	Weapon(string name, string type, int dmg, string effect = "None");
	virtual void useItem(Character* target) override;
	virtual void getDescription() const override;
};
