//RayTracing
#include <GL/glut.h>
#include "Constants.h"
#include "Position.h"
#include "Vector.h"
#include "SpherePrimitive.h"
#include "TrianglePrimitive.h"
#include "World.h"
#include "RayTracer.h"
#include "Frame.h"
#include "Material.h"

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//World world(
	//	{ new Model({
	//		new SpherePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 32.0),
	//		30.0, Color(1.0, 0.0, 0.0)) },
	//		{ Position(0.0, 0.0, 0.0) }),
	//	  new Model({
	//		new SpherePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 32.0),
	//		30.0, Color(0.0, 1.0, 0.0)) },
	//		{ Position(0.0, 0.0, 0.0) })
	//	},
	//	{ Position(0.0, 35.0, -40.0),
	//	  Position(0.0, -35.0, -40.0)
	//	},
	//	Light(Position(20.0, 20.0, 0.0), Color(1.0, 1.0, 1.0), Vector(0.2, 0.2, 0.2), Vector(0.5, 0.5, 0.5), Vector(1.0, 1.0, 1.0))
	//);

	World world(
	{
		new Model(
		{
			new SpherePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 2.0, true),
			5.0, Color(0.8, 0.8, 0.8)),

			new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			Position(-20.0, 0.0, 0.0), Position(20.0, 0.0, 0.0), Position(20.0, 0.0, -16.0), Color(0.7, 0.7, 0.7), true),
			new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			Position(-20.0, 0.0, -16.0), Position(20.0, 0.0, -16.0), Position(-20.0, 0.0, 0.0), Color(0.7, 0.7, 0.7), false),

			//new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			//Position(-20.0, 0.0, -16.0), Position(20.0, 0.0, -16.0), Position(-20.0, 70.0, -16.0), Color(0.5, 0.6, 0.7), true),
			//new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			//Position(-20.0, 70.0, -16.0), Position(20.0, 70.0, -16.0), Position(20.0, 0.0, -16.0), Color(0.5, 0.6, 0.7), false),

			new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, false),
			Position(-20.0, 0.0, -16.0), Position(-20.0, 0.0, 0.0), Position(-20.0, 70.0, 0.0), Color(0.7, 0.6, 0.5), false),
			new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, false),
			Position(-20.0, 70.0, -16.0), Position(-20.0, 70.0, 0.0), Position(-20.0, 0.0, -16.0), Color(0.7, 0.6, 0.5), true),


			//new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			//Position(20.0, 0.0, -16.0), Position(20.0, 0.0, 0.0), Position(20.0, 70.0, 0.0), Color(0.0, 0.8, 0.0), false),
			//new TrianglePrimitive(Material(Vector(1.0, 0.5, 0.31), Vector(1.0, 0.5, 0.31), Vector(0.5, 0.5, 0.5), 30.0, true),
			//Position(20.0, 70.0, -16.0), Position(20.0, 70.0, 0.0), Position(20.0, 0.0, -16.0), Color(0.0, 0.8, 0.0), true),
		},
		{
			Position(0.0, 5.0, -5.5),

			Position(0.0, 0.0, 0.0),
			Position(0.0, 0.0, 0.0),

			//Position(0.0, 0.0, 0.0),
			//Position(0.0, 0.0, 0.0),

			Position(0.0, 0.0, 0.0),
			Position(0.0, 0.0, 0.0),

			//Position(0.0, 0.0, 0.0),
			//Position(0.0, 0.0, 0.0)
		})
	},
	{ 
		Position(0.0, 0.0, 0.0)
	},
	Light(Position(-5.0, 7.0, 0.0), Color(1.0, 1.0, 1.0), Vector(0.2, 0.2, 0.2), Vector(0.7, 0.7, 0.7), Vector(1.0, 1.0, 1.0))
	);

	Frame frame(Position(0.0, 5.0, 1), Vector(0.0, 0.0, -1.0), Vector(0.0, 1.0, 0.0));
	//以这个世界场景创建一个光线跟踪器，第二个和第三个参数分别是眼睛位置和眼睛看的方向。
	RayTracer *rayTracer = new RayTracer(world, frame, 0.5, ScreenSize::width, ScreenSize::height, -2.2, 2.2, 2.2, -2.2);
	GLfloat *data = new GLfloat[ScreenSize::width * ScreenSize::height * 3];
	rayTracer->doRendering(data);
	glDrawPixels(ScreenSize::width, ScreenSize::height, GL_RGB, GL_FLOAT, data);
	delete[] data;
	data = nullptr;

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(ScreenSize::width, ScreenSize::height);
	glutCreateWindow("GLUT");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}