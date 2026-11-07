#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Potion .h"
using namespace std;
Potion::Potion(string name, int effect, string type, int dur)
	: Item(name, "Potion", effect), potionType(type), duration(dur) {
}

 void Potion::useItem(Character* target)  {
	if (target) {
		if (potionType == "Healing") {
			target->heal(effectValue);
			cout << "\033[32m✨ " << target->getName() << " healed for " << effectValue << " HP!\033[0m\n";
		}
		else if (potionType == "Mana") {
			// Assuming you add a mana restoration method to Character class
			cout << "\033[32m✨ " << target->getName() << " restored " << effectValue << " Mana!\033[0m\n";
		}
		else if (potionType == "Buff") {
			cout << "\033[32m✨ " << target->getName() << " gained " << effectValue
				<< " " << potionType << " for " << duration << " turns!\033[0m\n";
		}
	}
}
 void Potion::getDescription() const {
	cout << "\033[33mPotion Name: " << itemName << endl;
	cout << "Type: " << potionType << endl;
	cout << "Effect: \033[0m" << effectValue << endl;
	if (duration > 0) {
		cout << "\033[34mDuration: " << duration << " turns\033[0m" << endl;
	}
}