#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Staff.h"
using namespace std;

Staff::Staff(string name, int dmg, string effect)
	: Weapon(name, "Staff", dmg, effect) {
}
