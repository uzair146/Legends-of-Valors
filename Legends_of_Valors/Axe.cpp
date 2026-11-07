#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Axe.h"
using namespace std;
Axe::Axe(string name, int dmg) : Weapon(name, "Axe", dmg + 5, "Ignores 20% of defense") {

}