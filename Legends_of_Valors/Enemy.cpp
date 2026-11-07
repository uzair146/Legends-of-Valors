#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Enemy.h"
using namespace std;
Enemy::Enemy(string name) : Character(name), enemyType("Unknown"), dropGold(10), isFrenzied(false) {

}
Enemy::Enemy(string type, int lvl) : Character(type), isFrenzied(false) {
	this->Level(lvl);
	enemyType = type;
	dropGold = 10 + (lvl * 2);  // Changed from lvl * 5 to lvl * 2 for more balanced drops
}
Enemy::Enemy(string name, int lvl, int dG) : enemyType(name), Character(lvl, name) {
	dropGold = dG;  // Use the provided drop gold value
}
void Enemy::useSkill()  {
	if (!canAct()) {
		return;
	}
	if (!isFrenzied) {
		isFrenzied = true;
		cout << "\033[34m😈 " << getName() << " is entering Frenzy Mode!\033[0m" << endl;
	}
	else {
		cout << "\033[31m⚠ " << getName() << " is already in Frenzy Mode!\033[0m" << endl;
	}
}
void Enemy::frenzyAttack(Character* target) {
	if (!canAct()) {
		return;
	}
	if (isFrenzied) {
		isFrenzied = false;
		int baseDamage = getAttackPower();
		int randomBoost = rand() % 10 + 5;
		int damage = baseDamage + randomBoost;
		cout << "\033[35m🔥 " << getName() << " uses Frenzy Attack and strikes with " << damage << " damage!\033[0m" << endl;
		int finalDamage = damage - target->getDefensePower();
		if (finalDamage > 0)
			target->Attack(finalDamage);
		else
			cout << "\033[31m🛡 " << getName() << "'s frenzy was blocked!\033[0m" << endl;
	}
	else {
		cout << "\033[31m❌ Cannot use Frenzy Attack. " << getName() << " is not frenzied yet!\033[0m" << endl;
	}
}
int Enemy::dropLoot() {
	cout << "\033[34m💰 " << getName() << " dropped " << dropGold << " gold!\033[0m" << endl;
	int goldDropped = dropGold;
	dropGold = 0;
	return goldDropped;
}
string Enemy::getType() const {
	return enemyType;
}
bool Enemy::isAlive() {
	return Character::getHealth() > 0;
}
void Enemy::getStats() {
	cout << Character::getName() << " \033[36m- HP: " << Character::getHealth() << ", ATK:\033[0m " << Character::getAttackPower() << endl;
}
int Enemy::getAttackPower() {
	return Character::getAttackPower();
}
string Enemy::getName() {
	return Character::getName();
}