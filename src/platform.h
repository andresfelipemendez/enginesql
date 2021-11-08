#pragma once
#include <filesystem>

struct SDL_Window;
extern SDL_Window* window;

class Platform
{
public:
	void startUp();
	void runLoop();
	void shutDown();
	std::filesystem::directory_iterator GetListOf3DModels();
	bool isRunning = false;
	std::filesystem::directory_iterator getShaders();
};