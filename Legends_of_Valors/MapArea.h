#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <fstream>
#include"Enemy.h"
using namespace std;
class MapArea {
private:
	bool visited;
	string areaName;
	string terrainType;
	bool HasEnemy;
	Enemy* enemy;
public:
	Enemy* getEnemy();
	void markVisited();
	bool isVisited() const;
	bool hasEnemy();
	string getName();
	MapArea(string n, string t);
	void exploreArea();
	Enemy* triggerEncounter();
	void setEnemy(bool status);
	void setEnemyInstance(Enemy* newEnemy);
	~MapArea();
	string getTerrain();
};
