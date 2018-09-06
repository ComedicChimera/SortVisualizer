#pragma once

#include <vector>
#include <GLFW/glfw3.h>
#include <GL/glew.h>

struct Bar {
	float x, height;
};

class Renderer {
	std::vector<Bar> m_Bars;
	float m_BarWidth;

	GLFWwindow *m_Window;

public:
	Renderer(unsigned int arrLen);
	~Renderer();

	void addBar(Bar bar);
	void draw();
	void clear();

// opengl stuff
private:
	unsigned int m_ShaderProgram,
		m_VAO,
		m_IBO;

	void initShaders();
	void initGLData();
};