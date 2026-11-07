#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Mage.h"
using namespace std;
Mage::Mage(string name, string element) : Character(name), currentEnemy(nullptr), elementType(element) {
	this->health = 100;
	this->mana = 100;
	this->attackPower = 10;
	this->defensePower = 5;
}
void Mage::setCurrentEnemy(Character* enemy) {
	currentEnemy = enemy;
}
