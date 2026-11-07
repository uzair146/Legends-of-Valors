#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Rogue.h"
using namespace std;
class ThiefRogue : public Rogue {
public:
	ThiefRogue(string name);
	void useSkill() override;
};