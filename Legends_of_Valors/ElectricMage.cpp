#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"ElectricMage .h"
using namespace std;
ElectricMage::ElectricMage(string name) : Mage(name, "Electric") {
	this->mana = 120;  // More mana for electric mage
}
void ElectricMage::useSkill()  {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== ELECTRIC MAGE SKILLS ===\033[0m\n";
	cout << "\033[33m1. Lightning Bolt (Cost: 25 Mana) - Quick damage\n";
	cout << "2. Static Shield (Cost: 30 Mana) - Reflect damage\n";
	cout << "3. Thunder Storm (Cost: 40 Mana) - Chain lightning\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (mana >= 25 && currentEnemy) {
			mana -= 25;
			int damage = 45;
			currentEnemy->Attack(damage);
			cout << "\033[32m⚡ Lightning Bolt hits for " << damage << " damage!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana or no target!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (mana >= 30) {
			mana -= 30;
			BuffDefense(15);
			cout << "\033[32m⚡ Static Shield activated! Defense increased!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (mana >= 40 && currentEnemy) {
			mana -= 40;
			int damage = 55;
			currentEnemy->Attack(damage);
			cout << "\033[34m⚡ Thunder Storm deals " << damage << " damage!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana or no target!\033[0m\n";
		}
		break;
	}
	case 4:
		return;
	default:
		cout << "\033[31mInvalid choice!\033[0m\n";
	}
}