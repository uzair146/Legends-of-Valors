#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"TricksterRogue .h"
using namespace std;
TricksterRogue::TricksterRogue(string name) : Rogue(name, "Trickster") {
	this->energy = 120;      // More energy
	this->defensePower = 10;  // Better defense
}
void TricksterRogue::useSkill()  {
	if (!canAct()) {
		return;
	}
	cout << "\n\033[36m=== TRICKSTER SKILLS ===\033[0m\n";
	cout << "\033[33m1. Smoke Bomb (Cost: 25 Energy) - Vanish and confuse\n";
	cout << "2. Mirror Image (Cost: 35 Energy) - Create decoy\n";
	cout << "3. Trickster's Gambit (Cost: 40 Energy) - Dodge and counter\033[0m\n";
	cout << "\033[34m4. Back\033[0m\n";
	int choice;
	cout << "\033[35mEnter skill choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (energy >= 25) {
			energy -= 25;
			isVanished = true;
			cout << "\033[32m💨 Smoke Bomb deployed! You've vanished!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (energy >= 35) {
			energy -= 35;
			cout << "\033[32m🔄 Mirror Image created! Enemy might hit the wrong target!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough energy!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (energy >= 40) {
			energy -= 40;
			isVanished = true;
			cout << "\033[34m🎭 Trickster's Gambit activated! Ready to counter!\033[0m\n";
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