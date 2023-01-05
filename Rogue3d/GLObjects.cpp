
#include "Rogue3d.h"

ShaderProgram::ShaderProgram(std::string fragmentShaderLocation, std::string vertexShaderLocation)
{
	this->reloadProgram(fragmentShaderLocation, vertexShaderLocation);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(this->shaderProgramID);
}

void ShaderProgram::bind()
{
	glUseProgram(this->shaderProgramID);
}

void ShaderProgram::unBind()
{
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string name, float value)
{
	glUniform1f(glGetUniformLocation(this->shaderProgramID, name.c_str()), value);
}

void ShaderProgram::setUniform(std::string name, float value, float value2)
{
	glUniform2f(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2);
}

void ShaderProgram::setUniform(std::string name, float value, float value2, float value3)
{
	glUniform3f(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2, value3);
}
void ShaderProgram::setUniform(std::string name, float value, float value2, float value3, float value4)
{
	glUniform4f(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2, value3, value4);
}

void ShaderProgram::setUniform(std::string name, int value)
{
	glUniform1i(glGetUniformLocation(this->shaderProgramID, name.c_str()), value);
}

void ShaderProgram::setUniform(std::string name, int value, int value2)
{
	glUniform2i(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2);
}

void ShaderProgram::setUniform(std::string name, int value, int value2, int value3)
{
	glUniform3i(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2, value3);
}

void ShaderProgram::setUniform(std::string name, int value, int value2, int value3, int value4)
{
	glUniform4i(glGetUniformLocation(this->shaderProgramID, name.c_str()), value, value2, value3, value4);
}

void ShaderProgram::setUniform(std::string name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgramID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

bool ShaderProgram::reloadProgram(std::string fragmentShaderLocation, std::string vertexShaderLocation)
{
	std::ifstream fileStream;
	fileStream.open(vertexShaderLocation);

	std::string vertexShaderSource(
		(std::istreambuf_iterator<char>(fileStream)),
		(std::istreambuf_iterator<char>()));

	fileStream.close();
	fileStream.open(fragmentShaderLocation);

	std::string fragmentShaderSource(
		(std::istreambuf_iterator<char>(fileStream)),
		(std::istreambuf_iterator<char>()));

	fileStream.close();

	int  success;
	char infoLog[512];

	const char* vertexShaderCSource = vertexShaderSource.c_str();
	const char* fragmentShaderCSource = fragmentShaderSource.c_str();

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderCSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << " Vertex Shader Compilation Failed " << infoLog << std::endl;
		glDeleteShader(vertexShader);
		return false;
	}


	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderCSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << " Fragment Shader Compilation Failed " << infoLog << std::endl;
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		return false;
	}

	this->shaderProgramID = glCreateProgram();

	glAttachShader(this->shaderProgramID, vertexShader);
	glAttachShader(this->shaderProgramID, fragmentShader);
	glLinkProgram(this->shaderProgramID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return true;
}

VBO::VBO()
{
	glGenBuffers(1, &(this->vertexBufferObjectID));
	
}

VBO::~VBO()
{
	glDeleteBuffers(1, &this->vertexBufferObjectID);
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObjectID);
}

void VBO::unBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bufferData(const void* data, unsigned int dataSize, unsigned int usage)
{
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
}



void VAO::configureVertexAttribPointer(unsigned int index, unsigned int amountOfValues, unsigned int openglValueType, unsigned int openglNormailzed, unsigned int stride, const void* startingLocation)
{
	glVertexAttribPointer(index, amountOfValues, openglValueType, openglNormailzed, stride, startingLocation);
	
}

void VAO::enableVertexAttribPointer(unsigned int index)
{
	glEnableVertexAttribArray(index);
}

void VAO::disableVertexAttribPointer(unsigned int index)
{
	glDisableVertexAttribArray(index);
}

VAO::VAO()
{

	glGenVertexArrays(1, &(this->vertexArrayObjectID));
	
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &(this->vertexArrayObjectID));
}

void VAO::bind()
{
	glBindVertexArray(this->vertexArrayObjectID);
}

void VAO::unBind()
{
	glBindVertexArray(0);
}

EBO::EBO()
{
	glGenBuffers(1, &(this->elementBufferObjectID));
}

EBO::~EBO()
{
	glDeleteBuffers(1, &(this->elementBufferObjectID));
}

void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufferObjectID);
}

void EBO::unBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::bufferData(const void* data, unsigned int dataSize, unsigned int usage)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage);
}

Texture::Texture(std::string textureLocation)
{
	this->assignedIndex = 0;
	glGenTextures(1, &(this->textureID));
	this->bind(0);int x, y, n;
	unsigned char* data = stbi_load(textureLocation.c_str(), &x, &y, &n, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	this->unBind();
}

Texture::~Texture()
{
	glDeleteTextures(1, &(this->textureID));
}

void Texture::bind(unsigned int index)
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
	this->assignedIndex = index;
}

void Texture::unBind()
{
	glActiveTexture(GL_TEXTURE0 + this->assignedIndex);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::configureDefaultTextureParameter()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}