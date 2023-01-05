#include "Rogue3d.h"
#ifndef Rogue3d_GLObjects_H
#define Rogue3d_GLObjects_H
class Texture
{
public:
	Texture(std::string  textureLocation);
	~Texture();
	void bind(unsigned int index);
	void unBind();
	void configureDefaultTextureParameter();

private:
	unsigned int textureID;
	unsigned int assignedIndex;
};
class ShaderProgram
{
public:
	ShaderProgram(std::string fragmentShaderLocation, std::string vertexShaderLocation);
	~ShaderProgram();

	bool reloadProgram(std::string fragmentShaderLocation, std::string vertexShaderLocation);
	void bind();
	void unBind();
	void setUniform(std::string name, float value); // 1 float
	void setUniform(std::string name, float value, float value2); // 2 float vector
	void setUniform(std::string name, float value, float value2, float value3); // 3 float vector
	void setUniform(std::string name, float value, float value2, float value3, float value4); // 4 float vector
	void setUniform(std::string name, int value); // 1 float
	void setUniform(std::string name, int value, int value2); // 2 float vector
	void setUniform(std::string name, int value, int value2, int value3); // 3 float vector
	void setUniform(std::string name, int value, int value2, int value3, int value4); // 4 float vector
	void setUniform(std::string name, glm::mat4 value); // 4 float vector
private:
	unsigned int shaderProgramID;

};



class VBO
{
public:
	VBO();
	~VBO();
	void bind();
	void unBind();

	void bufferData(const void* data, unsigned int dataSize, unsigned int usage);


private:
	unsigned int vertexBufferObjectID;
};

class VAO
{
public:
	VAO();
	~VAO();
	void bind();
	void unBind();
	void configureVertexAttribPointer(unsigned int index, unsigned int amountOfValues, unsigned int openglValueType, unsigned int openglNormailzed, unsigned int stride, const void* startingLocation);
	void enableVertexAttribPointer(unsigned int index);
	void disableVertexAttribPointer(unsigned int index);
private:
	unsigned int vertexArrayObjectID;
};

class EBO
{
public:
	EBO();
	~EBO();
	void bind();
	void unBind();

	void bufferData(const void* data, unsigned int dataSize, unsigned int usage);

private:
	unsigned int elementBufferObjectID;
};

#endif Rogue3d_GLObjects_H


