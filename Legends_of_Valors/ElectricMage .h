#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Mage.h"
using namespace std;
class ElectricMage : public Mage {
public:
	ElectricMage(string name);
	void useSkill() override;
};

