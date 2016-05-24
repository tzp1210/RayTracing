#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Constants.h"
#include "Primitive.h"
#include "SpherePrimitive.h"
class Ray;
class Position;

class Model
{
private:
	std::vector<Primitive*> m_primitives;
	std::vector<Position> m_positions; 
	//TODO:有问题，不能这样写！！！暂且禁止Model的复制和赋值操作，以后再添加。
	//Model(const Model &c);
	//Model& operator=(const Model&);

public:
	Model() = default;
	Model(std::vector<Primitive*> primitives, const std::vector<Position> &positions);
	~Model();

	double hit(double tmin, double tmax, const Primitive*& hitPrimitive, Position& hitPos, const Ray & ray, const Position & modelPos);
};

#endif
