#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
class Armor : public Item {
protected:
	int defense;
	string armorType;
	string specialEffect;
public:
	Armor(string name, string type, int def, string effect = "None");
	virtual void useItem(Character* target) override;
	virtual void getDescription() const override;
};
