#ifndef POSITION_H
#define POSITION_H

class Vector;

class Position
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Position(const double x, const double y, const double z) : m_x(x), m_y(y), m_z(z) { }
	Position() : Position(0.0, 0.0, 0.0) { }
	~Position() = default;
	Position(const Position &c) = default;

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }
	void getXY(double &x, double &y, double &z) const { x = m_x; y = m_y; z = m_z; }

	void setX(const double x) { m_x = x; }
	void setY(const double y) { m_y = y; }
	void setZ(const double z) { m_z = z; }
	void setXY(const double x, const double y, const double z) { m_x = x; m_y = y; m_z = z; }

	friend Position operator+(const Position& c1, const Vector& c2);
	friend Position operator+(const Vector& c1, const Position& c2);
	friend Position operator-(const Position& c1, const Vector& c2);
};

Position operator+(const Position& c1, const Vector& c2);
Position operator+(const Vector& c1, const Position& c2);
Position operator-(const Position& c1, const Vector& c2);

#endif
