#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"character.h"
using namespace std;
bool Character::canAct() {
	if (isFrozen) {
		cout << name << "\033[31m is frozen and cannot act this turn!\033[0m" << endl;
		isFrozen = false;  // Only frozen for one turn
		return false;
	}
	return true;
}
Character::Character() : isFrozen(false), name("Unknown"), level(1), health(100), mana(50), experience(0), attackPower(10), defensePower(5), gold(0) {
}
Character::Character(string n) : isFrozen(false), name(n), level(1), health(100), mana(50), experience(0), attackPower(10), defensePower(5), gold(0) {
}
Character::Character(int lvl, string n) : isFrozen(false), name(n), level(lvl), health(100 + (lvl * 10)), mana(50 + (lvl * 5)), experience(0), attackPower(10 + (lvl * 2)), defensePower(5 + lvl), gold(0) {
}
void Character::setName(string n) {
	name = n;
}
void Character::showStats()const {
	cout << "\033[36mName: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << health << endl;
	cout << "Mana: " << mana << endl;
	cout << "Experience: " << experience << endl;
	cout << "Attack Power: " << attackPower << endl;
	cout << "Defense Power: \033[0m" << defensePower << endl;
}
void Character::levelUp() {
	level++;
}
void Character::Level(int lvl) {
	this->level = lvl;
}
void Character::attack(Character* enemy) {
	if (!canAct()) {
		return;
	}
	int damage = this->attackPower - enemy->defensePower;
	if (damage > 0) {
		enemy->health -= damage;
		cout << this->name << "\033[34m attacked " << enemy->name << " for damage\033[0m " << damage << endl;
	}
	else {
		enemy->health -= 0;
		cout << "\033[31mEnemy defense-power is more than your attack power \033[0m" << endl;
	}
}
void Character::heal(int amount) {
	health += amount;
}
Character::~Character() {

}
int Character::getAttackPower() {
	return attackPower;
}
int Character::getDefensePower() {
	return defensePower;
}
void Character::Attack(int damage) {
	health -= damage;
}
void Character::setFrozen(bool status) {
	isFrozen = status;
}
bool Character::getFrozen() const {
	return isFrozen;
}
void Character::collectGold(int amount) {
	gold += amount;
	cout << "\033[32m🪙 " << amount << " gold collected. Total gold:\033[0m " << gold << endl;
}
string Character::getName() {
	return name;
}
void Character::BuffAttack(int amount) {
	attackPower += amount;
	cout << name << "\033[32m's attack power increased to " << attackPower << "\033[0m!" << endl;
}
void Character::BuffDefense(int amount) {
	defensePower += amount;
	cout << name << "\033[32m's defense power increased to " << defensePower << "\033[0m!" << endl;
}
int Character::getHealth() {
	return health;
}
bool Character::isAlive() {
	if (health > 0) {
		return true;
	}
	else return false;
}