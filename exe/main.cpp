#include <iostream>

#include "platform.h"
#include "RendereringSystem.h"
#include "Scene.h"
#include "EditorGUI.h"

Platform gPlatform;
RendereringSystem gRenderer;
Scene gScene;
EditorGUI gEditorGUI;

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	gPlatform.startUp();
	gRenderer.startUp();
	gEditorGUI.startUp();

	if (gScene.open("scene1.db")) {
		gScene.Load();
	}
	
	std::cout << " this is the game \n";

	while (gPlatform.isRunning)
	{
		gPlatform.runLoop();
		gRenderer.runLoop();
		gEditorGUI.runLoop();
	}

	gRenderer.startUp();
	gPlatform.shutDown();
}
