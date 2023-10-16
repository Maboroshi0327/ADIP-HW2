#ifndef _HW2_1_
#define _HW2_1_

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <cmath>
#include <iostream>

using namespace std;

void HW2_1_1();
void HW2_1_2();
void HW2_1_3();
void HW2_1_4();
void HW2_1_5();

void new_array(uint8_t**& img, int row, int column);
void delete_array(uint8_t**& img, int row, int column);
void open_img(const char* FileName, int row, int column, uint8_t** img);
void save_img(const char* FileName, int row, int column, uint8_t** img);
void row_column_replication(uint8_t** input_img, int row, int column, int ratio, uint8_t** output_img);
void row_column_deletion(uint8_t** input_img, int row, int column, int ratio, uint8_t** output_img);
double nearest_neighbor(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out);
double bilinear(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out);
double bicubic(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out);
double bicubic_param(double x, double a);
void blur(uint8_t** img, int row, int column, int mask);
void padding(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int pad);
double mse(uint8_t** img1, uint8_t** img2, int row, int column);
double psnr(uint8_t** img, int row, int column, int max, double mse_v);

#endif /* _HW2_1_ */
