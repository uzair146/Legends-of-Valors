#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "BerserkerWarrior.h"
using namespace std;
BerserkerWarrior::BerserkerWarrior(string name) : Warrior(name, "Berserker") {
	this->attackPower = 18;  // Highest attack
	this->health = 130;      // Lower health
}
void BerserkerWarrior:: useSkill(){
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== BERSERKER SKILLS ===\033[0m\n";
	cout << "\033[33m1. Blood Rage (Cost: 30 Rage) - Triple damage next attack\n";
	cout << "2. Berserker's Fury (Cost: 40 Rage) - Increase attack but take damage\n";
	cout << "3. Death Wish (Cost: 50 Rage) - Massive damage but lose health\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (rage >= 30) {
			rage -= 30;
			boostPower = true;
			cout << "\033[32m💀 Blood Rage activated! Next attack will be devastating!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (rage >= 40) {
			rage -= 40;
			BuffAttack(20);
			Attack(10);  // Take some damage
			cout << "\03334m😡 Berserker's Fury increases attack but hurts you!033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (rage >= 50) {
			rage -= 50;
			Attack(20);  // Take more damage
			boostPower = true;
			cout << "\033[32m⚔ Death Wish activated! Next attack will be powerful!\033[0m\n";
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