#include"Armor.h"
#include "AssassinRogue.h"
#include"Axe.h"
#include "BattleMasterWarrior.h"
#include "BerserkerWarrior.h"
#include"Dagger.h"
#include "ElectricMage .h"
#include "FireMage.h"
#include"Game.h"
#include "GuardianWarrior.h"
#include"HealthPotion.h"
#include"Sword.h"
#include "ThiefRogue .h"
#include "TricksterRogue .h"
#include "WaterMage .h"
#include"Weapon.h"
#include <cstdlib>
#include<cstring>
#include <fstream>
#include<iostream>
#include<string>
#include"Staff.h"
#include"Bow.h"
#include"ManaPotion.h"
#include"DefensePotion.h"
#include"StrengthPotion.h"
#include"MageRobe.h"
#include"ArcaneCloak .h"
#include"LeatherArmor.h"
#include"ElementalMantle.h"
#include"ShadowCloak .h"
#include"AssassinGarb.h"
#include"PlateArmor.h"
#include"ChainMail.h"
#include"LightningRod.h"
#include"BattleArmor.h"
#include"HealingStaff.h"
#include"FireWand.h"
#include"FrostWand .h"
using namespace std;
// Helper function to save character data
void Game::saveCharacterData(ofstream& file) {
	file << player->getName() << endl;
	file << player->getHealth() << endl;
	file << player->getAttackPower() << endl;
	file << player->getDefensePower() << endl;
	// Save class type
	if (dynamic_cast<BerserkerWarrior*>(player)) {
		file << "BerserkerWarrior" << endl;
	}
	else if (dynamic_cast<GuardianWarrior*>(player)) {
		file << "GuardianWarrior" << endl;
	}
	else if (dynamic_cast<BattleMasterWarrior*>(player)) {
		file << "BattleMasterWarrior" << endl;
	}
	else if (dynamic_cast<FireMage*>(player)) {
		file << "FireMage" << endl;
	}
	else if (dynamic_cast<WaterMage*>(player)) {
		file << "WaterMage" << endl;
	}
	else if (dynamic_cast<ElectricMage*>(player)) {
		file << "ElectricMage" << endl;
	}
	else if (dynamic_cast<AssassinRogue*>(player)) {
		file << "AssassinRogue" << endl;
	}
	else if (dynamic_cast<TricksterRogue*>(player)) {
		file << "TricksterRogue" << endl;
	}
	else if (dynamic_cast<ThiefRogue*>(player)) {
		file << "ThiefRogue" << endl;
	}
}
// Helper function to save inventory data
void Game::saveInventoryData(ofstream& file) {
	file << inventory.getGold() << endl;
	// Save number of items
	int itemCount = 0;
	for (int i = 0; i < 10; i++) {
		if (inventory.getItem(i) != nullptr) itemCount++;
	}
	file << itemCount << endl;
	// Save each item
	for (int i = 0; i < 10; i++) {
		Item* item = inventory.getItem(i);
		if (item != nullptr) {
			file << item->getName() << endl;
			file << item->getItemType() << endl;
			file << item->getEffectValue() << endl;
		}
	}
}
// Helper function to save map data
void Game::saveMapData(ofstream& file) {
	file << currentLocationIndx << endl;
	for (int i = 0; i < 5; i++) {
		file << worldMap[i]->isVisited() << endl;
		file << worldMap[i]->hasEnemy() << endl;
		if (worldMap[i]->hasEnemy()) {
			Enemy* enemy = worldMap[i]->getEnemy();
			file << enemy->getName() << endl;
			file << enemy->getHealth() << endl;
			file << enemy->getAttackPower() << endl;
		}
	}
}
// Helper function to load character data
void Game::loadCharacterData(ifstream& file) {
	string name, classType;
	int health, attack, defense;
	getline(file, name);
	file >> health >> attack >> defense;
	file.ignore(); // Clear newline
	getline(file, classType);
	// Create appropriate character based on saved class
	if (classType == "BerserkerWarrior") {
		player = new BerserkerWarrior(name);
	}
	else if (classType == "GuardianWarrior") {
		player = new GuardianWarrior(name);
	}
	else if (classType == "BattleMasterWarrior") {
		player = new BattleMasterWarrior(name);
	}
	else if (classType == "FireMage") {
		player = new FireMage(name);
	}
	else if (classType == "WaterMage") {
		player = new WaterMage(name);
	}
	else if (classType == "ElectricMage") {
		player = new ElectricMage(name);
	}
	else if (classType == "AssassinRogue") {
		player = new AssassinRogue(name);
	}
	else if (classType == "TricksterRogue") {
		player = new TricksterRogue(name);
	}
	else if (classType == "ThiefRogue") {
		player = new ThiefRogue(name);
	}
	// Restore stats
	player->heal(health - player->getHealth());
	player->BuffAttack(attack - player->getAttackPower());
	player->BuffDefense(defense - player->getDefensePower());
}
// Helper function to load inventory data
void Game::loadInventoryData(ifstream& file) {
	int gold, itemCount;
	file >> gold;
	inventory.addGold(gold);
	file >> itemCount;
	file.ignore(); // Clear newline
	for (int i = 0; i < itemCount; i++) {
		string name, type;
		int effect;
		getline(file, name);
		getline(file, type);
		file >> effect;
		file.ignore(); // Clear newline
		Item* newItem = nullptr;
		if (type == "Weapon") {
			newItem = new Weapon(name, "Weapon", effect);
		}
		else if (type == "Potion") {
			newItem = new HealthPotion(name, effect);
		}
		else if (type == "Armor") {
			newItem = new Armor(name, "Armor", effect);
		}
		if (newItem) {
			inventory.addItem(newItem);
		}
	}
}
// Helper function to load map data
void Game::loadMapData(ifstream& file) {
	file >> currentLocationIndx;
	for (int i = 0; i < 5; i++) {
		bool visited, hasEnemy;
		file >> visited >> hasEnemy;
		if (visited) {
			worldMap[i]->markVisited();
		}
		if (hasEnemy) {
			string enemyName;
			int health, attack;
			file.ignore(); // Clear newline
			getline(file, enemyName);
			file >> health >> attack;
			Enemy* enemy = new Enemy(enemyName);
			enemy->heal(health);
			enemy->BuffAttack(attack);
			worldMap[i]->setEnemyInstance(enemy);
		}
	}
}
Game::Game() : player(nullptr), currentLocationIndx(0) {
	// Create 5 map areas for example
	worldMap[0] = new MapArea("Forest", "Grassland");
	worldMap[1] = new MapArea("Cave", "Rocky");
	worldMap[2] = new MapArea("Swamp", "Wetland");
	worldMap[3] = new MapArea("Mountain", "Snowy");
	worldMap[4] = new MapArea("Castle", "Stone");
	// Optionally set enemies in some areas
	worldMap[1]->setEnemyInstance(new Enemy("Goblin", 50, 10));
	worldMap[3]->setEnemyInstance(new Enemy("Orc", 80, 15));
	worldMap[4]->setEnemyInstance(new Enemy("Dragon", 150, 25));
}
void Game::startGame() {
	int choice;
	cout << "\033[36mWelcome to Legends of Valors!\033[0m" << endl;
	string name;
	cout << "\033[35mEnter your character name:\033[0m ";
	cin >> name;
	// First selection: Choose main class
	cout << "\n\033[34mChoose your main class:\033[0m\n";
	cout << "\033[33m1. Warrior\n";
	cout << "2. Mage\n";
	cout << "3. Rogue\033[0m\n";
	cout << "\033[34mEnter choice:\033[0m ";
	cin >> choice;
	// Second selection: Choose subclass based on main class
	switch (choice) {
	case 1: { // Warrior subclasses
		cout << "\n\033[34mChoose your Warrior type:\033[0m\n";
		cout << "\033[33m1. Berserker Warrior (High attack, lower health)\n";
		cout << "2. Guardian Warrior (High defense, high health)\n";
		cout << "3. Battle Master Warrior (Balanced stats)\033[0m\n";
		cout << "\033[34mEnter choice: \033[0m";
		int warriorChoice;
		cin >> warriorChoice;
		switch (warriorChoice) {
		case 1: {
			player = new BerserkerWarrior(name);
			break;
		}
		case 2: {
			player = new GuardianWarrior(name);
			break;
		}
		case 3: {
			player = new BattleMasterWarrior(name);
			break;
		}
		default: {
			cout << "\033[31mInvalid choice. Defaulting to Berserker Warrior.\033[0m" << endl;
			player = new BerserkerWarrior(name);
		}
		}
		break;
	}
	case 2: { // Mage subclasses
		cout << "\n\033[34mChoose your Mage type:\033[0m\n";
		cout << "\033[33m1. Fire Mage (High damage, fire spells)\n";
		cout << "2. Water Mage (Control and healing)\n";
		cout << "3. Electric Mage (Quick attacks, lightning spells)\033[0m\n";
		cout << "\033[34mEnter choice:\033[0m ";
		int mageChoice;
		cin >> mageChoice;
		switch (mageChoice) {
		case 1: {
			player = new FireMage(name);
			break;
		}
		case 2: {
			player = new WaterMage(name);
			break;
		}
		case 3: {
			player = new ElectricMage(name);
			break;
		}
		default: {
			cout << "\033[31mInvalid choice. Defaulting to Fire Mage.\033[0m" << endl;
			player = new FireMage(name);
		}
		}
		break;
	}
	case 3: { // Rogue subclasses
		cout << "\n\033[34mChoose your Rogue type:\033[0m\n";
		cout << "\033[33m1. Assassin Rogue (High damage, stealth)\n";
		cout << "2. Trickster Rogue (Defensive, confusing)\n";
		cout << "3. Thief Rogue (Utility, balanced)\033[0m\n";
		cout << "\033[34mEnter choice:\033[0m ";
		int rogueChoice;
		cin >> rogueChoice;
		switch (rogueChoice) {
		case 1: {
			player = new AssassinRogue(name);
			break;
		}
		case 2: {
			player = new TricksterRogue(name);
			break;
		}
		case 3: {
			player = new ThiefRogue(name);
			break;
		}
		default: {
			cout << "\033[31mInvalid choice. Defaulting to Assassin Rogue.\033[0m" << endl;
			player = new AssassinRogue(name);
		}
		}
		break;
	}
	default: {
		cout << "\033[31mInvalid choice. Defaulting to Berserker Warrior.\033[0m" << endl;
		player = new BerserkerWarrior(name);
	}
	}
	// Initialize starting inventory
	initializeInventory();
	cout << "\n\033[32mGame Started! Good luck, " << name << "!\033[0m\n" << endl;
	showMainMenu();
}
void Game::showMainMenu() {
	int choice;
	do {
		cout << "\033[33m1. Explore Area\n";
		cout << "2. Move to Next Area\n";
		cout << "3. Show Inventory\n";
		cout << "4. View World Map\n";
		cout << "5. Visit Shop\n";  // New option
		cout << "6. Save Game\n";
		cout << "7. Load Game\n";
		cout << "8. Exit\033[0m\n";
		cout << "\033[34mEnter choice: \033[0m";
		cin >> choice;
		switch (choice) {
		case 1: {
			worldMap[currentLocationIndx]->exploreArea();
			Enemy* enemy = worldMap[currentLocationIndx]->triggerEncounter();
			if (enemy) {
				battle(enemy);
			}
			break;
		}
		case 2:
			moveToNextArea();
			break;
		case 3:
			inventory.showInventory();
			break;
		case 4:
			displayMap();
			break;
		case 5: {
			showShop();
			break;
		}
		case 6:
			saveGame();
			break;
		case 7:
			loadGame();
			break;
		case 8:
			cout << "\033[32mExiting game. Goodbye!\033[0m" << endl;
			break;
		default:
			cout << "\033[31mInvalid choice. Try again.\033[0m" << endl;
		}
	} while (choice != 8);
}
void Game::moveToNextArea() {
	if (currentLocationIndx < 4) {
		currentLocationIndx++;
		cout << "\033[34mMoved to new area.\033[0m" << endl;
		worldMap[currentLocationIndx]->exploreArea();
	}
	else {
		cout << "\033[35mYou are at the final area. No further areas to explore.\033[0m" << endl;
	}
}
void Game::battle(Enemy* enemy) {
	cout << "\n\033[36m=== BATTLE STARTED ===\033[0m\n";
	cout << "\033[34mYou are fighting against " << enemy->getName() << "!\033[0m\n";
	while (player->isAlive() && enemy->isAlive()) {
		// Show battle menu
		cout << "\n\033[36m=== BATTLE MENU ===\033[0m\n";
		cout << "\033[33m1. Attack\n";
		cout << "2. Use Skill\n";
		cout << "3. Use Item\n";
		cout << "4. Show Stats\n";
		cout << "5. Try to Run\033[0m\n";
		int choice;
		cout << "\033[35mEnter your choice: \033[0m";
		cin >> choice;
		switch (choice) {
		case 1: {
			player->attack(enemy);
			break;
		}
		case 2: {
			player->useSkill();
			break;
		}
		case 3: {
			// Show inventory and use item
			cout << "\n\033[36m=== YOUR INVENTORY ===\033[0m\n";
			cout << "\033[35mGold: " << inventory.getGold() << "\033[0m\n\n";
			// First, count how many items we have
			int itemCount = 0;
			for (int i = 0; i < 10; i++) {
				if (inventory.getItem(i) != nullptr) {
					itemCount++;
				}
			}
			if (itemCount == 0) {
				cout << "\033[34mYour inventory is empty!\033[0m\n";
				break;
			}
			// Show numbered list of items
			cout << "\033[34mSelect an item to use:\033[0m\n";
			cout << "\033[31m0. Go back\033[0m\n";
			for (int i = 0; i < 10; i++) {
				Item* item = inventory.getItem(i);
				if (item != nullptr) {
					cout << i + 1 << ". " << item->getName();
					if (item->getItemType() == "Potion") {
						cout << "\033[32m (Heals " << item->getEffectValue() << " HP)\033[0m";
					}
					else if (item->getItemType() == "Weapon") {
						cout << "\033[0m (Damage: " << item->getEffectValue() << ")\033[0m";
					}
					cout << "\n";
				}
			}
			int itemChoice;
			cout << "\033[35mEnter item number (0 to cancel):\033[0m ";
			cin >> itemChoice;

			if (itemChoice == 0) {
				cout << "\033[31mItem use cancelled.\033[0m\n";
				break;
			}
			if (itemChoice > 0 && itemChoice <= itemCount) {
				Item* selectedItem = inventory.getItem(itemChoice - 1);
				if (selectedItem) {
					selectedItem->useItem(player);
					// Optionally remove the item after use if it's a consumable
					if (selectedItem->getItemType() == "Potion") {
						inventory.removeItem(selectedItem->getName());
					}
				}
			}
			else {
				cout << "\033[31mInvalid item selection!\033[0m\n";
			}
			break;
		}
		case 4: {
			cout << "\n\033[36m=== YOUR STATS ===\033[0m\n";
			player->showStats();
			cout << "\n\033[36m=== ENEMY STATS ===\033[0m\n";
			enemy->getStats();
			break;
		}
		case 5: {
			// 50% chance to run
			if (rand() % 2 == 0) {
				cout << "\033[32mYou successfully ran away!\033[0m\n";
				return;
			}
			else {
				cout << "\033[31mFailed to run away!\033[0m\n";
			}
			break;
		}
		default:
			cout << "\033[31mInvalid choice!\033[0m\n";
			continue;
		}
		// Enemy's turn
		if (enemy->isAlive()) {
			cout << "\n\033[36m=== ENEMY'S TURN ===\033[0m\n";
			// 30% chance to use skill
			if (rand() % 100 < 30) {
				enemy->useSkill();
			}
			else {
				enemy->attack(player);
			}
		}
		// Show current health
		cout << "\n\033[36m=== BATTLE STATUS ===\033[0m\n";
		cout << player->getName() << " \033[35mHP: " << player->getHealth() << "\n";
		cout << enemy->getName() << " HP: " << enemy->getHealth() << "\033[0m\n";
	}
	// Battle end
	if (player->isAlive()) {
		cout << "\n\033[36m=== VICTORY! ===\033[0m\n";
		cout << "\033[31mYou defeated " << enemy->getName() << "!\033[0m\n";
		// Drop loot
		int goldDropped = enemy->dropLoot();
		inventory.addGold(goldDropped);
		// Mark area as visited
		worldMap[currentLocationIndx]->markVisited();
		// Random chance to find item
		if (rand() % 100 < 30) { // 30% chance
			Item* newItem = nullptr;
			int itemType = rand() % 2;
			if (itemType == 0) {
				newItem = new Weapon("Enemy's " + enemy->getName() + " Weapon", "Weapon", 10 + rand() % 20);
			}
			else {
				newItem = new HealthPotion("Health Potion", 20 + rand() % 30);
			}
			inventory.addItem(newItem);
			cout << "\033[34mYou found a new item: " << newItem->getName() << "!\033[0m\n";
		}
	}
	else {
		cout << "\n\033[36m=== DEFEAT ===\033[0m\n";
		cout << "\033[34mYou were defeated by " << enemy->getName() << "!\033[0m\n";
		cout << "\033[31mGame Over!\033[0m\n";
		exit(0);
	}
}
void Game::saveGame() {
	ofstream saveFile("game_save.txt");
	if (!saveFile) {
		cout << "\033[31mError: Could not create save file!\033[0m" << endl;
		return;
	}
	// Save character data
	saveFile << player->getName() << endl;
	saveFile << player->getHealth() << endl;
	saveFile << player->getAttackPower() << endl;
	saveFile << player->getDefensePower() << endl;
	// Save class type
	if (dynamic_cast<BerserkerWarrior*>(player)) {
		saveFile << "BerserkerWarrior" << endl;
	}
	else if (dynamic_cast<GuardianWarrior*>(player)) {
		saveFile << "GuardianWarrior" << endl;
	}
	else if (dynamic_cast<BattleMasterWarrior*>(player)) {
		saveFile << "BattleMasterWarrior" << endl;
	}
	else if (dynamic_cast<FireMage*>(player)) {
		saveFile << "FireMage" << endl;
	}
	else if (dynamic_cast<WaterMage*>(player)) {
		saveFile << "WaterMage" << endl;
	}
	else if (dynamic_cast<ElectricMage*>(player)) {
		saveFile << "ElectricMage" << endl;
	}
	else if (dynamic_cast<AssassinRogue*>(player)) {
		saveFile << "AssassinRogue" << endl;
	}
	else if (dynamic_cast<TricksterRogue*>(player)) {
		saveFile << "TricksterRogue" << endl;
	}
	else if (dynamic_cast<ThiefRogue*>(player)) {
		saveFile << "ThiefRogue" << endl;
	}
	// Save inventory data
	saveFile << inventory.getGold() << endl;
	int itemCount = 0;
	for (int i = 0; i < 10; i++) {
		if (inventory.getItem(i) != nullptr) itemCount++;
	}
	saveFile << itemCount << endl;
	for (int i = 0; i < 10; i++) {
		Item* item = inventory.getItem(i);
		if (item != nullptr) {
			saveFile << item->getName() << endl;
			saveFile << item->getItemType() << endl;
			saveFile << item->getEffectValue() << endl;
		}
	}
	// Save map data
	saveFile << currentLocationIndx << endl;
	for (int i = 0; i < 5; i++) {
		saveFile << worldMap[i]->isVisited() << endl;
		saveFile << worldMap[i]->hasEnemy() << endl;
		if (worldMap[i]->hasEnemy()) {
			Enemy* enemy = worldMap[i]->getEnemy();
			saveFile << enemy->getName() << endl;
			saveFile << enemy->getHealth() << endl;
			saveFile << enemy->getAttackPower() << endl;
		}
	}
	saveFile.close();
	cout << "\033[32mGame saved successfully!\033[0m" << endl;
}
void Game::loadGame() {
	ifstream saveFile("game_save.txt");
	if (!saveFile) {
		cout << "\033[31mError: No save file found!\033[0m" << endl;
		return;
	}
	// Clear current game state
	delete player;
	for (int i = 0; i < 5; i++) {
		delete worldMap[i];
	}
	// Recreate map areas
	worldMap[0] = new MapArea("Forest", "Grassland");
	worldMap[1] = new MapArea("Cave", "Rocky");
	worldMap[2] = new MapArea("Swamp", "Wetland");
	worldMap[3] = new MapArea("Mountain", "Snowy");
	worldMap[4] = new MapArea("Castle", "Stone");
	// Load character data
	string name, classType;
	int health, attack, defense;
	getline(saveFile, name);
	saveFile >> health >> attack >> defense;
	saveFile.ignore(); // Clear newline
	getline(saveFile, classType);
	// Create appropriate character based on saved class
	if (classType == "BerserkerWarrior") {
		player = new BerserkerWarrior(name);
	}
	else if (classType == "GuardianWarrior") {
		player = new GuardianWarrior(name);
	}
	else if (classType == "BattleMasterWarrior") {
		player = new BattleMasterWarrior(name);
	}
	else if (classType == "FireMage") {
		player = new FireMage(name);
	}
	else if (classType == "WaterMage") {
		player = new WaterMage(name);
	}
	else if (classType == "ElectricMage") {
		player = new ElectricMage(name);
	}
	else if (classType == "AssassinRogue") {
		player = new AssassinRogue(name);
	}
	else if (classType == "TricksterRogue") {
		player = new TricksterRogue(name);
	}
	else if (classType == "ThiefRogue") {
		player = new ThiefRogue(name);
	}
	// Restore stats
	player->heal(health - player->getHealth());
	player->BuffAttack(attack - player->getAttackPower());
	player->BuffDefense(defense - player->getDefensePower());
	// Load inventory data
	int gold, itemCount;
	saveFile >> gold;
	inventory.addGold(gold);
	saveFile >> itemCount;
	saveFile.ignore(); // Clear newline
	for (int i = 0; i < itemCount; i++) {
		string itemName, itemType;
		int effect;
		getline(saveFile, itemName);
		getline(saveFile, itemType);
		saveFile >> effect;
		saveFile.ignore(); // Clear newline
		Item* newItem = nullptr;
		if (itemType == "Weapon") {
			newItem = new Weapon(itemName, "Weapon", effect);
		}
		else if (itemType == "Potion") {
			newItem = new HealthPotion(itemName, effect);
		}
		else if (itemType == "Armor") {
			newItem = new Armor(itemName, "Armor", effect);
		}
		if (newItem) inventory.addItem(newItem);
	}
	// Load map data
	saveFile >> currentLocationIndx;
	for (int i = 0; i < 5; i++) {
		bool visited, hasEnemy;
		saveFile >> visited >> hasEnemy;
		if (visited) {
			worldMap[i]->markVisited();
		}
		if (hasEnemy) {
			string enemyName;
			int enemyHealth, enemyAttack;
			saveFile.ignore(); // Clear newline
			getline(saveFile, enemyName);
			saveFile >> enemyHealth >> enemyAttack;
			Enemy* enemy = new Enemy(enemyName);
			enemy->heal(enemyHealth);
			enemy->BuffAttack(enemyAttack);
			worldMap[i]->setEnemyInstance(enemy);
		}
	}
	saveFile.close();
	cout << "\033[32mGame loaded successfully!\033[0m" << endl;
}
void Game::showShop() {
	cout << "\n\033[36m=== SHOP ===\033[0m\n";
	cout << "\033[35mYour Gold:\033[0m " << inventory.getGold() << "\n\n";
	cout << "\033[36m=== WEAPONS ===\033[0m\n";
	cout << "\033[34m1. Steel Sword (Damage: 20, Critical Hit Chance) - 50 gold\n";
	cout << "2. Battle Axe (Damage: 25, Ignores Defense) - 75 gold\n";
	cout << "3. Shadow Dagger (Damage: 15, Double Attack) - 60 gold\n";
	cout << "4. Arcane Staff (Damage: 18, Mana Regen) - 80 gold\n";
	cout << "5. Longbow (Damage: 22, Long Range) - 70 gold\n";
	cout << "6. Flame Blade (Damage: 28, Fire Damage) - 100 gold\n";
	cout << "7. Frost Axe (Damage: 25, Freeze Effect) - 90 gold\n";
	cout << "8. Thunder Sword (Damage: 30, Lightning Damage) - 120 gold\033[0m\n\n";
	cout << "\033[36m=== POTIONS ===\033[0m\n";
	cout << "\033[33m9. Health Potion (Heals 30 HP) - 20 gold\n";
	cout << "10. Greater Health Potion (Heals 50 HP) - 35 gold\n";
	cout << "11. Mana Potion (Restores 40 Mana) - 25 gold\n";
	cout << "12. Strength Potion (+15 Attack for 3 turns) - 40 gold\n";
	cout << "13. Defense Potion (+20 Defense for 3 turns) - 40 gold\n";
	cout << "14. Rejuvenation Potion (Heals 40 HP & 30 Mana) - 50 gold\n";
	cout << "15. Berserker's Brew (+25 Attack, -10 Defense) - 45 gold\n";
	cout << "16. Guardian's Elixir (+30 Defense, -5 Attack) - 45 gold\033[0m\n\n";
	cout << "\033[36m=== MAGIC ITEMS ===\033[0m\n";
	cout << "\033[32m17. Fire Wand (40 Fire Damage) - 100 gold\n";
	cout << "18. Frost Wand (30 Frost Damage) - 90 gold\n";
	cout << "19. Lightning Rod (50 Lightning Damage) - 120 gold\n";
	cout << "20. Healing Staff (60 Healing) - 150 gold\n";
	cout << "21. Arcane Orb (45 Arcane Damage) - 110 gold\n";
	cout << "22. Nature's Staff (35 Nature Damage) - 95 gold\n";
	cout << "23. Shadow Crystal (55 Shadow Damage) - 130 gold\n";
	cout << "24. Holy Light (40 Holy Damage) - 100 gold\033[0m\n\n";
	cout << "\033[36m=== ARMOR ===\033[0m\n";
	cout << "\033[3125. Plate Armor (Defense: 25, Physical Damage Reduction) - 150 gold\n";
	cout << "26. Chain Mail (Defense: 20, Balanced Protection) - 100 gold\n";
	cout << "27. Battle Armor (Defense: 30, Rage Generation) - 200 gold\n";
	cout << "28. Mage Robe (Defense: 15, Mana Regen) - 80 gold\n";
	cout << "29. Arcane Cloak (Defense: 18, Spell Cooldown Reduction) - 120 gold\n";
	cout << "30. Elemental Mantle (Defense: 20, Elemental Damage Boost) - 150 gold\n";
	cout << "31. Leather Armor (Defense: 12, Dodge Chance) - 60 gold\n";
	cout << "32. Shadow Cloak (Defense: 15, Stealth Boost) - 90 gold\n";
	cout << "33. Assassin Garb (Defense: 18, Critical Hit Chance) - 120 gold\033[0m\n\n";
	cout << "\033[36m34. Exit Shop\033[0m\n\n";
	int choice;
	cout << "\033[35mEnter your choice:\033[0m ";
	cin >> choice;
	switch (choice) {
	case 1: {
		if (inventory.getGold() >= 50) {
			inventory.subtractGold(50);
			inventory.addItem(new Sword("Steel Sword", 20));
			cout << "\033[34mPurchased Steel Sword!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 2: {
		if (inventory.getGold() >= 75) {
			inventory.subtractGold(75);
			inventory.addItem(new Axe("Battle Axe", 25));
			cout << "\033[34mPurchased Battle Axe!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 3: {
		if (inventory.getGold() >= 60) {
			inventory.subtractGold(60);
			inventory.addItem(new Dagger("Shadow Dagger", 15));
			cout << "\033[34mPurchased Shadow Dagger!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 4: {
		if (inventory.getGold() >= 80) {
			inventory.subtractGold(80);
			inventory.addItem(new Staff("Arcane Staff", 18));
			cout << "\033[34mPurchased Arcane Staff!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 5: {
		if (inventory.getGold() >= 70) {
			inventory.subtractGold(70);
			inventory.addItem(new Bow("Longbow", 22));
			cout << "\033[34mPurchased Longbow!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 9: {
		if (inventory.getGold() >= 20) {
			inventory.subtractGold(20);
			inventory.addItem(new HealthPotion("Health Potion", 30));
			cout << "\033[34mPurchased Health Potion!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 10: {
		if (inventory.getGold() >= 35) {
			inventory.subtractGold(35);
			inventory.addItem(new HealthPotion("Greater Health Potion", 50));
			cout << "\033[34mPurchased Greater Health Potion!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 11: {
		if (inventory.getGold() >= 25) {
			inventory.subtractGold(25);
			inventory.addItem(new ManaPotion("Mana Potion", 40));
			cout << "\033[34mPurchased Mana Potion!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 12: {
		if (inventory.getGold() >= 40) {
			inventory.subtractGold(40);
			inventory.addItem(new StrengthPotion("Strength Potion", 15));
			cout << "\033[34mPurchased Strength Potion!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 13: {
		if (inventory.getGold() >= 40) {
			inventory.subtractGold(40);
			inventory.addItem(new DefensePotion("Defense Potion", 20));
			cout << "\033[34mPurchased Defense Potion!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 17: {
		if (inventory.getGold() >= 100) {
			inventory.subtractGold(100);
			inventory.addItem(new FireWand("Fire Wand"));
			cout << "\033[34mPurchased Fire Wand!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 18: {
		if (inventory.getGold() >= 90) {
			inventory.subtractGold(90);
			inventory.addItem(new FrostWand("Frost Wand"));
			cout << "\033[34mPurchased Frost Wand!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 19: {
		if (inventory.getGold() >= 120) {
			inventory.subtractGold(120);
			inventory.addItem(new LightningRod("Lightning Rod"));
			cout << "\033[34mPurchased Lightning Rod!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 20: {
		if (inventory.getGold() >= 150) {
			inventory.subtractGold(150);
			inventory.addItem(new HealingStaff("Healing Staff"));
			cout << "\033[34mPurchased Healing Staff!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 25: {
		if (inventory.getGold() >= 150) {
			inventory.subtractGold(150);
			inventory.addItem(new PlateArmor("Plate Armor"));
			cout << "\033[34mPurchased Plate Armor!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 26: {
		if (inventory.getGold() >= 100) {
			inventory.subtractGold(100);
			inventory.addItem(new ChainMail("Chain Mail"));
			cout << "\033[34mPurchased Chain Mail!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 27: {
		if (inventory.getGold() >= 200) {
			inventory.subtractGold(200);
			inventory.addItem(new BattleArmor("Battle Armor"));
			cout << "\033[34mPurchased Battle Armor!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 28: {
		if (inventory.getGold() >= 80) {
			inventory.subtractGold(80);
			inventory.addItem(new MageRobe("Mage Robe"));
			cout << "\033[34mPurchased Mage Robe!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 29: {
		if (inventory.getGold() >= 120) {
			inventory.subtractGold(120);
			inventory.addItem(new ArcaneCloak("Arcane Cloak"));
			cout << "\033[34mPurchased Arcane Cloak!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 30: {
		if (inventory.getGold() >= 150) {
			inventory.subtractGold(150);
			inventory.addItem(new ElementalMantle("Elemental Mantle"));
			cout << "\033[34mPurchased Elemental Mantle!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 31: {
		if (inventory.getGold() >= 60) {
			inventory.subtractGold(60);
			inventory.addItem(new LeatherArmor("Leather Armor"));
			cout << "\033[34mPurchased Leather Armor!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 32: {
		if (inventory.getGold() >= 90) {
			inventory.subtractGold(90);
			inventory.addItem(new ShadowCloak("Shadow Cloak"));
			cout << "\033[34mPurchased Shadow Cloak!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 33: {
		if (inventory.getGold() >= 120) {
			inventory.subtractGold(120);
			inventory.addItem(new AssassinGarb("Assassin Garb"));
			cout << "\033[34mPurchased Assassin Garb!\033[0m\n";
		}
		else {
			cout << "\033[31mNot enough gold!\033[0m\n";
		}
		break;
	}
	case 34:
		cout << "\033[36mExiting shop...\033[0m\n";
		break;
	default:
		cout << "\033[31mInvalid choice!\033[0m\n";
	}
}
void Game::initializeInventory() {
	// Add starting items based on character class
	if (dynamic_cast<Warrior*>(player)) {
		// Warrior starting items
		inventory.addItem(new HealthPotion("Warrior's Health Potion", 40));  // Stronger health potion
		inventory.addItem(new Sword("Basic Sword", 15));  // Basic warrior weapon
		inventory.addItem(new StrengthPotion("Warrior's Strength Potion", 10));  // Attack boost
	}
	else if (dynamic_cast<Mage*>(player)) {
		// Mage starting items
		inventory.addItem(new ManaPotion("Mage's Mana Potion", 50));  // Mana restoration
		inventory.addItem(new Staff("Basic Staff", 12));  // Basic magic staff
		inventory.addItem(new HealthPotion("Mage's Health Potion", 25));  // Weaker health potion
	}
	else if (dynamic_cast<Rogue*>(player)) {
		// Rogue starting items
		inventory.addItem(new HealthPotion("Rogue's Health Potion", 30));  // Medium health potion
		inventory.addItem(new Dagger("Basic Dagger", 10));  // Basic dagger
		inventory.addItem(new DefensePotion("Rogue's Defense Potion", 8));  // Defense boost
	}
	// Give some starting gold
	inventory.addGold(50);
	// Print confirmation message
	cout << "\n\033[36m=== Starting Inventory ===\033[0m\n";
	cout << "\033[32mYou received:\033[0m\n";
	// Show items based on class
	if (dynamic_cast<Warrior*>(player)) {
		cout << "\033[33m- 1 Warrior's Health Potion (Heals 40 HP)\n";
		cout << "- 1 Basic Sword (Damage: 15)\n";
		cout << "- 1 Warrior's Strength Potion (+10 Attack for 3 turns)\033[0m\n";
	}
	else if (dynamic_cast<Mage*>(player)) {
		cout << "\033[33m- 1 Mage's Mana Potion (Restores 50 Mana)\n";
		cout << "- 1 Basic Staff (Damage: 12, Increases mana regeneration)\n";
		cout << "- 1 Mage's Health Potion (Heals 25 HP)\033[0m\n";
	}
	else if (dynamic_cast<Rogue*>(player)) {
		cout << "\033[33m- 1 Rogue's Health Potion (Heals 30 HP)\n";
		cout << "- 1 Basic Dagger (Damage: 10, Quick attack)\n";
		cout << "- 1 Rogue's Defense Potion (+8 Defense for 3 turns)\033[0m\n";
	}
	cout << "\033[34m- 50 gold\033[0m\n\n";
}
void Game::displayMap() {
	cout << "\n\033[36m=== WORLD MAP ===\033[0m\n";
	cout << "\033[35mLegend:\033[0m\n";
	cout << "\033[33m🔴 - Current Location\n";
	cout << "🌾 - Forest/Grassland\n";
	cout << "🪨 - Cave/Rocky\n";
	cout << "🪵 - Swamp/Wetland\n";
	cout << "❄ - Mountain/Snowy\n";
	cout << "🏰 - Castle/Stone\n";
	cout << "👹 - Enemy Present\n";
	cout << "✔ - Visited\n";
	cout << "❌ - Not Visited\033[0m\n\n";
	// Draw the map with connections
	for (int i = 0; i < 5; i++) {
		// Get area information
		string icon;
		string terrain = worldMap[i]->getTerrain();
		string areaName = worldMap[i]->getName();
		bool isCurrentLocation = (i == currentLocationIndx);
		bool isVisited = worldMap[i]->isVisited();
		bool hasEnemy = worldMap[i]->hasEnemy();
		// Set icon based on terrain
		if (terrain == "Grassland") {
			icon = "🌾";
		}
		else if (terrain == "Rocky") {
			icon = "🪨";
		}
		else if (terrain == "Wetland") {
			icon = "🪵";
		}
		else if (terrain == "Snowy") {
			icon = "❄";
		}
		else if (terrain == "Stone") {
			icon = "🏰";
		}
		else {
			icon = "❓";
		}
		// Draw the top border of the box
		cout << "\033[36m================================\033[0m\n";
		// Draw the area name line
		cout << "| " << (isCurrentLocation ? "🔴 " : "   ") << icon << " " << areaName;
		// Add padding to make the box rectangular
		int padding = 25 - areaName.length();
		for (int j = 0; j < padding; j++) cout << " ";
		cout << "|\n";
		// Draw the status line
		cout << "\033[34m| Status:\033[0m " << (isVisited ? "\033[32m✔ Visited\033[0m" : "\033[31m❌ Not Visited\033[0m");
		if (hasEnemy) {
			cout << " | 👹 " << worldMap[i]->getEnemy()->getName();
		}
		// Add padding for the status line
		padding = 25 - (isVisited ? 10 : 12) - (hasEnemy ? worldMap[i]->getEnemy()->getName().length() + 4 : 0);
		for (int j = 0; j < padding; j++) cout << " ";
		cout << "|\n";
		// Draw the bottom border of the box
		cout << "\033[36m================================\033[0m\n";
		// Draw connection lines if not the last area
		if (i < 4) {
			cout << "              |\n";
			cout << "              v\n";
		}
	}
}