#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include "Mage.h"
using namespace std;
class FireMage : public Mage {
public:
	FireMage(string name);
	void useSkill() override;
};
