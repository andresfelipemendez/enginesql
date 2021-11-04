#pragma once
#include <vector>
#include <string>

struct Renderer;

extern const char* glsl_version;

typedef void* SDL_GLContext;
extern SDL_GLContext gl_context;

class RendereringSystem
{
public:
	std::vector<Renderer> renderers;
	RendereringSystem();
	~RendereringSystem();
	void startUp();
	void runLoop();
	void shutDown();
	void addEmptyRenderer(std::string go);
};

