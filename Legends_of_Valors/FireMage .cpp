#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"FireMage.h "
using namespace std;
FireMage::FireMage(string name) : Mage(name, "Fire") {
	this->attackPower = 12;  // Higher attack for fire mage
}
void FireMage::useSkill() {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== FIRE MAGE SKILLS ===\033[0m\n";
	cout << "\033[33m1. Fireball (Cost: 30 Mana) - Deal 40 damage\n";
	cout << "2. Flame Shield (Cost: 25 Mana) - Create fire barrier\n";
	cout << "3. Meteor Strike (Cost: 50 Mana) - Massive damage\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (mana >= 30 && currentEnemy) {
			mana -= 30;
			int damage = 40;
			currentEnemy->Attack(damage);
			cout << "\033[32m🔥 Fireball hits for " << damage << " damage!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana or no target!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (mana >= 25) {
			mana -= 25;
			BuffDefense(20);
			cout << "\033[32m🔥 Flame Shield activated! Defense increased!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough mana!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (mana >= 50 && currentEnemy) {
			mana -= 50;
			int damage = 80;
			currentEnemy->Attack(damage);
			cout << "\033[34m☄ Meteor Strike deals " << damage << " damage!\033[0m\n";
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