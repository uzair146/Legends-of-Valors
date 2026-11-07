#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
class Staff : public Weapon {
public:
	Staff(string name, int dmg, string effect = "Increases mana regeneration");
};
