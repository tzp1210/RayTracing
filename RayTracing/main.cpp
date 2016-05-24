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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);   //ʹ��OpenGL�汾3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);   //ʹ��core profile
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);   //���ڲ��ᱻ�ı��С

	//��������
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Simple RayTracing", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//���ûص�����
	glfwSetKeyCallback(window, key_callback);

	//����GLEW
	glewExperimental = GL_TRUE;   //ensures GLEW uses more modern techniques for managing OpenGL functionality
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//����OpenGL�Ļ�ͼ�Ӵ���С
	glViewport(0, 0, WIDTH, HEIGHT);

	//ʹ���ڲ���һ������
	RGBType data[WIDTH * HEIGHT];
	while (!glfwWindowShouldClose(window))   //�˺������GLFW�Ĵ����Ƿ�Ҫ��ر�
	{
		glfwPollEvents();   //�˺�������Ƿ����¼�������,��֪ͨ��صĴ�����

		//rendering
		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  //state-setting function,����Ҫ��ɵ���ɫ
		glClear(GL_COLOR_BUFFER_BIT);   //state-using function,ˢ��buffer

		for (int i = 0; i < WIDTH * HEIGHT; ++i)
		{
				data[i].r = 1.0f;
				data[i].g = 0.0f;
				data[i].b = 0.0f;
				data[i].a = 0.5f;
		}
		glDrawPixels(WIDTH, HEIGHT, GL_RGBA, GL_FLOAT, data);
		glfwSwapBuffers(window);   //����color buffer
	}

	glfwTerminate();   //�ͷſռ䣬�˳�����

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}