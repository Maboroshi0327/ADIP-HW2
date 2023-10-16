#include "HW2_4.hpp"

void HW2_4()
{
	uint8_t** lena1024 = nullptr, ** lena1024_halftone = nullptr, ** lena1024_halftone_blur = nullptr;
	uint8_t** img_temp[64][64] = { 0 };
	new_array(lena1024, 1024, 1024);
	new_array(lena1024_halftone, 1024, 1024);
	new_array(lena1024_halftone_blur, 1024, 1024);
	open_img("lena1024.raw", 1024, 1024, lena1024);

	Mat img = Mat::zeros(Size(1024, 1024), CV_8UC3);
	img.setTo(255);

	for (int r = 0; r < 1024; r += 16)
		for (int c = 0; c < 1024; c += 16)
		{
			int avg = average(lena1024, r, c);
			plot_Circle(img, Coordinate(r, c), avg);
		}

	for (int r = 0; r < 1024; r++)
		for (int c = 0; c < 1024; c++)
			lena1024_halftone_blur[r][c] = lena1024_halftone[r][c] = img.at<Vec3b>(r, c)[0];
	blur(lena1024_halftone_blur, 1024, 1024, 13);

	save_img("lena1024_halftone.raw", 1024, 1024, lena1024_halftone);
	save_img("lena1024_halftone_blur.raw", 1024, 1024, lena1024_halftone_blur);

	imshow("lena1024_halftone", img);
	waitKey();

	delete_array(lena1024, 1024, 1024);
	delete_array(lena1024_halftone, 1024, 1024);
	delete_array(lena1024_halftone_blur, 1024, 1024);
}

int average(uint8_t** img, int row, int column)
{
	int avg = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			avg += img[row + i][column + j];
		}
	}
	avg = (int)round((double)avg / 256);

	return avg;
}

Coordinate circle_Center(Coordinate upperLeft)
{
	return Coordinate(upperLeft.row + 7, upperLeft.column + 7);
}

int circle_Radius(int avg)
{
	if (0 <= avg && avg <= 57)
		return 8;
	if (58 <= avg && avg <= 81)
		return 7;
	if (82 <= avg && avg <= 105)
		return 6;
	if (106 <= avg && avg <= 129)
		return 5;
	if (130 <= avg && avg <= 153)
		return 4;
	if (154 <= avg && avg <= 177)
		return 3;
	if (178 <= avg && avg <= 201)
		return 2;
	if (202 <= avg && avg <= 255)
		return 1;
}

void plot_Circle(Mat& img, Coordinate upperLeft, int avg)
{
	Coordinate center = circle_Center(upperLeft);
	int radius = circle_Radius(avg);
	circle(img, Point(center.column, center.row), radius, Scalar(0, 0, 0), FILLED);
}
