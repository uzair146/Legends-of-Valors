#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Item.h"
using namespace std;
string Item::getName() {
	return itemName;
}
Item::Item() : itemName("Unknown"), itemType("None"), effectValue(0) {

}
Item::Item(string name, string type, int val) :itemName(name), itemType(type), effectValue(val) {

}
void Item::getDescription() const {
	cout << "\033[33mItem Name: " << itemName << endl;
	cout << "Item Type: " << itemType << endl;
	cout << "Effect Value: \033[0m" << effectValue << endl;
}
int Item::getEffectValue() const {
	return effectValue;
}
string Item::getItemType() const {
	return itemType;
}