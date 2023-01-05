#include "Rogue3d.h"

Rogue3d::Core::Transform::Transform()
{

	this->position = glm::vec3(0.0f);
	this->rotation = glm::vec3(0.0f);
	this->scale = glm::vec3(1.0f);
	this->updateMatrix();
}

Rogue3d::Core::Transform::~Transform()
{
}

void Rogue3d::Core::Transform::updateMatrix()
{
	this->matrix = glm::mat4(1.0f);

	this->matrix = glm::translate(this->matrix, this->position);

	this->matrix = glm::rotate(this->matrix, this->rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	this->matrix = glm::rotate(this->matrix, this->rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	this->matrix = glm::rotate(this->matrix, this->rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	this->matrix = glm::scale(this->matrix, this->scale);

	this->changed = false;
}

glm::mat4 Rogue3d::Core::Transform::getMatrix()
{
	if (this->changed) 
	{
		this->updateMatrix();
	}
	return this->matrix;
}

void Rogue3d::Core::Transform::setPosition(glm::vec3 position)
{
	this->changed = true;
	this->position = position;
}

void Rogue3d::Core::Transform::setPosition(float x, float y, float z)
{
	this->changed = true;
	this->position = glm::vec3(x, y, z);
}

void Rogue3d::Core::Transform::movePosition(glm::vec3 move)
{
	this->changed = true;
	this->position += move;
}

void Rogue3d::Core::Transform::movePosition(float x, float y, float z)
{
	this->changed = true;
	this->position += glm::vec3(x, y, z);
}

void Rogue3d::Core::Transform::setScale(float x, float y, float z)
{
	this->changed = true;
	this->scale = glm::vec3(x, y, z);
}

void Rogue3d::Core::Transform::setRotation(float x, float y, float z)
{
	this->changed = true;
	this->rotation = glm::vec3(x, y, z);
}

Rogue3d::Core::OrthoTransform::OrthoTransform()
{
	this->near = 0.1f;
	this->far = 100.0f;
	this->width = 800.0f;
	this->height = 600.0f;
	this->updateMatrix();
}

Rogue3d::Core::OrthoTransform::~OrthoTransform()
{
}

glm::mat4 Rogue3d::Core::OrthoTransform::getMatrix()
{
	if (this->changed)
	{
		this->updateMatrix();
	}
	return this->matrix;
}

void Rogue3d::Core::OrthoTransform::setNear(float near)
{
	this->near = near;
	this->changed = true;
}

void Rogue3d::Core::OrthoTransform::setFar(float far)
{
	this->far = far;
	this->changed = true;
}

void Rogue3d::Core::OrthoTransform::setWidth(float width)
{
	this->width = width;
	this->changed = true;
}

void Rogue3d::Core::OrthoTransform::setHeight(float height)
{
	this->height = height;
	this->changed = true;
}

void Rogue3d::Core::OrthoTransform::updateMatrix()
{
	this->matrix = glm::ortho(0.0f, this->width, 0.0f, this->height, this->near, this->far);

	this->changed = false;
}
