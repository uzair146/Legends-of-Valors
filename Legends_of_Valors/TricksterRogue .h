#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Rogue.h"
using namespace std;
class TricksterRogue : public Rogue {
public:
	TricksterRogue(string name);
	void useSkill() override;
};
