#include "renderer.h"

#include <iostream>
#include <stdexcept>

Renderer::Renderer(unsigned int bars) {
	if (!glfwInit()) 
		throw new std::exception("Failed to initialize GLFW.");

	m_Window = glfwCreateWindow(1280, 720, "Sort Visualizer", NULL, NULL);

	if (!m_Window)
		throw new std::exception("Failed to create window.");

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
		throw new std::exception("Failed to initialize GLEW.");

	m_BarWidth = 1280 / bars;

	initShaders();

	initGLData();
}

Renderer::~Renderer() {
	glDeleteBuffers(1, &m_IBO);
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteProgram(m_ShaderProgram);

	glfwDestroyWindow(m_Window);
	glfwTerminate();
}