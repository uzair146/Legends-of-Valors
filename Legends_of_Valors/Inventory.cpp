#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Inventory .h"
using namespace std;
Inventory::Inventory() {
	gold = 0;
	count = 0;
	items = new Item * [10];
	for (int i = 0; i < 10; i++)
		items[i] = nullptr;
}
void Inventory::addItem(Item* item) {
	if (count < 10) {
		items[count] = item;
		count++;
	}
	else {
		cout << "\033[31mThe items list is already full\033[0m " << endl;
	}
}
void Inventory::removeItem(string itemName) {
	for (int i = 0; i < count; i++) {
		if (items[i] && items[i]->getName() == itemName) {
			delete items[i];
			// Shift remaining items left
			for (int j = i; j < count - 1; j++) {
				items[j] = items[j + 1];
			}
			items[count - 1] = nullptr;
			count--;
			break;
		}
	}
}
void Inventory::showInventory() {
	cout << "\n\033[36m=== YOUR INVENTORY ===\033[0m\n";
	cout << "\033[34mGold: \033[0m" << gold << "\n\n";
	if (count == 0) {
		cout << "\033[34mYour inventory is empty!\033[0m\n";
		return;
	}
	cout << "\033[34mItems:\033[0m\n";
	for (int i = 0; i < count; i++) {
		if (items[i] != nullptr) {
			cout << i + 1 << ". ";
			items[i]->getDescription();
		}
	}
}
Item* Inventory::getItem(string itemName) const {
	Item* temp = nullptr;
	for (int i = 0; i < count; i++) {  // Iterate only over used slots
		if (items[i] != nullptr && items[i]->getName() == itemName) {
			temp = items[i];
			break;
		}
	}
	return temp;
}
Inventory::~Inventory() {
	for (int i = 0; i < count; i++) {
		delete items[i];
	}
	delete[] items;
}
void Inventory::addGold(int amount) {
	gold += amount;
}
void Inventory::subtractGold(int amount) {
	if (gold >= amount) {
		gold -= amount;
	}
	else {
		cout << "\033[31mNot enough gold!\033[0m" << endl;
	}
}
int Inventory::getGold() const {
	return gold;
}
Item* Inventory::getItem(int index) const {
	if (index >= 0 && index < 10) {
		return items[index];
	}
	return nullptr;
}