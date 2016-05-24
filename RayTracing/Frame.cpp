#include <cstdlib>
#include <iostream>
#include "Frame.h"

class Position;

Frame::Frame(const Position &position, const Vector &u, const Vector &v, const Vector &w) : m_position(position)
{
	if (Vector::dot(u, v) == 0 && Vector::dot(v, w) == 0 && Vector::dot(w, u) == 0)
	{
		m_u = Vector::normal(u);
		m_v = Vector::normal(v);
		m_w = Vector::normal(w);
	} else {
		std::cerr << "Vectors can't form a coordinate frame!" << std::endl;
		exit(-1);
	}
}

Frame::Frame(const Position &position, const Vector &eyeDirection, const Vector &up) : m_position(position)
{
	if (eyeDirection.length() == 0 || up.length() == 0)
	{
		std::cerr << "Vector eyeDirection or up can't be zero vector!" << std::endl;
		exit(-1);
	}
	m_w = -Vector::normal(eyeDirection);
	m_u = Vector::normal(up * m_w);
	m_v = Vector::normal(m_w * m_u);
}
