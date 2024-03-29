#include "Test.h"

void Test::testImagesLoad()
{
	Texture backgroundImg;
	Texture obstacleImg;

	if (backgroundImg.loadFromFile("background.png") && obstacleImg.loadFromFile("OIP.png"))
	{
		cout << "Images load test successful " << endl;
	}
	else
	{
		cout << "Image load test failed!!! " << endl;
	}
	
}

