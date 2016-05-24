#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Color.h"
#include "Material.h"
class Ray;
class Position;

class Primitive
{
protected:
	Material m_material; //TODO:暂且没有用到，以后可以添加

public:
	Primitive(Material material) : m_material(material) { }
	virtual ~Primitive() = default;

	virtual double hit(Position& hitPos, const Ray & ray, 
		const double tmin, const double tmax, const Position & modelPos, const Position & primitivePos) = 0;
	virtual Color getHitColor(Position& hitPos) const = 0;
	virtual Vector getHitNormal(Position& hitPos) const = 0;
	Material getMaterial() const { return m_material; }
};

#endif