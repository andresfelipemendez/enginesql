#pragma once
#include <string>

class EditorGUI 
{
	bool my_tool_active;
	bool show_demo_window = true;
	bool show_another_window = false;
	float clear_color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };

public:
	EditorGUI();
	~EditorGUI();
	void startUp();
	void runLoop();
	std::string DrawGOSelection();
	std::string DrawShaderSelection();
	void shutDown();
};