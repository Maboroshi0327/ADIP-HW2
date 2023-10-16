#include "HW2_1.hpp"

void HW2_1_1()
{
	uint8_t** lena256 = nullptr, ** lena512 = nullptr, ** hw2_1_1 = nullptr;
	new_array(lena256, 256, 256);
	new_array(lena512, 512, 512);
	new_array(hw2_1_1, 512, 512);

	open_img("lena256.raw", 256, 256, lena256);
	open_img("lena512.raw", 512, 512, lena512);

	row_column_replication(lena256, 256, 256, 2, hw2_1_1);
	double mse_v = mse(lena512, hw2_1_1, 512, 512);
	double psnr_v = psnr(hw2_1_1, 512, 512, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;

	save_img("hw2_1_1.raw", 512, 512, hw2_1_1);

	delete_array(lena256, 256, 256);
	delete_array(lena512, 512, 512);
	delete_array(hw2_1_1, 512, 512);
}

void HW2_1_2()
{
	uint8_t** lena512 = nullptr, ** lena512_blur = nullptr, ** hw2_1_2 = nullptr, ** hw2_1_2_blur = nullptr;
	new_array(lena512, 512, 512);
	new_array(lena512_blur, 512, 512);
	new_array(hw2_1_2, 128, 128);
	new_array(hw2_1_2_blur, 128, 128);

	open_img("lena512.raw", 512, 512, lena512);
	open_img("lena512.raw", 512, 512, lena512_blur);

	blur(lena512_blur, 512, 512, 3);
	row_column_deletion(lena512, 512, 512, 4, hw2_1_2);
	row_column_deletion(lena512_blur, 512, 512, 4, hw2_1_2_blur);

	save_img("hw2_1_2.raw", 128, 128, hw2_1_2);
	save_img("hw2_1_2_blur.raw", 128, 128, hw2_1_2_blur);

	delete_array(lena512, 512, 512);
	delete_array(lena512_blur, 512, 512);
	delete_array(hw2_1_2, 128, 128);
	delete_array(hw2_1_2_blur, 128, 128);
}

void HW2_1_3()
{
	uint8_t** lena128 = nullptr, ** lena256 = nullptr, ** lena512 = nullptr;
	uint8_t** hw2_1_3_256_nearest = nullptr, ** hw2_1_3_512_nearest = nullptr;
	uint8_t** hw2_1_3_256_bilinear = nullptr, ** hw2_1_3_512_bilinear = nullptr;
	uint8_t** hw2_1_3_256_bicubic = nullptr, ** hw2_1_3_512_bicubic = nullptr;
	new_array(lena128, 128, 128);
	new_array(lena256, 256, 256);
	new_array(lena512, 512, 512);
	new_array(hw2_1_3_256_nearest, 256, 256);
	new_array(hw2_1_3_512_nearest, 512, 512);
	new_array(hw2_1_3_256_bilinear, 256, 256);
	new_array(hw2_1_3_512_bilinear, 512, 512);
	new_array(hw2_1_3_256_bicubic, 256, 256);
	new_array(hw2_1_3_512_bicubic, 512, 512);

	open_img("lena128.raw", 128, 128, lena128);
	open_img("lena256.raw", 256, 256, lena256);
	open_img("lena512.raw", 512, 512, lena512);

	double exe_time = nearest_neighbor(lena128, 128, 128, hw2_1_3_256_nearest, 256, 256);
	double mse_v = mse(lena256, hw2_1_3_256_nearest, 256, 256);
	double psnr_v = psnr(hw2_1_3_256_nearest, 256, 256, 255, mse_v);
	cout << "------------" << " lena128 to 256*256 nearest neighbor " << "------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = nearest_neighbor(lena128, 128, 128, hw2_1_3_512_nearest, 512, 512);
	mse_v = mse(lena512, hw2_1_3_512_nearest, 512, 512);
	psnr_v = psnr(hw2_1_3_512_nearest, 512, 512, 255, mse_v);
	cout << "------------" << " lena128 to 512*512 nearest neighbor " << "------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bilinear(lena128, 128, 128, hw2_1_3_256_bilinear, 256, 256);
	mse_v = mse(lena256, hw2_1_3_256_bilinear, 256, 256);
	psnr_v = psnr(hw2_1_3_256_bilinear, 256, 256, 255, mse_v);
	cout << "----------------" << " lena128 to 256*256 bilinear " << "----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bilinear(lena128, 128, 128, hw2_1_3_512_bilinear, 512, 512);
	mse_v = mse(lena512, hw2_1_3_512_bilinear, 512, 512);
	psnr_v = psnr(hw2_1_3_512_bilinear, 512, 512, 255, mse_v);
	cout << "----------------" << " lena128 to 512*512 bilinear " << "----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bicubic(lena128, 128, 128, hw2_1_3_256_bicubic, 256, 256);
	mse_v = mse(lena256, hw2_1_3_256_bicubic, 256, 256);
	psnr_v = psnr(hw2_1_3_256_bicubic, 256, 256, 255, mse_v);
	cout << "----------------" << " lena128 to 256*256 bicubic " << "-----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bicubic(lena128, 128, 128, hw2_1_3_512_bicubic, 512, 512);
	mse_v = mse(lena512, hw2_1_3_512_bicubic, 512, 512);
	psnr_v = psnr(hw2_1_3_512_bicubic, 512, 512, 255, mse_v);
	cout << "----------------" << " lena128 to 512*512 bicubic " << "-----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	cout << "-------------------------------------------------------------" << endl;
	save_img("hw2_1_3_256_nearest.raw", 256, 256, hw2_1_3_256_nearest);
	save_img("hw2_1_3_512_nearest.raw", 512, 512, hw2_1_3_512_nearest);
	save_img("hw2_1_3_256_bilinear.raw", 256, 256, hw2_1_3_256_bilinear);
	save_img("hw2_1_3_512_bilinear.raw", 512, 512, hw2_1_3_512_bilinear);
	save_img("hw2_1_3_256_bicubic.raw", 256, 256, hw2_1_3_256_bicubic);
	save_img("hw2_1_3_512_bicubic.raw", 512, 512, hw2_1_3_512_bicubic);

	delete_array(lena128, 128, 128);
	delete_array(lena256, 256, 256);
	delete_array(lena512, 512, 512);
	delete_array(hw2_1_3_256_nearest, 256, 256);
	delete_array(hw2_1_3_512_nearest, 512, 512);
	delete_array(hw2_1_3_256_bilinear, 256, 256);
	delete_array(hw2_1_3_512_bilinear, 512, 512);
	delete_array(hw2_1_3_256_bicubic, 256, 256);
	delete_array(hw2_1_3_512_bicubic, 512, 512);
}

void HW2_1_4()
{
	uint8_t** lena512 = nullptr, ** lena384_lanczos = nullptr;
	uint8_t** hw2_1_4_384_nearest = nullptr, ** hw2_1_4_384_bilinear = nullptr, ** hw2_1_4_384_bicubic = nullptr;
	new_array(lena512, 512, 512);
	new_array(lena384_lanczos, 384, 384);
	new_array(hw2_1_4_384_nearest, 384, 384);
	new_array(hw2_1_4_384_bilinear, 384, 384);
	new_array(hw2_1_4_384_bicubic, 384, 384);

	open_img("lena512.raw", 512, 512, lena512);
	open_img("lena384_lanczos.raw", 384, 384, lena384_lanczos);

	blur(lena512, 512, 512, 3);

	double exe_time = nearest_neighbor(lena512, 512, 512, hw2_1_4_384_nearest, 384, 384);
	double mse_v = mse(lena384_lanczos, hw2_1_4_384_nearest, 384, 384);
	double psnr_v = psnr(hw2_1_4_384_nearest, 384, 384, 255, mse_v);
	cout << "------------" << " lena512 to 384*384 nearest neighbor " << "------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bilinear(lena512, 512, 512, hw2_1_4_384_bilinear, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_4_384_bilinear, 384, 384);
	psnr_v = psnr(hw2_1_4_384_bilinear, 384, 384, 255, mse_v);
	cout << "----------------" << " lena512 to 384*384 bilinear " << "----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	exe_time = bicubic(lena512, 512, 512, hw2_1_4_384_bicubic, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_4_384_bicubic, 384, 384);
	psnr_v = psnr(hw2_1_4_384_bicubic, 384, 384, 255, mse_v);
	cout << "----------------" << " lena512 to 384*384 bicubic " << "-----------------" << endl;
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	cout << "-------------------------------------------------------------" << endl;
	save_img("hw2_1_4_384_nearest.raw", 384, 384, hw2_1_4_384_nearest);
	save_img("hw2_1_4_384_bilinear.raw", 384, 384, hw2_1_4_384_bilinear);
	save_img("hw2_1_4_384_bicubic.raw", 384, 384, hw2_1_4_384_bicubic);

	delete_array(lena512, 512, 512);
	delete_array(lena384_lanczos, 384, 384);
	delete_array(hw2_1_4_384_nearest, 384, 384);
	delete_array(hw2_1_4_384_bilinear, 384, 384);
	delete_array(hw2_1_4_384_bicubic, 384, 384);
}

void HW2_1_5()
{
	uint8_t** lena256 = nullptr, ** lena384_lanczos = nullptr;
	uint8_t** hw2_1_5_1_nearest = nullptr, ** hw2_1_5_1_bilinear = nullptr, ** hw2_1_5_1_bicubic = nullptr;
	uint8_t** hw2_1_5_2_nearest = nullptr, ** hw2_1_5_2_bilinear = nullptr, ** hw2_1_5_2_bicubic = nullptr;
	uint8_t** hw2_1_5_3_nearest = nullptr, ** hw2_1_5_3_bilinear = nullptr, ** hw2_1_5_3_bicubic = nullptr;
	uint8_t** temp_576 = nullptr, ** temp_171 = nullptr;
	new_array(lena256, 256, 256);
	new_array(lena384_lanczos, 384, 384);
	new_array(hw2_1_5_1_nearest, 384, 384); new_array(hw2_1_5_1_bilinear, 384, 384); new_array(hw2_1_5_1_bicubic, 384, 384);
	new_array(hw2_1_5_2_nearest, 384, 384); new_array(hw2_1_5_2_bilinear, 384, 384); new_array(hw2_1_5_2_bicubic, 384, 384);
	new_array(hw2_1_5_3_nearest, 384, 384); new_array(hw2_1_5_3_bilinear, 384, 384); new_array(hw2_1_5_3_bicubic, 384, 384);
	new_array(temp_576, 576, 576);
	new_array(temp_171, 171, 171);

	open_img("lena256.raw", 256, 256, lena256);
	open_img("lena384_lanczos.raw", 384, 384, lena384_lanczos);

	cout << "---------------------" << " lena256 ¡ô2.25¡õ1.5 " << "---------------------" << endl;
	cout << "----------" << " nearest neighbor " << "----------" << endl;
	double exe_time = nearest_neighbor(lena256, 256, 256, temp_576, 576, 576);
	exe_time += nearest_neighbor(temp_576, 576, 576, hw2_1_5_1_nearest, 384, 384);
	double mse_v = mse(lena384_lanczos, hw2_1_5_1_nearest, 384, 384);
	double psnr_v = psnr(hw2_1_5_1_nearest, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bilinear " << "--------------" << endl;
	exe_time = bilinear(lena256, 256, 256, temp_576, 576, 576);
	exe_time += bilinear(temp_576, 576, 576, hw2_1_5_1_bilinear, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_1_bilinear, 384, 384);
	psnr_v = psnr(hw2_1_5_1_bilinear, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bicubic " << "---------------" << endl;
	exe_time = bicubic(lena256, 256, 256, temp_576, 576, 576);
	exe_time += bicubic(temp_576, 576, 576, hw2_1_5_1_bicubic, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_1_bicubic, 384, 384);
	psnr_v = psnr(hw2_1_5_1_bicubic, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	cout << "---------------------" << " lena256 ¡õ1.5¡ô2.25 " << "---------------------" << endl;
	cout << "----------" << " nearest neighbor " << "----------" << endl;
	exe_time = nearest_neighbor(lena256, 256, 256, temp_171, 171, 171);
	exe_time += nearest_neighbor(temp_171, 171, 171, hw2_1_5_2_nearest, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_2_nearest, 384, 384);
	psnr_v = psnr(hw2_1_5_2_nearest, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bilinear " << "--------------" << endl;
	exe_time = bilinear(lena256, 256, 256, temp_171, 171, 171);
	exe_time += bilinear(temp_171, 171, 171, hw2_1_5_2_bilinear, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_2_bilinear, 384, 384);
	psnr_v = psnr(hw2_1_5_2_bilinear, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bicubic " << "---------------" << endl;
	exe_time = bicubic(lena256, 256, 256, temp_171, 171, 171);
	exe_time += bicubic(temp_171, 171, 171, hw2_1_5_2_bicubic, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_2_bicubic, 384, 384);
	psnr_v = psnr(hw2_1_5_2_bicubic, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	cout << "-----------------------" << " lena256 ¡ô1.5 " << "------------------------" << endl;
	cout << "----------" << " nearest neighbor " << "----------" << endl;
	exe_time = nearest_neighbor(lena256, 256, 256, hw2_1_5_3_nearest, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_3_nearest, 384, 384);
	psnr_v = psnr(hw2_1_5_3_nearest, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bilinear " << "--------------" << endl;
	exe_time = bilinear(lena256, 256, 256, hw2_1_5_3_bilinear, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_3_bilinear, 384, 384);
	psnr_v = psnr(hw2_1_5_3_bilinear, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;
	cout << "--------------" << " bicubic " << "---------------" << endl;
	exe_time = bicubic(lena256, 256, 256, hw2_1_5_3_bicubic, 384, 384);
	mse_v = mse(lena384_lanczos, hw2_1_5_3_bicubic, 384, 384);
	psnr_v = psnr(hw2_1_5_3_bicubic, 384, 384, 255, mse_v);
	cout << "MSE: " << mse_v << endl;
	cout << "PSNR: " << psnr_v << endl;
	cout << "Execution time: " << exe_time << "ms" << endl;

	cout << "-------------------------------------------------------------" << endl;
	save_img("hw2_1_5_1_nearest.raw", 384, 384, hw2_1_5_1_nearest);
	save_img("hw2_1_5_1_bilinear.raw", 384, 384, hw2_1_5_1_bilinear);
	save_img("hw2_1_5_1_bicubic.raw", 384, 384, hw2_1_5_1_bicubic);
	save_img("hw2_1_5_2_nearest.raw", 384, 384, hw2_1_5_2_nearest);
	save_img("hw2_1_5_2_bilinear.raw", 384, 384, hw2_1_5_2_bilinear);
	save_img("hw2_1_5_2_bicubic.raw", 384, 384, hw2_1_5_2_bicubic);
	save_img("hw2_1_5_3_nearest.raw", 384, 384, hw2_1_5_3_nearest);
	save_img("hw2_1_5_3_bilinear.raw", 384, 384, hw2_1_5_3_bilinear);
	save_img("hw2_1_5_3_bicubic.raw", 384, 384, hw2_1_5_3_bicubic);

	delete_array(lena256, 256, 256);
	delete_array(lena384_lanczos, 384, 384);
	delete_array(hw2_1_5_1_nearest, 384, 384);
	delete_array(hw2_1_5_2_nearest, 384, 384);
	delete_array(hw2_1_5_3_nearest, 384, 384);
	delete_array(temp_576, 576, 576);
	delete_array(temp_171, 171, 171);
}

void new_array(uint8_t**& img, int row, int column)
{
	img = new uint8_t * [row];
	for (int r = 0; r < row; r++)
		img[r] = new uint8_t[column];
	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			img[r][c] = 0;
}

void delete_array(uint8_t**& img, int row, int column)
{
	for (int r = 0; r < row; r++)
		delete[] img[r];
	delete[] img;
}

void open_img(const char* FileName, int row, int column, uint8_t** img)
{
	int size = row * column;
	uint8_t* buffer = new uint8_t[size];

	FILE* input_file;
	input_file = fopen(FileName, "rb");
	if (input_file == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(buffer, 1, size, input_file);

	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			img[r][c] = buffer[c + r * column];

	delete[] buffer;
	fclose(input_file);
}

void save_img(const char* FileName, int row, int column, uint8_t** img)
{
	int size = row * column;
	uint8_t* buffer = new uint8_t[size];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			buffer[c + r * column] = img[r][c];

	FILE* output_file;
	output_file = fopen(FileName, "wb");
	fwrite(buffer, 1, size, output_file);

	delete[] buffer;
	fclose(output_file);

	cout << "Output file: " << FileName << endl;
}

void row_column_replication(uint8_t** input_img, int row, int column, int ratio, uint8_t** output_img)
{
	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			for (int i = 0; i < ratio; i++)
				for (int j = 0; j < ratio; j++)
					output_img[r * ratio + i][c * ratio + j] = input_img[r][c];
}

void row_column_deletion(uint8_t** input_img, int row, int column, int ratio, uint8_t** output_img)
{
	for (int r = 0; r < row; r += ratio)
		for (int c = 0; c < column; c += ratio)
			output_img[r / ratio][c / ratio] = input_img[r][c];
}

double nearest_neighbor(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out)
{
	auto start = chrono::high_resolution_clock::now();

	for (int r = 0; r < row_out; r++)
	{
		for (int c = 0; c < column_out; c++)
		{
			double r_mapping = (double)r / (row_out - 1) * (row_in - 1);
			double c_mapping = (double)c / (column_out - 1) * (column_in - 1);
			output_img[r][c] = input_img[(int)round(r_mapping)][(int)round(c_mapping)];
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, ratio<1, 1000>> duration = end - start;
	return duration.count();
}

double bilinear(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out)
{
	auto start = chrono::high_resolution_clock::now();

	for (int r = 0; r < row_out; r++)
	{
		for (int c = 0; c < column_out; c++)
		{
			double r_mapping = (double)r / (row_out - 1) * (row_in - 1);
			double c_mapping = (double)c / (column_out - 1) * (column_in - 1);
			double r1 = floor(r_mapping);
			double r2 = r1 + 1;
			double c1 = floor(c_mapping);
			double c2 = c1 + 1;
			double Q_00 = input_img[(int)r1][(int)c1];
			double Q_01 = input_img[(int)r1][(int)(c2 >= column_in ? c1 : c2)];
			double Q_10 = input_img[(int)(r2 >= row_in ? r1 : r2)][(int)c1];
			double Q_11 = input_img[(int)(r2 >= row_in ? r1 : r2)][(int)(c2 >= column_in ? c1 : c2)];

			double P1 = Q_00 * (c2 - c_mapping) + Q_01 * (c_mapping - c1);
			double P2 = Q_10 * (c2 - c_mapping) + Q_11 * (c_mapping - c1);
			output_img[r][c] = (uint8_t)round(P1 * (r2 - r_mapping) + P2 * (r_mapping - r1));
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, ratio<1, 1000>> duration = end - start;
	return duration.count();
}

double bicubic(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int row_out, int column_out)
{
	auto start = chrono::high_resolution_clock::now();

	int pad = 2;
	uint8_t** padding_img = nullptr;
	new_array(padding_img, row_in + 2 * pad, column_in + 2 * pad);
	padding(input_img, row_in, column_in, padding_img, pad);

	for (int r = 0; r < row_out; r++)
	{
		for (int c = 0; c < column_out; c++)
		{
			double r_mapping = (double)r / (row_out - 1) * (row_in - 1) + pad;
			double c_mapping = (double)c / (column_out - 1) * (column_in - 1) + pad;
			double r1 = floor(r_mapping);
			double c1 = floor(c_mapping);

			double sum = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					sum += padding_img[(int)r1 - 1 + i][(int)c1 - 1 + j]
						* bicubic_param(r_mapping - (r1 - 1 + i), -0.5)
						* bicubic_param(c_mapping - (c1 - 1 + j), -0.5);
				}
			}

			output_img[r][c] = (uint8_t)round(sum);
		}
	}

	delete_array(padding_img, row_in + 2 * pad, column_in + 2 * pad);

	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, ratio<1, 1000>> duration = end - start;
	return duration.count();
}

double bicubic_param(double x, double a)
{
	x = abs(x);
	if (x <= 1)
		return (a + 2) * x * x * x - (a + 3) * x * x + 1;
	else if (1 < x && x < 2)
		return a * x * x * x - 5 * a * x * x + 8 * a * x - 4 * a;
	else
		return 0;
}

void blur(uint8_t** img, int row, int column, int mask)
{
	int pad = mask / 2;
	uint8_t** padding_img = nullptr;
	new_array(padding_img, row + 2 * pad, column + 2 * pad);
	padding(img, row, column, padding_img, pad);

	for (int r = pad; r < row + pad; r++)
	{
		for (int c = pad; c < column + pad; c++)
		{
			int sum = 0;
			for (int i = -pad; i <= pad; i++)
			{
				for (int j = -pad; j <= pad; j++)
				{
					sum = sum + padding_img[r + i][c + j];
				}
			}
			img[r - pad][c - pad] = sum / mask / mask;
		}
	}

	delete_array(padding_img, row + 2 * pad, column + 2 * pad);
}

void padding(uint8_t** input_img, int row_in, int column_in, uint8_t** output_img, int pad)
{
	for (int r = 0; r < row_in; r++)
		for (int c = 0; c < column_in; c++)
			output_img[r + pad][c + pad] = input_img[r][c];

	for (int r = 0; r < row_in + pad * 2; r++)
	{
		for (int c = 0; c < column_in + pad * 2; c++)
		{
			if (r < pad && c < pad)
				output_img[r][c] = output_img[2 * pad - 1 - r][2 * pad - 1 - c];
			else if (r < pad && pad <= c && c < column_in + pad)
				output_img[r][c] = output_img[2 * pad - 1 - r][c];
			else if (r < pad && c >= column_in + pad)
				output_img[r][c] = output_img[2 * pad - 1 - r][2 * (column_in + pad) - 1 - c];
			else if (pad <= r && r < row_in + pad && c < pad)
				output_img[r][c] = output_img[r][2 * pad - 1 - c];
			else if (pad <= r && r < row_in + pad && c >= column_in + pad)
				output_img[r][c] = output_img[r][2 * (column_in + pad) - 1 - c];
			else if (r >= row_in + pad && c < pad)
				output_img[r][c] = output_img[2 * (row_in + pad) - 1 - r][2 * pad - 1 - c];
			else if (r >= row_in + pad && pad <= c && c < column_in + pad)
				output_img[r][c] = output_img[2 * (row_in + pad) - 1 - r][c];
			else if (r >= row_in + pad && c >= column_in + pad)
				output_img[r][c] = output_img[2 * (row_in + pad) - 1 - r][2 * (column_in + pad) - 1 - c];
		}
	}
}

double mse(uint8_t** img1, uint8_t** img2, int row, int column)
{
	int size = row * column;
	int sum = 0;
	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			sum = sum + (img1[r][c] - img2[r][c]) * (img1[r][c] - img2[r][c]);
	double value = sum / (double)size;

	return value;
}

double psnr(uint8_t** img, int row, int column, int max, double mse_v)
{
	double value, param;
	param = max * max / mse_v;
	value = 10 * log10(param);

	return value;
}
