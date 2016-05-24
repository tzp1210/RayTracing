#include <cstdlib>
#include <iostream>
#include "World.h"
#include "Constants.h"
#include "Primitive.h"

World::World(const std::vector<Model*> &models, const std::vector<Position> &positions, const Light light) :
	m_models(models), m_positions(positions), m_light(light)
{
	if (models.size() != positions.size())
	{
		std::cerr << "The number of models and the number of positions don't match when creating an instance of World." << std::endl;
		exit(-1);
	}
}

World::~World()
{
	for (Model*& model : m_models)
	{
		delete model;
		model = nullptr;
	}
}

double max(double a, double b)
{
	return a >= b ? a : b;
}

void World::hit(double tmin, double tmax, const Ray& ray, double& trec, const Primitive*& hitPrimitive, Position& hitPos)
{
	//对于每一个模型，检查是否与光线相交
	trec = Constants::infiniteDistance;
	hitPrimitive = nullptr;
	for (size_t i = 0; i < m_models.size(); ++i)
	{
		const Primitive* tmpHitPrimitive = nullptr;
		Position tmpHitPos;
		double t = m_models[i]->hit(tmin, tmax, tmpHitPrimitive, tmpHitPos, ray, m_positions[i]);
		if (t < trec)
		{
			trec = t;
			hitPrimitive = tmpHitPrimitive;
			hitPos = tmpHitPos;
		}
	}
}

Color World::shading(const Ray& ray, double& trec, const Primitive* hitPrimitive, Position& hitPos, int currentRecursiveNum, int maxRecursiveNum)
{
	if (trec == Constants::infiniteDistance)
	{
		return Constants::backgroundColor;
	} else {
		//Shading
		Color hitColor = hitPrimitive->getHitColor(hitPos);
		Position fragPos = ray.getOrigin() + trec * ray.getDirection();

		Vector totalLight;

		//ambient
		Vector ambientLight = Vector::piecewiseMultiply(m_light.getAmbient(), Vector(hitColor));
		totalLight = ambientLight;

		//shadow
		Vector newRayDirect = Vector::normal(Vector(m_light.getPosition()) - Vector(fragPos));
		Position newRayOrigin(fragPos);
		Ray newRay(newRayDirect, newRayOrigin);
		double shadowTrec = Constants::infiniteDistance;
		const Primitive* shadowHitPrimitive = nullptr;
		Position shadowHitPosition;
		hit(Constants::epsilon, Constants::infiniteDistance, newRay, shadowTrec, shadowHitPrimitive, shadowHitPosition);
		if (shadowHitPrimitive != nullptr)
			return Color(totalLight);

		//diffuse
		Vector hitNormal = hitPrimitive->getHitNormal(hitPos);
		Vector lightDir = Vector::normal(Vector(m_light.getPosition()) - Vector(fragPos));
		double diff = max(Vector::dot(hitNormal, lightDir), 0.0);
		Vector diffuseLight = Vector::piecewiseMultiply(
			Vector::piecewiseMultiply(m_light.getDiffuse(), Vector(diff, diff, diff)),
			Vector(hitColor));
		totalLight = totalLight + diffuseLight;

		// Specular
		Vector viewDir = Vector::normal(Vector(ray.getOrigin()) - Vector(fragPos));
		Vector halfVec = Vector::normal(viewDir + lightDir);
		double spec = pow(max(Vector::dot(hitNormal, halfVec), 0.0), (hitPrimitive->getMaterial()).getMaterialShininess());
		Vector specularLight = Vector::piecewiseMultiply(
			Vector::piecewiseMultiply(m_light.getSpecular(), Vector(spec, spec, spec)),
			Vector(hitColor));
		totalLight = totalLight + specularLight;

		// Ideal Specular Reflection
		if (currentRecursiveNum < maxRecursiveNum && hitPrimitive->getMaterial().isIdealSpecular())
		{
			Vector idealRayDirect = Vector::normal((-viewDir) - 2 * Vector::dot(-viewDir, hitNormal) * hitNormal);
			Position idealRayOrigin(fragPos);
			Ray idealRay(idealRayDirect, idealRayOrigin);
			double idealTrec = Constants::infiniteDistance;
			const Primitive* idealHitPrimitive = nullptr;
			Position idealHitPosition;
			hit(Constants::epsilon, Constants::infiniteDistance, idealRay, idealTrec, idealHitPrimitive, idealHitPosition);
			if (idealHitPrimitive != nullptr)
			{
				totalLight = totalLight + shading(idealRay, idealTrec, idealHitPrimitive, idealHitPosition, currentRecursiveNum + 1, maxRecursiveNum);
			}
		}

		return Color(totalLight);
	}
}

