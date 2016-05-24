#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Vector.h"
#include "Position.h"
#include "Color.h"

Vector::Vector(Position pos) : Vector(pos.getX(), pos.getY(), pos.getZ())
{
}

Vector::Vector(Color color) : Vector(color.getR(), color.getG(), color.getB())
{
}

double Vector::length() const
{
	
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector Vector::normal(const Vector & v)
{
	double len = v.length();
	if (len > 0)
	{
		return Vector(v.getX() / len, v.getY() / len, v.getZ() / len);
	}
	else
	{
		std::cerr << "The divisor can't be zero when computing normal!" << std::endl;
		exit(-1);
	}
}

double Vector::dot(const Vector & a, const Vector & b)
{
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

Vector Vector::piecewiseMultiply(const Vector & a, const Vector & b)
{
	return Vector(a.getX() * b.getX(), a.getY() * b.getY(), a.getZ() * b.getZ());
}

Vector Vector::operator-() const
{
	return Vector(-getX(), -getY(), -getZ());
}

Vector operator+(const Vector & c1, const Vector & c2)
{
	return Vector(c1.getX() + c2.getX(), c1.getY() + c2.getY(), c1.getZ() + c2.getZ());
}

Vector operator-(const Vector & c1, const Vector & c2)
{
	return Vector(c1.getX() - c2.getX(), c1.getY() - c2.getY(), c1.getZ() - c2.getZ());
}

Vector operator*(const Vector & c1, const Vector & c2)
{

	return Vector(c1.getY() * c2.getZ() - c2.getY() * c1.getZ(),
				  c1.getZ() * c2.getX() - c2.getZ() * c1.getX(),
		          c1.getX() * c2.getY() - c2.getX() * c1.getY());
}

Vector operator*(const double c1, const Vector & c2)
{
	return Vector(c1 * c2.getX(), c1 * c2.getY(), c1 * c2.getZ());
}

Vector operator*(const Vector & c1, const double c2)
{
	return c2 * c1;
}
