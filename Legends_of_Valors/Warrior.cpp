#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Warrior.h"
using namespace std;
Warrior::Warrior(string name, string type) : Character(name), warriorType(type) {
	this->health = 150;
	this->attackPower = 15;
	this->defensePower = 10;
}
