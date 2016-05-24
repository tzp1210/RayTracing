#include "Position.h"
#include "Vector.h"

Position operator+(const Position & c1, const Vector & c2)
{
	return Position(c1.getX() + c2.getX(), c1.getY() + c2.getY(), c1.getZ() + c2.getZ());
}

Position operator+(const Vector & c1, const Position & c2)
{
	return c2 + c1;
}

Position operator-(const Position & c1, const Vector & c2)
{
	return c1 + (-c2);
}

