
#define STB_IMAGE_IMPLEMENTATION
#include "Rogue3d.h"
using namespace Rogue3d::Core;
int main(int argc, char** argv)
{
	stbi_set_flip_vertically_on_load(true);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Rogue3d", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to Create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -2;
	}

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	});

	float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};






	Transform model = Transform();
	Transform view = Transform();
	OrthoTransform projection = OrthoTransform();

	view.setPosition(0.0f, 0.0f, -1.0f);
	model.setScale(1000.0f, 1000.0f, 1000.0f);
	

	VAO rect = VAO();
	VBO rectVertices = VBO();
	EBO rectIndices = EBO();
	rectVertices.bind();
	rect.bind();

	rectVertices.bufferData(vertices, sizeof(vertices), GL_STATIC_DRAW);

	rect.configureVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	rect.enableVertexAttribPointer(0);
	rectIndices.bind();
	rectIndices.bufferData(indices, sizeof(indices), GL_STATIC_DRAW);

	rect.unBind();
	rectVertices.unBind();
	rectIndices.unBind();
	

	ShaderProgram shaderProgram("fragmentshader.shader", "vertexshader.shader");

	Texture tex = Texture("Unbenannt.png");
	tex.bind(0);
	tex.configureDefaultTextureParameter();
	tex.unBind();
	

	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE)) 
		{
			glfwSetWindowShouldClose(window, true);
		}

		glClear(GL_COLOR_BUFFER_BIT);



		shaderProgram.bind();
		rect.bind();
		tex.bind(0);
		shaderProgram.setUniform("ourColor", 1.0f, 1.0f, 0.0f, 1.0f);
		shaderProgram.setUniform("model", model.getMatrix());
		shaderProgram.setUniform("view", view.getMatrix());
		shaderProgram.setUniform("projection", projection.getMatrix());
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
		rect.unBind();
		shaderProgram.unBind();
		tex.unBind();
	}


	glfwTerminate();
	return 0;
}