#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
//shaders



int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);		//sets max version of openGL to 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);		//Min ver to 3 as well
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//Specifies we are using the core profile, we are not using the compatibility libraries for this project

	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	GLFWwindow* window = glfwCreateWindow(640, 480, "Main", NULL, NULL); //creates a 640x480 window with name "Main"
	glfwMakeContextCurrent(window);

	gladLoadGL();					//load glad so we can use graphics drivers
	glViewport(0, 0, 640, 480);		//specifies the viewport or the framebuffer size, this is seperate from the window size but should be made the same size

	
	///////////////////////////////// create a vertex buffer object to store all vertex data

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 640, 480);

	//NOW WE NEED THE POINTER TO DRAW THE IMAGH E BECAUSE IT CANT FIND IT ITSELF????
	//"VAOs" it stores pointers to serveral VBOs,and interprets them
	//needed to switch between different VBOs

	
	GLuint vertexArrayObject, vertexBufferObject;
		//use VAO with 1 object
		//uses VBO with 1 3d object
		

		//current "binded" Object

	//we can use glBufferData() to write data

			//(type_of_buffer, size, vertices, type_of_data)	

	

	
	
	
	
	glBindVertexArray(0);
	
	
			//sets the color of background buffer to black
	glClear(GL_COLOR_BUFFER_BIT);	//clears front buffer
	glfwSwapBuffers(window);		//swaps back/front buffers

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);	//colour of background
		glClear(GL_COLOR_BUFFER_BIT);			//clears the back buffer, the new colour gets applied
		glUseProgram(shaderProgram);			//multiples shader programs may be used, so this specifies which one
		glBindVertexArray(vertexArrayObject);	//binds the VAO
		glDrawArrays(GL_TRIANGLES, 0, 3);	//draws the first object in the VAO
		glfwSwapBuffers(window);			//displays the drawn image

		glfwPollEvents();		//processes events while the window is not closed, when this finishes the program terminates
	};


	glfwDestroyWindow(window);
	glfwTerminate();
}