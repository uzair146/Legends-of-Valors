#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
class Axe : public Weapon {
public:
	Axe(string name, int dmg);
};