////阴影部分应该是没有镜子的倒影的，所以这个可能是不对的
//Color World::shading(const Ray& ray, double& trec, const Primitive* hitPrimitive, Position& hitPos, int currentRecursiveNum, int maxRecursiveNum)
//{
//	if (trec == Constants::infiniteDistance)
//	{
//		return Constants::backgroundColor;
//	}
//	else {
//		//Shading
//		Color hitColor = hitPrimitive->getHitColor(hitPos);
//		Position fragPos = ray.getOrigin() + trec * ray.getDirection();
//		Vector viewDir = Vector::normal(Vector(ray.getOrigin()) - Vector(fragPos));
//		Vector hitNormal = hitPrimitive->getHitNormal(hitPos);
//
//		Vector totalLight;
//
//		//ambient
//		Vector ambientLight = Vector::piecewiseMultiply(m_light.getAmbient(), Vector(hitColor));
//		totalLight = ambientLight;
//
//		// Ideal Specular Reflection
//		if (currentRecursiveNum < maxRecursiveNum && hitPrimitive->getMaterial().isIdealSpecular())
//		{
//			Vector idealRayDirect = Vector::normal((-viewDir) - 2 * Vector::dot(-viewDir, hitNormal) * hitNormal);
//			Position idealRayOrigin(fragPos);
//			Ray idealRay(idealRayDirect, idealRayOrigin);
//			double idealTrec = Constants::infiniteDistance;
//			const Primitive* idealHitPrimitive = nullptr;
//			Position idealHitPosition;
//			hit(Constants::epsilon, Constants::infiniteDistance, idealRay, idealTrec, idealHitPrimitive, idealHitPosition);
//			if (idealHitPrimitive != nullptr)
//			{
//				totalLight = totalLight + shading(idealRay, idealTrec, idealHitPrimitive, idealHitPosition, currentRecursiveNum + 1, maxRecursiveNum);
//			}
//		}
//
//		//shadow
//		Vector newRayDirect = Vector::normal(Vector(m_light.getPosition()) - Vector(fragPos));
//		Position newRayOrigin(fragPos);
//		Ray newRay(newRayDirect, newRayOrigin);
//		double shadowTrec = Constants::infiniteDistance;
//		const Primitive* shadowHitPrimitive = nullptr;
//		Position shadowHitPosition;
//		hit(Constants::epsilon, Constants::infiniteDistance, newRay, shadowTrec, shadowHitPrimitive, shadowHitPosition);
//		if (shadowHitPrimitive != nullptr)
//			return Color(totalLight);
//
//		//diffuse
//		//Vector hitNormal = hitPrimitive->getHitNormal(hitPos);
//		Vector lightDir = Vector::normal(Vector(m_light.getPosition()) - Vector(fragPos));
//		double diff = max(Vector::dot(hitNormal, lightDir), 0.0);
//		Vector diffuseLight = Vector::piecewiseMultiply(
//			Vector::piecewiseMultiply(m_light.getDiffuse(), Vector(diff, diff, diff)),
//			Vector(hitColor));
//		totalLight = totalLight + diffuseLight;
//
//		// Specular
//		//Vector viewDir = Vector::normal(Vector(ray.getOrigin()) - Vector(fragPos));
//		Vector halfVec = Vector::normal(viewDir + lightDir);
//		double spec = pow(max(Vector::dot(hitNormal, halfVec), 0.0), (hitPrimitive->getMaterial()).getMaterialShininess());
//		Vector specularLight = Vector::piecewiseMultiply(
//			Vector::piecewiseMultiply(m_light.getSpecular(), Vector(spec, spec, spec)),
//			Vector(hitColor));
//		totalLight = totalLight + specularLight;
//
//		return Color(totalLight);
//	}
//}