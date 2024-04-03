#pragma once
#include "Pixel.h";
#include <vector>

class Image
{
public:
	Image(int heigt, int width);
	~Image();
	
	Pixel getPixel(int x, int y) const;
	int getHeight() const;
	int getWidth() const;
	
	void setPixel(const Pixel& pixel, int x, int y);
	void setHeight(int heigth);
	void setWidth(int width);

	void export(const char* fileName) const;
	void import(const char* fileName);
private:
	int height;
	int width;
	std::vector<Pixel> pixels;
};

