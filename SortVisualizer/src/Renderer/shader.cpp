#include "renderer.h"

#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

class ShaderCompileError : public std::exception {
public:
	const std::string infoLog;

	ShaderCompileError(const char* log)
		: infoLog(log)
	{}

	const char* what() const override {
		return "Failed to compile shader.";
	}
};

std::string openShader(const std::string &path) {
	std::ifstream file;
	file.open(path);

	if (!file)
		throw new std::exception("Unable to load shader.");

	std::stringstream ss;
	ss << file.rdbuf();

	return ss.str();
}

void compileShader(unsigned int shaderId) {
	glCompileShader(shaderId);

	int compiled;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);

	if (compiled != GL_TRUE) {
		int logLength;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);

		char* log = (char*)alloca(sizeof(char) * logLength);
		glGetShaderInfoLog(shaderId, logLength, &logLength, log);

		throw new ShaderCompileError(log);
	}
}

void Renderer::initShaders() {
	unsigned int 
		vertexShader = glCreateShader(GL_VERTEX_SHADER),
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::string vertexSource = openShader("shader_src/vertex.glsl"),
		fragSource = openShader("shader_src/fragment.glsl");

	const char* c_VS = vertexSource.c_str();
	const char* c_FS = fragSource.c_str();

	glShaderSource(vertexShader, 1, &c_VS, NULL);
	compileShader(vertexShader);

	glShaderSource(fragmentShader, 1, &c_FS, NULL);
	compileShader(fragmentShader);

	glAttachShader(m_ShaderProgram, vertexShader);
	glAttachShader(m_ShaderProgram, fragmentShader);
	glLinkProgram(m_ShaderProgram);

	int programLinked;
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &programLinked);

	if (programLinked != GL_TRUE) {
		int logLength;
		glGetProgramiv(m_ShaderProgram, GL_INFO_LOG_LENGTH, &logLength);

		char* log = (char*)alloca(sizeof(char) * logLength);
		glGetProgramInfoLog(m_ShaderProgram, logLength, &logLength, log);

		throw new ShaderCompileError(log);
	}

	// cleanup
	glDetachShader(m_ShaderProgram, vertexShader);
	glDetachShader(m_ShaderProgram, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}