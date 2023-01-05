#include "Rogue3d.h"

#ifndef Rogue3d_Core_H
#define Rogue3d_Core_H
namespace Rogue3d::Core
{
	class Transform
	{
	public:
		Transform();
		~Transform();
		glm::mat4 getMatrix();
		void setPosition(glm::vec3 position);
		void setPosition(float x, float y, float z);
		void movePosition(glm::vec3 move);
		void movePosition(float x, float y, float z);
		void setScale(float x, float y, float z);
		void setRotation(float x, float y, float z);

	private:
		void updateMatrix();
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		bool changed;
		glm::mat4 matrix;
	};


	class OrthoTransform
	{
	public:
		OrthoTransform();
		~OrthoTransform();
		glm::mat4 getMatrix();
		void setNear(float near);
		void setFar(float far);
		void setWidth(float width);
		void setHeight(float height);

	private:
		glm::mat4 matrix;
		void updateMatrix();
		bool changed;
		float near;
		float far;
		float width;
		float height;
	};
}
#endif Rogue3d_Core_H

