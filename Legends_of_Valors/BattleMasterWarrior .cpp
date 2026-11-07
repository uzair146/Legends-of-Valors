#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"BattleMasterWarrior.h"
using namespace std;
BattleMasterWarrior::BattleMasterWarrior(string name) : Warrior(name, "Battle Master") {
	this->attackPower = 15;
	this->defensePower = 12;
	this->health = 160;
}
void BattleMasterWarrior::useSkill()  {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== BATTLE MASTER SKILLS ===\033[0m\n";
	cout << "\033[33m1. Precision Strike (Cost: 25 Rage) - Guaranteed critical hit\n";
	cout << "2. Battle Tactics (Cost: 35 Rage) - Increase attack and defense\n";
	cout << "3. Master's Combo (Cost: 45 Rage) - Multiple hits\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (rage >= 25) {
			rage -= 25;
			boostPower = true;
			cout << "\033[32m🎯 Precision Strike ready! Next attack will be critical!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (rage >= 35) {
			rage -= 35;
			BuffAttack(15);
			BuffDefense(10);
			cout << "\033[34m⚔ Battle Tactics improve your combat abilities!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough rage!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (rage >= 45) {
			rage -= 45;
			boostPower = true;
			cout << "\033[32m⚔ Master's Combo ready! Next attack will hit multiple times!\033[0m\n";
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