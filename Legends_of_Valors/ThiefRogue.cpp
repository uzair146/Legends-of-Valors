#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"ThiefRogue .h"
using namespace std;
ThiefRogue::ThiefRogue(string name) : Rogue(name, "Thief") {
	this->health = 130;      // More health
	this->attackPower = 10;  // Lower attack
}
void ThiefRogue::useSkill() {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== THIEF SKILLS ===\033[0m\n";
	cout << "\033[33m1. Pickpocket (Cost: 20 Energy) - Steal gold from enemy\n";
	cout << "2. Evasion (Cost: 30 Energy) - Dodge next attack\n";
	cout << "3. Lucky Strike (Cost: 35 Energy) - Chance for critical hit\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (energy >= 20) {
			energy -= 20;
			cout << "\033[32m💰 Pickpocket attempt! Trying to steal gold!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (energy >= 30) {
			energy -= 30;
			isVanished = true;
			cout << "\033[32m🎯 Evasion activated! Next attack will be dodged!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (energy >= 35) {
			energy -= 35;
			cout << "\033[34m🍀 Lucky Strike ready! Next attack might be critical!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 4:
		return;
	default:
		cout << "\033[31mInvalid choice!\033[0m\n";
	}
}