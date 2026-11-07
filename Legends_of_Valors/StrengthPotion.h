#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Potion .h"
class StrengthPotion : public Potion {
public:
	StrengthPotion(string name, int strengthBoost);
};