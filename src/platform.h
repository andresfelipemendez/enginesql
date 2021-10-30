#pragma once

struct SDL_Window;
extern SDL_Window* window;

class Platform
{
public:
	void startUp();
	void runLoop();
	void shutDown();
	bool isRunning = false;
};