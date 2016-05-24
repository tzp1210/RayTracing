#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Model.h"
#include "Position.h"
#include "Color.h"
#include "Ray.h"
#include "Light.h"

class World
{
private:
	std::vector<Model*> m_models;
	std::vector<Position> m_positions;
	Light m_light;

public:
	World(const std::vector<Model*> &models, const std::vector<Position> &positions, const Light light);
	~World();

	void hit(double tmin, double tmax, const Ray &ray, double& trec, const Primitive*& hitPrimitive, Position& hitPos);
	Color shading(const Ray& ray, double& trec, const Primitive* hitPrimitive, Position& hitPos, int currentRecursiveNum, int maxRecursiveNum);
};

#endif
