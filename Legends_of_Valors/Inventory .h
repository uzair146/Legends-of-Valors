#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
class Inventory {
private:
	Item** items;
	int gold;
	int count = 0;
public:
	Inventory();
	void addItem(Item* item);
	void removeItem(string itemName);
	void showInventory();
	Item* getItem(string itemName) const;
	~Inventory();
	void addGold(int amount);
	void subtractGold(int amount);
	int getGold() const;
	Item* getItem(int index) const;
};

