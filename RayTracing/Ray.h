#ifndef RAY_H
#define RAY_H

#include "Vector.h"
#include "Position.h"

class Ray
{
private:
	Vector m_direction;
	Position m_origin;

public:
	Ray(Vector direction, Position origin) : m_direction(direction), m_origin(origin) { }
	Vector getDirection() const { return m_direction; }
	Position getOrigin() const { return m_origin; }
};

#endif
