#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Dagger.h"
using namespace std;
Dagger::Dagger(string name, int dmg, string effect)
	: Weapon(name, "Dagger", dmg, effect) {
}
