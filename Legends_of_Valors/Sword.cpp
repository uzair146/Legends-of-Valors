#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Sword.h"
using namespace std;
Sword::Sword(string name, int dmg) : Weapon(name, "Sword", dmg, "High critical hit chance") {

}