#ifndef VECTOR_H
#define VECTOR_H

#include "Color.h"
#include "Position.h"

class Vector
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector(const double x, const double y, const double z) : m_x(x), m_y(y), m_z(z) { }
	Vector() : Vector(0.0, 0.0, 0.0) { }
	Vector(Position pos);
	Vector(Color color);
	~Vector() = default;
	Vector(const Vector &c) = default;

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }
	void getXYZ(double &x, double &y, double &z) const { x = m_x; y = m_y; z = m_z; }

	void setX(const double x) { m_x = x; }
	void setY(const double y) { m_y = y; }
	void setZ(const double z) { m_z = z; }
	void setXYZ(const double x, const double y, const double z) { m_x = x; m_y = y; m_z = z; }

	double length() const;

	static Vector normal(const Vector &v);
	static double dot(const Vector &a, const Vector &b);
	static Vector piecewiseMultiply(const Vector &a, const Vector &b);

	Vector operator-() const;
	friend Vector operator+(const Vector& c1, const Vector& c2);
	friend Vector operator-(const Vector& c1, const Vector& c2);
	friend Vector operator*(const Vector& c1, const Vector& c2);
	friend Vector operator*(const double c1, const Vector& c2);
	friend Vector operator*(const Vector& c1, const double c2);
};

Vector operator+(const Vector& c1, const Vector& c2);
Vector operator-(const Vector& c1, const Vector& c2);
Vector operator*(const Vector& c1, const Vector& c2);
Vector operator*(const double c1, const Vector& c2);
Vector operator*(const Vector& c1, const double c2);

#endif
