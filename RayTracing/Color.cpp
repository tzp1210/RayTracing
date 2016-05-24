#include "Color.h"
#include "Vector.h"

Color::Color(const Vector & c) : Color(c.getX(), c.getY(), c.getZ())
{
}
