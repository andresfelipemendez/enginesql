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
	void shutDown();
	std::string getValue();
	int ret = 0;
	static std::vector<GameObject> gameObjects;
	void AddRenderingComponent(std::string gameObject, std::string shader, std::string model);
private:
	sqlite3* db = nullptr;
	std::string sceneName;
};
