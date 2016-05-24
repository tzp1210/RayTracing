#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <GL/glut.h>
#include "Position.h"
#include "Vector.h"
#include "Frame.h"
#include "ImagePlane.h"

class World;

class RayTracer
{
private:
	World &m_world;
	Frame m_frame;
	double m_planeDistance;
	ImagePlane m_plane;

public:
	RayTracer(World& world, const Frame frame, const double planeDistance,
		const int planeWidth, const int planeHeight, double left, double right, double top, double bottom);
	~RayTracer() = default;

	void doRendering(GLfloat* data);
};

#endif
