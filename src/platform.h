#pragma once

struct SDL_Window;

class Platform
{
public:
	SDL_Window* window = nullptr;
	void startUp();
	void runLoop();
	void shutDown();
	bool isRunning;
};