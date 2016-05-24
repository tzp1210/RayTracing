#ifndef LIGHT_H
#define LIGHT_H

#include "Position.h"
#include "Vector.h"

class Light
{
private:
	Position m_pos;
	Color m_lightColor; //TODO: ‘›«“√ª”√…œ
	Vector m_ambient;
	Vector m_diffuse;
	Vector m_specular;

public:
	Light(Position pos, Color lightColor, Vector ambient, Vector diffuse, Vector specular);

	Position getPosition() const { return m_pos; }
	Vector getAmbient() const { return m_ambient; }
	Vector getDiffuse() const { return m_diffuse; }
	Vector getSpecular() const { return m_specular; }
};

#endif
