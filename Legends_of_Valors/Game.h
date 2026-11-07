#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"character.h"
#include"MapArea.h"
#include "Inventory .h"
using namespace std;
class Game {
private:
	Character* player;
	Inventory inventory;
	MapArea* worldMap[5]; // You can expand this size if needed
	int currentLocationIndx;
	// Helper function to save character data
	void saveCharacterData(ofstream& file);
	void saveInventoryData(ofstream& file);
	void saveMapData(ofstream& file);
	void loadCharacterData(ifstream& file);
	void loadInventoryData(ifstream& file);
	void loadMapData(ifstream& file);
public:
	Game();
	void startGame();
	void showMainMenu();
	void moveToNextArea();
	void battle(Enemy* enemy);
	void saveGame();
	void loadGame();
	void showShop();
	void initializeInventory();
	void displayMap();
};

