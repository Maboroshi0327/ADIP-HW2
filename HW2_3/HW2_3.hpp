#ifndef _HW2_3_
#define _HW2_3_

#include <string>
#include <iomanip>
#include <iostream>
#include <cstdint>
#include <cmath>
#include "../HW2_1/HW2_1.hpp"

using namespace std;

void HW2_3();

void quantize(uint8_t** input_img, int row, int column, uint8_t** output_img, int bits);

#endif /* _HW2_3_ */
