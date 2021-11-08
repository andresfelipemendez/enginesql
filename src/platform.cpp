#include "platform.h"
#include <iostream>

#include "SDL.h"
#include "SDL_opengl.h"

#include <filesystem>

SDL_Window* window = nullptr;

void Platform::startUp() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialize the SDL2 library\n";
	}

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	window = SDL_CreateWindow("SDL2 Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		680, 480,
		window_flags);

	if (!window)
	{
		std::cout << "Failed to create window\n";
	}

	SDL_Surface* window_surface = SDL_GetWindowSurface(window);

	if (!window_surface)
	{
		std::cout << "Failed to get the surface from the window\n";
	}

	isRunning = true;
}

std::filesystem::directory_iterator Platform::GetListOf3DModels() {
	std::string path = "assets/models";
	return std::filesystem::directory_iterator(path);
}

std::filesystem::directory_iterator Platform::getShaders()
{
	std::string path = "assets/shaders";
	return std::filesystem::directory_iterator(path);
}

void Platform::runLoop() {
	SDL_Event e;
	while (SDL_PollEvent(&e) > 0)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}

void Platform::shutDown() {
}