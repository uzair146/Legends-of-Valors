#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Rogue.h"
using namespace std;
class AssassinRogue : public Rogue {
public:
	AssassinRogue(string name);
	void useSkill() override;
};

