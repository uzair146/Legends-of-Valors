#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"GuardianWarrior.h"
using namespace std;
GuardianWarrior::GuardianWarrior(string name) : Warrior(name, "Guardian") {
	this->defensePower = 15;  // Highest defense
	this->health = 180;       // Highest health
}
void GuardianWarrior::useSkill() {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== GUARDIAN SKILLS ===\033[0m\n";
	cout << "\033[33m1. Shield Wall (Cost: 20 Rage) - Block next attack\n";
	cout << "2. Defensive Stance (Cost: 30 Rage) - Increase defense\n";
	cout << "3. Guardian's Protection (Cost: 40 Rage) - Heal and increase defense\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (rage >= 20) {
			rage -= 20;
			isBlocking = true;
			cout << "\033[32m🛡 Shield Wall activated! Next attack will be blocked!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (rage >= 30) {
			rage -= 30;
			BuffDefense(25);
			cout << "\033[34m🛡 Defensive Stance increases your defense!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (rage >= 40) {
			rage -= 40;
			heal(30);
			BuffDefense(15);
			cout << "\033[34m✨ Guardian's Protection heals and protects you!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 4:
		return;
	default:
		cout << "\033[31mInvalid choice!\033[0m\n";
	}
}