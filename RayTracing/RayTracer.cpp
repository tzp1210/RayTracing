#include <GL/glut.h>
#include "RayTracer.h"
#include "Frame.h"
#include "World.h"
#include "Ray.h"

RayTracer::RayTracer(World & world, const Frame frame, const double planeDistance,
	const int planeWidth, const int planeHeight, double left, double right, double top, double bottom) :
	m_world(world), m_frame(frame), m_planeDistance(planeDistance),
	m_plane(planeWidth, planeHeight, left, right, top, bottom)
{
}

void RayTracer::doRendering(GLfloat* data)
{
	//对于每一个像素，求出其颜色
	for (int i = 0; i < m_plane.getPixelHeight(); ++i)
	{
		for (int j = 0; j < m_plane.getPixelWidth(); ++j)
		{
			double u = m_plane.getLeft() + (m_plane.getRight() - m_plane.getLeft()) * (j + 0.5) / m_plane.getPixelWidth();
			double v = m_plane.getBottom() + (m_plane.getTop() - m_plane.getBottom()) * (i + 0.5) / m_plane.getPixelHeight();
			Vector direction = -(m_planeDistance * m_frame.getW()) + u * m_frame.getU() + v * m_frame.getV();
			Ray ray(direction, m_frame.getPosition());
			
			double tmin = Constants::infiniteDistance;
			const Primitive* hitPrimitive = nullptr;
			Position hitPos;
			m_world.hit(0, Constants::infiniteDistance, ray, tmin, hitPrimitive, hitPos);
			m_plane.setPixel(i, j, m_world.shading(ray, tmin, hitPrimitive, hitPos, 1, 2));
		}
	}
	//给data赋值
	for (int i = 0; i < m_plane.getPixelHeight(); ++i)
	{
		for (int j = 0; j < m_plane.getPixelWidth(); ++j)
		{
			data[3 * ((i * m_plane.getPixelWidth()) + j) + 0] = static_cast<GLfloat>(m_plane.getPixel(i, j).getR());
			data[3 * ((i * m_plane.getPixelWidth()) + j) + 1] = static_cast<GLfloat>(m_plane.getPixel(i, j).getG());
			data[3 * ((i * m_plane.getPixelWidth()) + j) + 2] = static_cast<GLfloat>(m_plane.getPixel(i, j).getB());
		}
	}
}
