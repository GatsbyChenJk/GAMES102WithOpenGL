#pragma once
#ifndef IMGUIAPP_H
#define IMGUIAPP_H
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>


class ImGuiApp
{
public:
	struct ImGuiIODeleter
	{
		void operator()(ImGuiIO* io) const
		{
			ImGui::DestroyContext();
		}
	};

	struct ImGuiAppDeleter
	{
		void operator() (ImGuiApp* imguiApp) const
		{
			delete imguiApp;
		}
	};

public:
	std::unique_ptr<ImGuiIO,ImGuiIODeleter> GL_ImGuiIO;
	std::string GL_ImGui_Name;
	std::string GL_Shader_Version;

public:
	ImGuiApp() = default;
	~ImGuiApp();
	ImGuiApp(const std::string& GuiName,const std::string& ShaderVersion);
	bool Init(GLFWwindow* windowPtr);
	void SetUIDetail(glm::mat4& projection);
	void RenderOnWindow(GLFWwindow* windowPtr);
	void Destroy();
	static std::unique_ptr<ImGuiApp, ImGuiAppDeleter> createImGuiPtr(const char* GuiName, const char* ShaderVersion)
	{
		return std::unique_ptr<ImGuiApp, ImGuiAppDeleter>(new ImGuiApp(GuiName, ShaderVersion));
	}
};

#endif // !IMGUIAPP_H