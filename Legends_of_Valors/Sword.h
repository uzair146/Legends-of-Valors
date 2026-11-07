#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
class Sword : public Weapon {
public:
	Sword(string name, int dmg);
};
