#include "sdk.h"

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error %d: %s\n", error, description);
}


int main(int, char**)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return 1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "ITGS-IA-CHAREKIAN", NULL, NULL);
	glfwMakeContextCurrent(window);
	gl3wInit();

	ImGui_ImplGlfwGL3_Init(window, true);


	bool info_window = true;
	bool show_test_window = false;
	bool show_another_window = false;
	ImVec4 color = ImColor(0, 128, 128);

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		ImGui_ImplGlfwGL3_NewFrame();

		if (info_window)
		{
			ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_FirstUseEver);
			ImGui::Begin("Test", &info_window);
			ImGui::OpenPopup("Enter distance ran please");
			ImGui::InputFloat("Input distance", &apace->distance, 0.1f, 1.0f);
			ImGui::InputFloat("Input time", &apace->ttime, 0.1f, 1.0f);
			ImGui::InputFloat("Input speed", &apace->speed, 0.1f, 1.0f);
			ImGui::InputFloat("Input gradient", &apace->gradient, 0.1f, 1.0f);
			ImGui::Text("Average pace %f", apace->calcavgpace(apace->distance, apace->ttime));
			ImGui::Text("GAP pace %f", apace->calcgap(apace->distance, apace->speed, apace->gradient));
			ImGui::End();
		}

		
		int w, h;
		glfwGetFramebufferSize(window, &w, &h);
		glViewport(0, 0, w, h);
		glClearColor(color.x, color.y, color.z, color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	glfwTerminate();

	return 0;
}