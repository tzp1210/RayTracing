#include "Constants.h"
#include "TrianglePrimitive.h"
#include "Material.h"
#include "Ray.h"

//normalDirect为真时，normal的方向是AB* AC的单位向量，否则则取负
TrianglePrimitive::TrianglePrimitive(Material material, Position a, Position b, Position c, Color color, bool normalDirect) :
	Primitive(material), m_a(a), m_b(b), m_c(c), m_color(color)
{
	if (normalDirect == true)
	{
		m_normal = Vector::normal((Vector(b) - Vector(a)) * (Vector(c) - Vector(a)));
	} else {
		m_normal = -Vector::normal((Vector(b) - Vector(a)) * (Vector(c) - Vector(a)));
	}
}

double TrianglePrimitive::hit(Position & hitPos, const Ray & ray, 
	const double tmin, const double tmax, const Position & modelPos, const Position & primitivePos)
{
	Vector vecPosA(Vector(m_a) + Vector(modelPos) + Vector(primitivePos)); //vector a
	Vector vecPosB(Vector(m_b) + Vector(modelPos) + Vector(primitivePos)); //vector b
	Vector vecPosC(Vector(m_c) + Vector(modelPos) + Vector(primitivePos)); //vector c
	Vector vecOriginE(ray.getOrigin()); //vector e
	Vector vecDirectD(ray.getDirection()); //vector d
	
	double Ma = vecPosA.getX() - vecPosB.getX();
	double Mb = vecPosA.getY() - vecPosB.getY();
	double Mc = vecPosA.getZ() - vecPosB.getZ();
	double Md = vecPosA.getX() - vecPosC.getX();
	double Me = vecPosA.getY() - vecPosC.getY();
	double Mf = vecPosA.getZ() - vecPosC.getZ();
	double Mg = vecDirectD.getX();
	double Mh = vecDirectD.getY();
	double Mi = vecDirectD.getZ();
	double Mj = vecPosA.getX() - vecOriginE.getX();
	double Mk = vecPosA.getY() - vecOriginE.getY();
	double Ml = vecPosA.getZ() - vecOriginE.getZ();
	double M = Ma * (Me * Mi - Mh * Mf) + Mb * (Mg * Mf - Md * Mi) + Mc * (Md * Mh - Me * Mg);

	//compute t
	double t =
		-(Mf * (Ma * Mk - Mj * Mb) + Me * (Mj * Mc - Ma * Ml) + Md * (Mb * Ml - Mk * Mc)) / M;
	if (t < tmin || t >= tmax) //注意这里要用>=
		return Constants::infiniteDistance;
	double gamma =
		(Mi * (Ma *Mk - Mj * Mb) + Mh * (Mj * Mc - Ma * Ml) + Mg * (Mb * Ml - Mk * Mc)) / M;
	if (gamma < 0 || gamma > 1)
		return Constants::infiniteDistance;
	double beta =
		(Mj * (Me * Mi - Mh * Mf) + Mk * (Mg * Mf - Md * Mi) + Ml * (Md * Mh - Me * Mg)) / M;
	if (beta < 0 || beta >(1 - gamma))
		return Constants::infiniteDistance;
	return t;
}

Color TrianglePrimitive::getHitColor(Position & hitPos) const
{
	return m_color;
}

Vector TrianglePrimitive::getHitNormal(Position & hitPos) const
{
	return m_normal;
}


