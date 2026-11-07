#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"MagicItem.h"
using namespace std;
MagicItem::MagicItem(string name, int effect, string type, int cd)
	: Item(name, "MagicItem", effect), magicType(type), cooldown(cd), isCharged(true) {
}

void MagicItem::useItem(Character* target) {
	if (!isCharged) {
		cout << "\033[34mThis magic item needs " << cooldown << " more turns to recharge!\033[0m\n";
		return;
	}
	if (target) {
		cout << "\033[32m✨ " << itemName << " casts " << magicType << " magic!\033[0m\n";
		isCharged = false;
		// Magic effect implementation
	}
}
 void MagicItem::getDescription() const {
	cout << "\033[33mMagic Item: " << itemName << endl;
	cout << "Type: " << magicType << endl;
	cout << "Effect: " << effectValue << endl;
	cout << "Cooldown: " << cooldown << " turns\033[0m" << endl;
}