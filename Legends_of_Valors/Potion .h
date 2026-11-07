#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
class Potion : public Item {
protected:
	string potionType;
	int duration;  // For buff potions
public:
	Potion(string name, int effect, string type = "Healing", int dur = 0);
	virtual void useItem(Character* target) override;
	virtual void getDescription() const override;
};