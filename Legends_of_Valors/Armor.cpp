#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Armor.h"
using namespace std;
Armor::Armor(string name, string type, int def, string effect)
	: Item(name, "Armor", def), defense(def), armorType(type), specialEffect(effect) {
}

 void Armor::useItem(Character* target)  {
	if (target) {
		target->BuffDefense(defense);
		cout << "\033[32m🛡 " << target->getName() << " equipped " << itemName << "!\033[0m\n";
		if (specialEffect != "None") {
			cout << "\033[34mSpecial Effect:\033[0m " << specialEffect << endl;
		}
	}
}
 void Armor::getDescription() const  {
	cout << "\033[33mArmor Name: " << itemName << endl;
	cout << "Type: " << armorType << endl;
	cout << "Defense: " << defense << endl;
	cout << "Special Effect:\033[0m " << specialEffect << endl;
}