#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"AssassinRogue.h"
using namespace std;
AssassinRogue::AssassinRogue(string name) : Rogue(name, "Assassin") {
	this->attackPower = 15;  // Highest attack
	this->health = 100;      // Lowest health
}
void AssassinRogue::useSkill()  {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== ASSASSIN SKILLS ===\033[0m\n";
	cout << "\033[33m1. Shadow Strike (Cost: 30 Energy) - High damage from stealth\n";
	cout << "2. Poison Blade (Cost: 25 Energy) - Apply poison damage\n";
	cout << "3. Death Mark (Cost: 40 Energy) - Mark target for death\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (energy >= 30) {
			energy -= 30;
			isVanished = true;
			cout << "\033[32m👻 Shadow Strike ready! Next attack will be from stealth!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (energy >= 25) {
			energy -= 25;
			cout << "\033[34m☠ Poison Blade applied! Target will take damage over time!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (energy >= 40) {
			energy -= 40;
			cout << "\033[32m💀 Death Mark applied! Target will take increased damage!\033[0m\n";
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