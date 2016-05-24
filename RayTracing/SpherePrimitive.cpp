#include <cmath>
#include "SpherePrimitive.h"
#include "Constants.h"
#include "Ray.h"
#include "Position.h"

double square(double x)
{
	return x * x;
}

double SpherePrimitive::hit(Position& hitPos, const Ray & ray, 
	const double tmin, const double tmax, const Position & modelPos, const Position & primitivePos)
{
	Vector vecPos(Vector(modelPos) + Vector(primitivePos));
	Vector vecOrigin(ray.getOrigin());
	Vector vecDirect(ray.getDirection());
	double discriminant = square(Vector::dot(vecDirect, vecOrigin - vecPos)) -
		Vector::dot(vecDirect, vecDirect) *
		(Vector::dot(vecOrigin - vecPos, vecOrigin - vecPos) - square(m_radius));
	if (discriminant < 0)
	{
		return Constants::infiniteDistance;
	} else if(discriminant == 0) {
		double t = (-Vector::dot(ray.getDirection(), ray.getOrigin() - vecPos)) / Vector::dot(ray.getDirection(), ray.getDirection());
		if (t < tmin || t >= tmax)
		{
			return Constants::infiniteDistance;
		}
		else {
			hitPos = ray.getOrigin() + t * ray.getDirection() - vecPos;
			return t;
		}
	} else {
		double t1 = ((-Vector::dot(ray.getDirection(), ray.getOrigin() - vecPos)) - sqrt(discriminant)) /
			Vector::dot(ray.getDirection(), ray.getDirection());
		double t2 = ((-Vector::dot(ray.getDirection(), ray.getOrigin() - vecPos)) + sqrt(discriminant)) /
			Vector::dot(ray.getDirection(), ray.getDirection());
		if (t1 >= 0 && t1 >=tmin && t1 < tmax)
		{
			hitPos = ray.getOrigin() + t1 * ray.getDirection() - vecPos;
			return t1;
		}
		else if (t2 >= 0 && t2 >= tmin && t2 < tmax)
		{
			hitPos = ray.getOrigin() + t2 * ray.getDirection() - vecPos;
			return t2;
		}
		else
		{
			return Constants::infiniteDistance;
		}
	}
}

Color SpherePrimitive::getHitColor(Position & hitPos) const
{
	return m_color;
}

Vector SpherePrimitive::getHitNormal(Position & hitPos) const
{
	return Vector::normal(Vector(hitPos));
}
