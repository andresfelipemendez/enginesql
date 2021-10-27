#pragma once 
#include <vector>
#include <string>
#include "GameObject.h"

struct sqlite3;

struct Scene
{
	Scene();
	~Scene();
	bool open(std::string name);
	void Load();
	std::string getValue();
	int ret = 0;
	static std::vector<GameObject> gameObjects;

private:
	sqlite3* db = nullptr;
	std::string sceneName;
};
