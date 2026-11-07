#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
Weapon::Weapon(string name, string type, int dmg, string effect)
	: Item(name, "Weapon", dmg), damage(dmg), weaponType(type), specialEffect(effect) {
}

void Weapon::useItem(Character* target)  {
	if (target == nullptr) {
		cout << "\033[34mNo target to use the weapon on!\033[0m" << endl;
		return;
	}
	cout << "\033[32m🗡 " << itemName << " strikes " << target->getName()
		<< " for " << damage << " damage!\033[0m" << endl;
	if (specialEffect != "None") {
		cout << "\033[34mSpecial Effect: \033[0m" << specialEffect << endl;
	}
	target->Attack(damage);
}
 void Weapon::getDescription() const {
	cout << "\033[33mWeapon Name: " << itemName << endl;
	cout << "Type: " << weaponType << endl;
	cout << "Damage: " << damage << endl;
	cout << "Special Effect:\033[0m " << specialEffect << endl;
}