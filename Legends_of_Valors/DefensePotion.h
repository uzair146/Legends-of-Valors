#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Potion .h"
class DefensePotion : public Potion {
public:
	DefensePotion(string name, int defenseBoost);
};
