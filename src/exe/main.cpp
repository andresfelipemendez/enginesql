#include <iostream>

#include "platform.h"
#include "RendereringSystem.h"
#include "Scene.h"

Platform gPlatform;
RendereringSystem gRenderer;
Scene gScene;

// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	gPlatform.startUp();
	gRenderer.startUp();

	if (gScene.open("scene1.db")) {
		gScene.Load();
	}
	
	std::cout << " this is the game \n";

	while (gPlatform.isRunning)
	{
		gPlatform.runLoop();
		gRenderer.startUp();
	}

	gRenderer.startUp();
	gPlatform.shutDown();
}
