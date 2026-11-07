#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Weapon.h"
using namespace std;
class Dagger : public Weapon {
public:
	Dagger(string name, int dmg, string effect = "Quick attack, can attack twice");
};
