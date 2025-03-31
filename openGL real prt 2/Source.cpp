#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "VAO.h"
#include "VBO.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\0";


int main()
{
	glfwInit();	//loads glfw

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);		//sets max version of openGL to 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);		//Min ver to 3 as well
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//Specifies we are using the core profile, we are not using the compatibility libraries for this project

	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, -1.0f // Upper corner
	};

	GLFWwindow* window = glfwCreateWindow(640, 480, "Main", NULL, NULL); //creates a 640x480 window with name "Main"
	glfwMakeContextCurrent(window);

	gladLoadGL();					//load glad so we can use graphics drivers
	glViewport(0, 0, 640, 480);		//specifies the viewport or the framebuffer size, this is seperate from the window size but should be made the same size

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);	//creates the reference for the vertex shader
	glShaderSource(vertShader, 1, &vertexShaderSource, NULL);	//gives the reference the data of the actual shader
	glCompileShader(vertShader);	//compiles the vertex shader, is now ready to be attached to the context

	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);  
	glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragShader);


	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);

	glLinkProgram(shaderProgram);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	glViewport(0, 0, 640, 480);

	VAO VAO1;	//initalise VAO
	VAO1.Bind();	//bind the VAO



	VBO VBO1(vertices, sizeof(vertices));
	VBO1.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	VAO1.LinkVBO(VBO1,0);
	VAO1.Unbind();
	glClear(GL_COLOR_BUFFER_BIT);	//clears front buffer
	glfwSwapBuffers(window);		//swaps back/front buffers

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);	//colour of background
		glClear(GL_COLOR_BUFFER_BIT);			//clears the back buffer, the new colour gets applied
		glUseProgram(shaderProgram);			//multiples shader programs may be used, so this specifies which one
		VAO1.Bind();	//binds the VAO
		glDrawArrays(GL_TRIANGLES, 0, 3);	//draws the first object in the VAO
		glfwSwapBuffers(window);			//displays the drawn image

		glfwPollEvents();		//processes events while the window is not closed, when this finishes the program terminates
	};


	glfwDestroyWindow(window);
	glfwTerminate();
}