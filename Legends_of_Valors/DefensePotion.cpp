#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"DefensePotion.h"
using namespace std;
DefensePotion::DefensePotion(string name, int defenseBoost) : Potion(name, defenseBoost, "Defense", 3) {

}