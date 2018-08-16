	#include<glad/glad.h>
	#include <GLFW/glfw3.h>
	#include<iostream>
	using namespace std;

	void processInput(GLFWwindow *window);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
   
	int main() {
		// 初始化GLFW
	    glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//创建一个窗口
		GLFWwindow* window = glfwCreateWindow(1200, 600, "LearnOpenGL", NULL, NULL);

		if (window == NULL) {
			cout << "Failed to create GLFW window" << endl;
			glfwTerminate();
			return -1;
		}
		// 设置到当前上下文
		glfwMakeContextCurrent(window);

		// GLAD是用来管理OpenGL的函数指针的，
		// 所以在调用任何OpenGL的函数之前我们需要初始化GLAD。
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			cout << "Failed to initialize GLAD" << endl;
			return -1;
		}

		glViewport(0, 0, 800, 600);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		while (!glfwWindowShouldClose(window)) {
			processInput(window);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}


	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}


	void processInput(GLFWwindow *window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
		}