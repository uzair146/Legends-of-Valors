#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"character.h"
using namespace std;
class Item {
protected:
	string itemName;
	string itemType;
	int effectValue;
public:
	string getName();
	Item();
	Item(string name, string type, int val);
	virtual void useItem(Character* target) = 0;
	virtual void getDescription() const;
	int getEffectValue() const;
	string getItemType() const;
	virtual ~Item() {};
};

