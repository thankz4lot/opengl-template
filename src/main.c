#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* WINDOW_TITLE = "OpenGL Example";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char** argv) {
	GLFWwindow* window;
	if(!glfwInit()) return EXIT_FAILURE;
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	// Write your opengl code here
	//
	uint32_t vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	uint32_t vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vao);
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	uint32_t ibo = 0;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	uint32_t indices[] = {
		0, 1, 2, 2, 3, 0
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		// Draw in here
		glDrawElements(GL_TRIANGLES, 0, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
	}
	return EXIT_SUCCESS;
}
