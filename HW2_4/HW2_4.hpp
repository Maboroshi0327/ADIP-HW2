#ifndef _HW2_4_
#define _HW2_4_

#include <cmath>
#include "../HW2_1/HW2_1.hpp"
#include "../HW2_2/HW2_2.hpp"

#include <opencv2\opencv.hpp>
using namespace cv;

void HW2_4();

int average(uint8_t** img, int row, int column);
Coordinate circle_Center(Coordinate upperLeft);
int circle_Radius(int avg);
void plot_Circle(Mat& img, Coordinate upperLeft, int avg);

#endif /* _HW2_4_ */
