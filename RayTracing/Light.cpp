#include "Light.h"

Light::Light(Position pos, Color lightColor, Vector ambient, Vector diffuse, Vector specular) :
	m_pos(pos), m_lightColor(lightColor), m_ambient(ambient), m_diffuse(diffuse), m_specular(specular)
{
}
