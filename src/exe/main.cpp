#include <iostream>

#include "platform.h"
#include "renderer.h"
#include "scene.h"

Platform gPlatform;
Renderer gRenderer;

scene gScene;

//
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	gPlatform.startUp();
	gRenderer.startUp();

	gScene.open("scene1.db");
	auto row = gScene.getValue();
	std::cout << " this is the game \n";

	while (gPlatform.isRunning)
	{
		gPlatform.runLoop();
		gRenderer.startUp();
	}

	gRenderer.startUp();
	gPlatform.shutDown();
}
