#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Potion .h"
using namespace std;
class ManaPotion : public Potion {
public:
	ManaPotion(string name, int manaAmount);
};
