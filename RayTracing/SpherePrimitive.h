#ifndef SPHERE_PRIMITIVE_H
#define SPHERE_PRIMITIVE_H

#include "Color.h"
#include "Primitive.h"
#include "Material.h"

class SpherePrimitive : public Primitive
{
private:
	double m_radius;
	Color m_color;

public:
	SpherePrimitive(Material material, double radius, Color color) :
		Primitive(material), m_radius(radius), m_color(color) { }
	virtual ~SpherePrimitive() = default;
	SpherePrimitive(const SpherePrimitive &c) = default;

	double getRadius() const { return m_radius; }
	Color getColor() const { return m_color; }

	virtual double hit(Position& hitPos, const Ray & ray, const double tmin, const double tmax, const Position & modelPos, const Position & primitivePos);
	virtual Color getHitColor(Position& hitPos) const;
	virtual Vector getHitNormal(Position& hitPos) const;
};

#endif
