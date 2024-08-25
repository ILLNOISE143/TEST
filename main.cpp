#include <iostream>
#include <sstream>
#include <iomanip>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <Vertexes.h>
#include <Extra.h>

#define ww 800
#define wh 600

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void print_resolutions(GLFWmonitor* monitor);

GLFWmonitor* monitor;

int main() {
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW!" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(ww, wh, "Cortex (C) - By ERA", NULL, NULL);
	if (!window) {
		std::cout << "Failed to create GLFW window!" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, ww, wh);
	MakeAllVertexOperations();
	MakeAllShaderOperations();
	MakeAllTextureOperations();

	float angle = 20.0f;

	glEnable(GL_DEPTH_TEST);

	double previousTime = glfwGetTime();
	int frameCount = 0;
	initImGui(window);

	while (!glfwWindowShouldClose(window))
	{
		angle += 0.5f * rotationSpeed;

		glClearColor(0.6f, 0.7f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		processInput(window);
		SetShaderFloat("number", glm::sin(glfwGetTime())); // clamp(glm::sin(glfwGetTime()), 0.5f, 1.0f)

		glm::mat4 projection = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);

		int liveWW, liveWH;

		glfwGetWindowSize(window, &liveWW, &liveWH);

		DrawEverything();
		projection = glm::perspective(glm::radians(90.0f + fovSpeed), (float)liveWW / (float)liveWH, 0.01f, 1000.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));

		SetShaderMat4("uProjection", projection);
		SetShaderMat4("uView", view);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.3f, 0.0f));
		SetShaderMat4("uModel", model);

		glDrawArrays(GL_TRIANGLES, 0, 36);

		showFPSImGui();
		glfwPollEvents();
		glfwSwapBuffers(window);
		glFlush();
	}

	shutdownImGui();
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);

		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}


	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		glfwSetWindowMonitor(window, NULL, 50, 50, ww, wh, 165);
	}
}

void print_resolutions(GLFWmonitor* monitor) {
	int count;
	const GLFWvidmode* modes = glfwGetVideoModes(monitor, &count);

	for (int i = 0; i < count; i++) {
		printf("Resolution %d: %dx%d @ %dHz\n", i, modes[i].width, modes[i].height, modes[i].refreshRate);
	}
}
