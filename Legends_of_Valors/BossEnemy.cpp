#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"BossEnemy.h"
using namespace std;
BossEnemy::BossEnemy(string name) : Enemy(name), phase(1), enraged(false) {

}
void BossEnemy::setTarget(Character* target) {
	currentTarget = target; // Set the target for this boss
}
void BossEnemy::useSkill() {
	if (!canAct()) {
		return;
	}
	if (currentTarget == nullptr) {
		cout << "\033[34mNo target to attack!\033[0m" << endl;
		return;
	}
	if (enraged) {
		cout << "\033[32m🔥 Boss is ENRAGED! Using 'Frenzy Attack' with double damage!\033[0m" << endl;
		frenzyAttack(currentTarget);  // Perform a frenzy attack with increased damage
	}
	else {
		cout << "\033[34mBoss is not enraged, using regular attack.\033[0m" << endl;
		frenzyAttack(currentTarget);  // Regular Frenzy Attack (if not enraged)
	}
}
void BossEnemy::enterEnragedMode() {
	cout << "\033[35mEnter the choice:\033[0m\n \033[36m1. Enraged Mode\n 2. Calm Mode\033[0m\n" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		enraged = true;
		cout << "\033[34mBoss has entered ENRAGED mode!\033[0m" << endl;
	}
	else if (choice == 2) {
		enraged = false;
		cout << "\033[35mBoss has calmed down.\033[0m" << endl;
	}
	else {
		cout << "\033[31mInvalid choice!\033[0m" << endl;
	}
}
void BossEnemy::nextPhase() {
	phase++;
	cout << "\033[34mBoss has entered phase " << phase << "!\033[0m" << endl;
}
int BossEnemy::getPhase() {
	return phase;
}