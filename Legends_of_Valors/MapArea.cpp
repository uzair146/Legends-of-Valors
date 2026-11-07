#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"MapArea.h"
using namespace std;
Enemy* MapArea::getEnemy() {
	return enemy;
}
void MapArea::markVisited() {
	visited = true;
}
bool MapArea::isVisited() const {
	return visited;
}
bool MapArea::hasEnemy() {
	return HasEnemy;
}
string MapArea::getName() {
	return areaName;
}
MapArea::MapArea(string n, string t) : areaName(n), terrainType(t), enemy(nullptr), visited(false) {
	HasEnemy = false;
}
void MapArea::exploreArea() {
	cout << "\033[35mYou are in the " << areaName << ".\033[0m" << endl;
	cout << "\033[34mTerrain type: \033[0m" << terrainType << endl;
	cout << (hasEnemy() ? "\033[31mWarning: An enemy is lurking in this area!\033[0m" : "\033[32mThis area is safe for now.\033[0m") << endl;
	markVisited();  // Add this line to mark the area as visited when explored
}
Enemy* MapArea::triggerEncounter() {
	if (HasEnemy) {
		cout << "\033[31mA wild enemy has appeared!\033[0m" << endl;
		if (!enemy)
			enemy = new Enemy("Enemy Name");
		return enemy;
	}
	cout << "\033[34mNo enemies in this area.\033[0m" << endl;
	return nullptr;
}
void MapArea::setEnemy(bool status) {
	HasEnemy = status;
}
void MapArea::setEnemyInstance(Enemy* newEnemy) {
	enemy = newEnemy;
	HasEnemy = (newEnemy != nullptr);
}
MapArea::~MapArea() {
	delete enemy;
}
string MapArea::getTerrain() {
	return terrainType;
}