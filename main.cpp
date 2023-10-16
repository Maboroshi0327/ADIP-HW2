#include <iostream>
#include "HW2_1/HW2_1.hpp"
#include "HW2_2/HW2_2.hpp"
#include "HW2_3/HW2_3.hpp"
#include "HW2_4/HW2_4.hpp"

using namespace std;

int main()
{
	char cmd_input = 0;

	while (cmd_input != 'q')
	{
		cout << "1: 1_1 anwser\n"
			<< "2: 1_2 anwser\n"
			<< "3: 1_3 anwser\n"
			<< "4: 1_4 anwser\n"
			<< "5: 1_5 anwser\n"
			<< "6: 2_1 anwser\n"
			<< "7: 2_2 anwser\n"
			<< "8: 2_3 anwser\n"
			<< "9: 3 anwser\n"
			<< "a: 4 anwser\n"
			<< "q: quit\n"
			<< "Enter the question number to select output result: ";
		cin >> cmd_input;

		switch (cmd_input)
		{
		case '1':
			HW2_1_1();
			break;

		case '2':
			HW2_1_2();
			break;

		case '3':
			HW2_1_3();
			break;

		case '4':
			HW2_1_4();
			break;

		case '5':
			HW2_1_5();
			break;

		case '6':
			HW2_2_1();
			break;

		case '7':
			HW2_2_2();
			break;

		case '8':
			HW2_2_3();
			break;

		case '9':
			HW2_3();
			break;

		case 'a':
			HW2_4();
			break;
		}

		cout << endl << endl;
	}
}
