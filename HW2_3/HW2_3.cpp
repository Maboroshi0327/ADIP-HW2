#include "HW2_3.hpp"

void HW2_3()
{
	uint8_t** lena256 = nullptr, ** baboon256 = nullptr;
	uint8_t** hw2_3_lena[7], ** hw2_3_baboon[7];
	new_array(lena256, 256, 256);
	new_array(baboon256, 256, 256);
	for (int i = 0; i < 7; i++)
	{
		new_array(hw2_3_lena[i], 256, 256);
		new_array(hw2_3_baboon[i], 256, 256);
	}

	open_img("lena256.raw", 256, 256, lena256);
	open_img("baboon256.raw", 256, 256, baboon256);

	ios state(nullptr);
	state.copyfmt(cout);
	cout << " bit |       |  lena256  |  baboon256  " << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < 7; i++)
	{
		quantize(lena256, 256, 256, hw2_3_lena[i], i + 1);
		quantize(baboon256, 256, 256, hw2_3_baboon[i], i + 1);

		double mse_lena = mse(lena256, hw2_3_lena[i], 256, 256);
		double psnr_lena = psnr(hw2_3_lena[i], 256, 256, 255, mse_lena);
		double mse_baboon = mse(baboon256, hw2_3_baboon[i], 256, 256);
		double psnr_baboon = psnr(hw2_3_baboon[i], 256, 256, 255, mse_baboon);

		cout << "  " << i + 1 << "  |  MSE: |" << setw(9) << mse_lena << "  |" << setw(9) << mse_baboon << endl;
		cout << "     | PSNR: |" << setw(9) << psnr_lena << "  |" << setw(9) << psnr_baboon << endl;
		cout << "-----------------------------------------" << endl;
	}
	cout.copyfmt(state);

	for (int i = 0; i < 7; i++)
	{
		string str_lena = (string)"lena_" + to_string(i + 1) + (string)"bit.raw";
		save_img(str_lena.c_str(), 256, 256, hw2_3_lena[i]);
		string str_baboon = (string)"baboon_" + to_string(i + 1) + (string)"bit.raw";
		save_img(str_baboon.c_str(), 256, 256, hw2_3_baboon[i]);
	}

	delete_array(lena256, 256, 256);
	delete_array(baboon256, 256, 256);
	for (int i = 0; i < 7; i++)
	{
		delete_array(hw2_3_lena[i], 256, 256);
		delete_array(hw2_3_baboon[i], 256, 256);
	}
}

void quantize(uint8_t** input_img, int row, int column, uint8_t** output_img, int bits)
{
	const double pow2_8 = 256;
	const double pow2_bits = pow(2, bits);
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < column; c++)
		{
			double q_value = (input_img[r][c] >> (8 - bits)) / (pow2_bits - 1) * (pow2_8 - 1);
			output_img[r][c] = (uint8_t)round(q_value);
		}
	}
}
