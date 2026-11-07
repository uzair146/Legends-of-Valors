#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Mage.h"
using namespace std;
class WaterMage : public Mage {
public:
	WaterMage(string name);
	void useSkill() override;
};

