#pragma once

extern const char* glsl_version;

typedef void* SDL_GLContext;
extern SDL_GLContext gl_context;

class RendereringSystem
{
public:
	RendereringSystem();
	~RendereringSystem();
	void startUp();
	void runLoop();
	void shutDown();
};

