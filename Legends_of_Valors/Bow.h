#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
class Bow : public Weapon {
public:
	Bow(string name, int dmg);
};
