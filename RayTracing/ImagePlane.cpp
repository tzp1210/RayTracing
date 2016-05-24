#include "ImagePlane.h"
#include "Constants.h"
#include "Color.h"

ImagePlane::ImagePlane(int pixelWidth, int pixelHeight, double left, double right, double top, double bottom) :
	m_pixelWidth(pixelWidth), m_pixelHeight(pixelHeight), m_left(left), m_right(right), m_top(top), m_bottom(bottom)
{
	m_plane = new Color[ScreenSize::height * ScreenSize::width];
}

ImagePlane::~ImagePlane()
{
	delete[] m_plane;
}


