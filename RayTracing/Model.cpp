#include <vector>
#include "Model.h"
#include "Constants.h"
#include "SpherePrimitive.h"
#include "Primitive.h"
#include <iostream>
class Ray;
class Position;

Model::Model(std::vector<Primitive*> primitives, const std::vector<Position> &positions) : m_positions(positions)
{
	if (positions.size() != primitives.size())
	{
		std::cerr << "The size of positions and the size of primitives don't match when creating model!" << std::endl;
		exit(-1);
	}
	for (Primitive* primitive : primitives)
	{
		m_primitives.push_back(primitive);
	}
}

Model::~Model()
{
	for (Primitive*& primitive : m_primitives)
	{
		delete primitive;
		primitive = nullptr;
	}
}

//tmin和tmax表示光线的t的范围
double Model::hit(double tmin, double tmax, const Primitive*& hitPrimitive, Position& hitPos, const Ray & ray, const Position & modelPos)
{
	//对于每一个图元
	double trec = Constants::infiniteDistance;
	hitPrimitive = nullptr;
	for (size_t i = 0; i < m_primitives.size(); ++i)
	{
		Position tmpHitPos;
		double t = m_primitives[i]->hit(tmpHitPos, ray, tmin, tmax, modelPos, m_positions[i]);
		if (t < trec)
		{
			trec = t;
			hitPrimitive = m_primitives[i];
			hitPos = tmpHitPos;
		}
	}
	return trec;
}