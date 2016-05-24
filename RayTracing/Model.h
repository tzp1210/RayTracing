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
	//TODO:�����⣬��������д���������ҽ�ֹModel�ĸ��ƺ͸�ֵ�������Ժ�����ӡ�
	//Model(const Model &c);
	//Model& operator=(const Model&);

public:
	Model() = default;
	Model(std::vector<Primitive*> primitives, const std::vector<Position> &positions);
	~Model();

	double hit(double tmin, double tmax, const Primitive*& hitPrimitive, Position& hitPos, const Ray & ray, const Position & modelPos);
};

#endif
