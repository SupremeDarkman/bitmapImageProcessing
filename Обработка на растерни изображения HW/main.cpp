#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
enum Commands
{
	LOAD = 1,
	SAVEAS,
	GRAYSACLE,
	MONOCHROME,
	NEGATIVE,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	FLIP_TOP,
	FLIP_LEFT,
	UNDO,
	REDO,
	ADD,
	CROP,
	SAVE,
	LIST_SESSION,
	SESSION_INFO,
	MAKE_COLLAGE_HORIZONTAL,
	MAKE_COLLAGE_VERTICAL,
	EXIT,

};
void menu()
{
	std::cout << "Enter a choice:\n";
	std::cout << "1.Load\n";
	std::cout << "2.Save as\n";
	std::cout << "3.Gray scale\n";
	std::cout << "4.Monochrome\n";
	std::cout << "5.Negative\n";
	std::cout << "6.Rotate left\n";
	std::cout << "7.Rotate right\n";
	std::cout << "8.Flip top\n";
	std::cout << "9.Flip left\n";
	std::cout << "10.Undo\n";
	std::cout << "11.Redo\n";
	std::cout << "12.Add\n";
	std::cout << "13.Crop\n";
	std::cout << "14.Save\n";
	std::cout << "15.List session\n";
	std::cout << "16.Session info\n";
	std::cout << "17.Make collage horizontal\n";
	std::cout << "18.Make collage vertical\n";
	std::cout << "19.Exit\n";
}



bool load()
{
	std::cout << "Enter file name to load: ";
	char* fileName = new char[33];
	std::cin >> fileName;

	std::ifstream image;
	image.open(fileName);

	if (!image.is_open())
	{
		std::cout << "Loading failed\n";
		return false;
	}



	image.close();
}
bool saveAs()
{
	return false;
}
int main()
{
	//menu();
	//int command;
	//std::cin >> command;
	//switch (command)
	//{
	//case Commands::LOAD: load(); break;
	//case Commands::SAVEAS: saveAs(); break;
	//}
	//std::cout << "Enter file name to load: ";
	//char* fileName = new char[33];
	//std::cin >> fileName;
	//std::ofstream draw;
	//draw.open("NEWIMAGE.ppm");
	//draw << "P3" << '\n';
	//draw << "1024 1024" << '\n';
	//draw << "255" << '\n';
	//srand(time(0));

	//for (unsigned y = 0; y < 1024; y++)
	//{
	//	for (unsigned x = 0; x < 1024; x++)
	//	{
	//		draw << rand() % 255 << " " << rand() % 255 << " " << rand() % 255 << '\n';
	//	}
	//}
	//draw.close();

	std::ifstream image;
	std::ofstream newImage;
	image.open("NEWIMAGE.ppm");
	newImage.open("newImages.ppm");

	if (!image.is_open())
	{
		std::cout << "Loading failed\n";
		return -1;
	}
	if (!newImage.is_open())
	{
		image.close();
		std::cout << "Loading failed\n";
		return -1;
	}
	
	std::string type = "", width = "", height = "", RGB = "";
	image >> type;
	image >> width;
	image >> height;
	image >> RGB;

	newImage << type << '\n';
	newImage << width << ' ' << height << '\n';
	newImage << RGB << '\n';

	std::string red = "", green = "", blue = "";
	int r = 0, g = 0, b = 0;
	while (!image.eof())
	{
		image >> red;
		image >> green;
		image >> blue;

		r = atoi(red.c_str());
		g = atoi(green.c_str());
		b = atoi(blue.c_str());

		if (r+50 >= 255)
		{
			r = 255;
		}
		else
		{
			r += 50;
		}
		newImage << r << ' ' << g << ' ' << b << '\n';
	}



	image.close();
	newImage.close();
	return 0;
}