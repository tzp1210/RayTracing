// C++
#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 250, HEIGHT = 200;

struct RGBType {
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);   //使用OpenGL版本3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);   //使用core profile
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);   //窗口不会被改变大小

	//创建窗口
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Simple RayTracing", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//设置回调函数
	glfwSetKeyCallback(window, key_callback);

	//启动GLEW
	glewExperimental = GL_TRUE;   //ensures GLEW uses more modern techniques for managing OpenGL functionality
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//设置OpenGL的绘图视窗大小
	glViewport(0, 0, WIDTH, HEIGHT);

	//使窗口不会一闪而过
	RGBType data[WIDTH * HEIGHT];
	while (!glfwWindowShouldClose(window))   //此函数检查GLFW的窗口是否被要求关闭
	{
		glfwPollEvents();   //此函数检查是否有事件被激发,并通知相关的处理函数

		//rendering
		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  //state-setting function,设置要变成的颜色
		glClear(GL_COLOR_BUFFER_BIT);   //state-using function,刷新buffer

		for (int i = 0; i < WIDTH * HEIGHT; ++i)
		{
				data[i].r = 1.0f;
				data[i].g = 0.0f;
				data[i].b = 0.0f;
				data[i].a = 0.5f;
		}
		glDrawPixels(WIDTH, HEIGHT, GL_RGBA, GL_FLOAT, data);
		glfwSwapBuffers(window);   //交换color buffer
	}

	glfwTerminate();   //释放空间，退出程序

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}