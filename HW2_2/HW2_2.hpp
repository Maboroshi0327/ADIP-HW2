#ifndef _HW2_2_
#define _HW2_2_

#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstdint>
#include "../HW2_1/HW2_1.hpp"

using namespace std;

void HW2_2_1();
void HW2_2_2();
void HW2_2_3();

enum class Distance_type
{
	D4,
	D8,
	Dm
};

class Coordinate
{
public:
	int row;
	int column;
	Coordinate();
	Coordinate(int row, int column);
	Coordinate operator=(const Coordinate& other);
	bool operator==(const Coordinate& other);
	bool operator!=(const Coordinate& other);
};

class Node
{
public:
	Coordinate coord;
	Node* parent;
	Node();
	Node(Coordinate coord, Node* parent);
};

class Distance
{
public:
	vector<Coordinate> path;

	void set_Image(uint8_t** img, int row, int column);
	void set_StartEnd(int start_r, int start_c, int end_r, int end_c);
	void set_GrayLevelValue(uint8_t* v, int amount);
	void distance(Distance_type type);
	void draw_Picture(uint8_t** output_img);
	void print_PathDistance();

private:
	uint8_t** img;
	int img_row, img_column;
	Coordinate start, end;
	vector<uint8_t> v;
	Distance_type type;
	vector<Coordinate> adjacency(Coordinate parent, Coordinate coord, Distance_type type);
};

#endif /* _HW2_2_ */
