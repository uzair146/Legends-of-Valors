#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Potion .h"
using namespace std;
class HealthPotion : public Potion {
public:
	HealthPotion(string name, int healAmount);
};
