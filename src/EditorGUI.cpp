#include "EditorGUI.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "SDL_opengl.h"

#include "Platform.h"
#include "RendereringSystem.h"

#include "Globals.h"
#include "Scene.h"

#include <SDL.h>
#include <SDL_opengl.h>

#include <filesystem>
#include "components/Renderer.h"

EditorGUI::EditorGUI()
{
}

EditorGUI::~EditorGUI()
{
}

void EditorGUI::startUp()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	/*io.DisplaySize.x = 600;
	io.DisplaySize.y = 480;*/

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL3_Init(glsl_version);

}

void EditorGUI::runLoop()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		
		auto go = DrawGOSelection();
		auto shader = DrawDropDownListOfShader();
		auto model = DrawDropDownListOfModels();

		for (auto& renderer : gRenderer.renderers)
		{
			ImGui::Text("%s, %s, %s", 
				renderer.GOID.c_str(), renderer.shader.c_str()
				, renderer.model.c_str());
		}

		if (ImGui::Button("add renderer")) {
			gRenderer.addEmptyRenderer(go, shader, model);
			gScene.AddRenderingComponent(go, shader, model);
		}

		ImGui::End();
	}

	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
	
}

std::string EditorGUI::DrawGOSelection()
{
	static std::string current_item  = "null";
	if (ImGui::BeginCombo("##combo", current_item.c_str())) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < gScene.gameObjects.size(); n++)
		{
			bool is_selected = (current_item == gScene.gameObjects[n].Name); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(gScene.gameObjects[n].Name.c_str(), is_selected))
			{
				current_item = gScene.gameObjects[n].Name;
				if (is_selected)
				{
					ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
				}
			}
		}
		ImGui::EndCombo();
	}
	return current_item;
}

std::string EditorGUI::DrawDropDownListOfShader()
{
	static std::string current_item = "null";
	if (ImGui::BeginCombo("##shader", current_item.c_str())) 
	{
		for(const auto&	shader : gPlatform.getShaders())
		{ 
			auto shaderFileName = shader.path().filename().string();
			bool is_selected = (current_item == shaderFileName);
			if (ImGui::Selectable(shaderFileName.c_str(), is_selected))
			{
				current_item = shaderFileName;
				if (is_selected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
		}
		ImGui::EndCombo();
	}
	return current_item;
}

std::string EditorGUI::DrawDropDownListOfModels()
{
	static std::string current_item = "null";
	if (ImGui::BeginCombo("##model", current_item.c_str()))
	{
		for (const auto& shader : gPlatform.GetListOf3DModels())
		{
			auto shaderFileName = shader.path().filename().string();
			bool is_selected = (current_item == shaderFileName);
			if (ImGui::Selectable(shaderFileName.c_str(), is_selected))
			{
				current_item = shaderFileName;
				if (is_selected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
		}
		ImGui::EndCombo();
	}
	return current_item;
}


void EditorGUI::shutDown()
{
}
