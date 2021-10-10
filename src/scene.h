#pragma once 
#include <vector>
#include <string>
#include "GameObject.h"

struct sqlite3;

struct scene
{
	scene();
	~scene();
	bool open(std::string name);
	std::string getValue();
	int ret = 0;
	static std::vector<GameObject> gameObjects;
private:
	sqlite3* db = nullptr;
	//int callback(void* data, int argc, char** argv, char** azColName);
};
