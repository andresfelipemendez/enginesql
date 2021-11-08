#include <iostream>

#include "Globals.h"

#include "platform.h"
#include "RendereringSystem.h"
#include "Scene.h"
#include "EditorGUI.h"

#include<filesystem>

Platform gPlatform;
RendereringSystem gRenderer;
Scene gScene;
EditorGUI gEditorGUI;

// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	gPlatform.startUp();
	gRenderer.startUp();
	gEditorGUI.startUp();

	std::cout << std::filesystem::current_path();

	if (gScene.open("../../../../db/scene1.db")) {
		gScene.Load();
	}
	
	std::cout << " this is the game \n";

	while (gPlatform.isRunning)
	{
		gPlatform.runLoop();
		gRenderer.runLoop();
		gEditorGUI.runLoop();
	}

	gScene.shutDown();
	gRenderer.shutDown();
	gPlatform.shutDown();
}
