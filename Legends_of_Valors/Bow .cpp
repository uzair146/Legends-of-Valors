#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Bow.h"
using namespace std;
Bow::Bow(string name, int dmg) : Weapon(name, "Bow", dmg, "Long range attack, can't be countered") {

}