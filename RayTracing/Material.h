#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vector.h"

class Material
{
private:
	Vector m_ambient;
	Vector m_diffuse;
	Vector m_specular;
	double m_shininess;
	bool m_idealSpucular;

public:
	Material(Vector ambient, Vector diffuse, Vector specular, double shininess, bool idealSpecular) :
		m_ambient(ambient), m_diffuse(diffuse), m_specular(specular), m_shininess(shininess), m_idealSpucular(idealSpecular) { }
	~Material() = default;

	Vector getMaterialAmbient() const { return m_ambient; }
	Vector getMaterialDiffuse() const { return m_diffuse; }
	Vector getMaterialSpecular() const { return m_specular; }
	double getMaterialShininess() const { return m_shininess; }
	bool isIdealSpecular() const { return m_idealSpucular; }
};

#endif
