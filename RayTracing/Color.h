#ifndef COLOR_H
#define COLOR_H

class Vector;

class Color
{
private:
	double m_R;
	double m_G;
	double m_B;

public:
	Color(const double R, const double G, const double B) { m_R = R; m_G = G; m_B = B; }
	Color() : Color(0.0, 0.0, 0.0) { }
	Color(const Vector& c);
	~Color() = default;
	Color(const Color &c) = default;

	double getR() const { return m_R; }
	double getG() const { return m_G; }
	double getB() const { return m_B; }
	void getRGB(double &R, double &G, double &B) const { R = m_R; G = m_G; B = m_B; }

	void setR(const double R) { m_R = R; }
	void setG(const double G) { m_G = G; }
	void setB(const double B) { m_B = B; }
	void setRGB(const double R, const double G, const double B) { m_R = R; m_G = G; m_B = B; }
};

#endif
