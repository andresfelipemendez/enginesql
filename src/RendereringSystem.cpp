#include "RendereringSystem.h"
#include "Platform.h"

#include <SDL.h>
#include <SDL_opengl.h>

#include "components/Renderer.h"

const char* glsl_version = "#version 130";
SDL_GLContext gl_context = nullptr;

RendereringSystem::RendereringSystem()
{
}

RendereringSystem::~RendereringSystem()
{
}


void RendereringSystem::startUp()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1); // Enable vsync
}

void RendereringSystem::runLoop()
{
	glViewport(0, 0, 680, 480);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	
	//SDL_GL_SwapWindow(window);
}

void RendereringSystem::shutDown()
{

}

void RendereringSystem::addEmptyRenderer(std::string go, std::string shader, std::string model)
{
	Renderer r;
	r.GOID = go;
	r.shader = shader;
	r.model = model;
	renderers.push_back(r);
}
