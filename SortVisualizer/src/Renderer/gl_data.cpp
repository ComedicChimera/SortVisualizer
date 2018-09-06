#include "renderer.h"

void Renderer::initGLData() {
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);

	float indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6, &indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 2 * sizeof(float), GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3 * sizeof(float), GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)2);
	glEnableVertexAttribArray(1);
}