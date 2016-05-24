#ifndef TRIANGLE_PRIMITIVE_H
#define TRIANGLE_PRIMITIVE_H

#include "Primitive.h"
#include "Position.h"
#include "Color.h"
#include "Vector.h"

class Material;
class Ray;

class TrianglePrimitive : public Primitive
{
private:
	Position m_a;
	Position m_b;
	Position m_c;
	Color m_color;
	Vector m_normal;

public:
	TrianglePrimitive(Material material, Position a, Position b, Position c, Color color, bool normalDirect);
	virtual ~TrianglePrimitive() = default;
	TrianglePrimitive(const TrianglePrimitive& c) = default;

	virtual double hit(Position& hitPos, const Ray & ray, const double tmin, const double tmax, const Position & modelPos, const Position & primitivePos);
	virtual Color getHitColor(Position& hitPos) const;
	virtual Vector getHitNormal(Position& hitPos) const;
};

#endif