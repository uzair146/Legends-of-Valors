#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"WaterMage .h"
using namespace std;
WaterMage::WaterMage(string name) : Mage(name, "Water") {
	this->health = 120;  // More HP for water mage
}
void WaterMage::useSkill()  {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== WATER MAGE SKILLS ===\033[0m\n";
	cout << "\033[33m1. Tidal Wave (Cost: 30 Mana) - Deal damage and slow\n";
	cout << "2. Healing Waters (Cost: 35 Mana) - Heal self\n";
	cout << "3. Tsunami (Cost: 45 Mana) - Area damage\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (mana >= 30 && currentEnemy) {
			mana -= 30;
			int damage = 35;
			currentEnemy->Attack(damage);
			currentEnemy->setFrozen(true);
			cout << "\033[32m🌊 Tidal Wave hits for " << damage << " damage and freezes!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana or no target!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (mana >= 35) {
			mana -= 35;
			heal(50);
			cout << "\033[34m💧 Healing Waters restore 50 HP!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (mana >= 45 && currentEnemy) {
			mana -= 45;
			int damage = 60;
			currentEnemy->Attack(damage);
			cout << "\033[34m🌊 Tsunami deals " << damage << " damage!\033[0m\n";
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