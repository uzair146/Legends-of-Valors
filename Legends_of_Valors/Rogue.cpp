#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Rogue.h"
using namespace std;
Rogue::Rogue(string name, string type) : Character(name), isVanished(false), rogueType(type) {
	this->health = 120;
	this->attackPower = 12;
	this->defensePower = 8;
}