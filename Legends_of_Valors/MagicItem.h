#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
class MagicItem : public Item {
protected:
	string magicType;
	int cooldown;
	bool isCharged;
public:
	MagicItem(string name, int effect, string type, int cd = 3);
	virtual void useItem(Character* target) override;
	virtual void getDescription() const override;
};
