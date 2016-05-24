#ifndef IMAGE_PLANE_H
#define IMAGE_PLANE_H

#include "Constants.h"
#include "Color.h"

class ImagePlane
{
private:
	Color *m_plane;
	int m_pixelWidth;
	int m_pixelHeight;
	double m_left, m_right, m_top, m_bottom;

	////TODO:有问题！！！禁止复制和赋值
	//ImagePlane(const ImagePlane&);
	//ImagePlane& operator=(const ImagePlane&);

public:
	ImagePlane(int pixelWidth, int pixelHeight, double left, double right, double top, double bottom);
	~ImagePlane();

	int getPixelWidth() const { return m_pixelWidth; }
	int getPixelHeight() const { return m_pixelHeight; }
	double getLeft() const { return m_left; }
	double getRight() const { return m_right; }
	double getTop() const { return m_top; }
	double getBottom() const { return m_bottom; }

	Color getPixel(const int x, const int y) const { return m_plane[x * m_pixelWidth + y]; } //x行 y列
	void setPixel(const int x, const int y, Color color) { m_plane[x * m_pixelWidth + y] = color; }
};

#endif
