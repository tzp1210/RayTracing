#ifndef FRAME_H
#define FRAME_H

#include "Vector.h"
#include "Position.h"

class Frame
{
private:
	Position m_position;
	Vector m_u;
	Vector m_v;
	Vector m_w;

public:
	Frame(const Position &position, const Vector &u, const Vector &v, const Vector &w);
	Frame(const Position &position, const Vector &eyeDirection, const Vector &up);
	~Frame() = default;
	Frame(const Frame &c) = default;

	Vector getU() const { return m_u; }
	Vector getV() const { return m_v; }
	Vector getW() const { return m_w; }
	Position getPosition() const { return m_position; }
};

#endif
