#pragma once
class Pixel
{
public:
	Pixel(unsigned red, unsigned green, unsigned blue);
	void readPixel();
	void writePixel();
	void setRed(unsigned r);
	void setGreen(unsigned g);
	void setBlue(unsigned b);

	unsigned getRed() const;
	unsigned getGreen() const;
	unsigned getBlue() const;

	void printPixel() const;
private:
	unsigned char red, green, blue;
};

