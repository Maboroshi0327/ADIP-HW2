#include "HW2_2.hpp"

void HW2_2_1()
{
	uint8_t v[3] = { 72, 145, 218 };
	uint8_t** map10x10 = nullptr, ** hw2_2_1_D4 = nullptr, ** hw2_2_1_D8 = nullptr, ** hw2_2_1_Dm = nullptr;
	new_array(map10x10, 10, 10);
	new_array(hw2_2_1_D4, 10, 10);
	new_array(hw2_2_1_D8, 10, 10);
	new_array(hw2_2_1_Dm, 10, 10);

	open_img("map10x10.raw", 10, 10, map10x10);

	cout << "Gray-value of the road {72}:" << endl;
	Distance dis;
	dis.set_Image(map10x10, 10, 10);
	dis.set_StartEnd(0, 0, 9, 9);
	dis.set_GrayLevelValue(v, 1);

	dis.distance(Distance_type::D4);
	dis.draw_Picture(hw2_2_1_D4);
	dis.print_PathDistance();

	dis.distance(Distance_type::D8);
	dis.draw_Picture(hw2_2_1_D8);
	dis.print_PathDistance();

	dis.distance(Distance_type::Dm);
	dis.draw_Picture(hw2_2_1_Dm);
	dis.print_PathDistance();

	save_img("hw2_2_1_D4.raw", 10, 10, hw2_2_1_D4);
	save_img("hw2_2_1_D8.raw", 10, 10, hw2_2_1_D8);
	save_img("hw2_2_1_Dm.raw", 10, 10, hw2_2_1_Dm);

	delete_array(map10x10, 10, 10);
	delete_array(hw2_2_1_D4, 10, 10);
	delete_array(hw2_2_1_D8, 10, 10);
	delete_array(hw2_2_1_Dm, 10, 10);
}

void HW2_2_2()
{
	uint8_t v[3] = { 72, 145, 218 };
	uint8_t** map10x10 = nullptr, ** hw2_2_2_D4 = nullptr, ** hw2_2_2_D8 = nullptr, ** hw2_2_2_Dm = nullptr;
	new_array(map10x10, 10, 10);
	new_array(hw2_2_2_D4, 10, 10);
	new_array(hw2_2_2_D8, 10, 10);
	new_array(hw2_2_2_Dm, 10, 10);

	open_img("map10x10.raw", 10, 10, map10x10);

	cout << "Gray-value of the road {72,145}:" << endl;
	Distance dis;
	dis.set_Image(map10x10, 10, 10);
	dis.set_StartEnd(0, 0, 9, 9);
	dis.set_GrayLevelValue(v, 2);

	dis.distance(Distance_type::D4);
	dis.draw_Picture(hw2_2_2_D4);
	dis.print_PathDistance();

	dis.distance(Distance_type::D8);
	dis.draw_Picture(hw2_2_2_D8);
	dis.print_PathDistance();

	dis.distance(Distance_type::Dm);
	dis.draw_Picture(hw2_2_2_Dm);
	dis.print_PathDistance();

	save_img("hw2_2_2_D4.raw", 10, 10, hw2_2_2_D4);
	save_img("hw2_2_2_D8.raw", 10, 10, hw2_2_2_D8);
	save_img("hw2_2_2_Dm.raw", 10, 10, hw2_2_2_Dm);

	delete_array(map10x10, 10, 10);
	delete_array(hw2_2_2_D4, 10, 10);
	delete_array(hw2_2_2_D8, 10, 10);
	delete_array(hw2_2_2_Dm, 10, 10);
}

void HW2_2_3()
{
	uint8_t v[3] = { 72, 145, 218 };
	uint8_t** map10x10 = nullptr, ** hw2_2_3_D4 = nullptr, ** hw2_2_3_D8 = nullptr, ** hw2_2_3_Dm = nullptr;
	new_array(map10x10, 10, 10);
	new_array(hw2_2_3_D4, 10, 10);
	new_array(hw2_2_3_D8, 10, 10);
	new_array(hw2_2_3_Dm, 10, 10);

	open_img("map10x10.raw", 10, 10, map10x10);

	cout << "Gray-value of the road {72,145}:" << endl;
	Distance dis;
	dis.set_Image(map10x10, 10, 10);
	dis.set_StartEnd(0, 0, 9, 9);
	dis.set_GrayLevelValue(v, 3);

	dis.distance(Distance_type::D4);
	dis.draw_Picture(hw2_2_3_D4);
	dis.print_PathDistance();

	dis.distance(Distance_type::D8);
	dis.draw_Picture(hw2_2_3_D8);
	dis.print_PathDistance();

	dis.distance(Distance_type::Dm);
	dis.draw_Picture(hw2_2_3_Dm);
	dis.print_PathDistance();

	save_img("hw2_2_3_D4.raw", 10, 10, hw2_2_3_D4);
	save_img("hw2_2_3_D8.raw", 10, 10, hw2_2_3_D8);
	save_img("hw2_2_3_Dm.raw", 10, 10, hw2_2_3_Dm);

	delete_array(map10x10, 10, 10);
	delete_array(hw2_2_3_D4, 10, 10);
	delete_array(hw2_2_3_D8, 10, 10);
	delete_array(hw2_2_3_Dm, 10, 10);
}

Coordinate::Coordinate()
{
	row = 0;
	column = 0;
}

Coordinate::Coordinate(int row, int column)
{
	Coordinate::row = row;
	Coordinate::column = column;
}

Coordinate Coordinate::operator=(const Coordinate& other)
{
	Coordinate::row = other.row;
	Coordinate::column = other.column;
	return *this;
}

bool Coordinate::operator==(const Coordinate& other)
{
	bool result = Coordinate::row == other.row;
	result &= Coordinate::column == other.column;
	return result;
}

bool Coordinate::operator!=(const Coordinate& other)
{
	bool result = Coordinate::row != other.row;
	result |= Coordinate::column != other.column;
	return result;
}

Node::Node()
{
	Node::coord.row = 0;
	Node::coord.column = 0;
	Node::parent = nullptr;
}

Node::Node(Coordinate coord, Node* parent)
{
	Node::coord = coord;
	Node::parent = parent;
}

void Distance::set_Image(uint8_t** img, int row, int column)
{
	Distance::img = img;
	Distance::img_row = row;
	Distance::img_column = column;
}

void Distance::set_StartEnd(int start_r, int start_c, int end_r, int end_c)
{
	Distance::start.row = start_r;
	Distance::start.column = start_c;
	Distance::end.row = end_r;
	Distance::end.column = end_c;
}

void Distance::set_GrayLevelValue(uint8_t* v, int amount)
{
	Distance::v.clear();
	Distance::v.shrink_to_fit();
	for (int i = 0; i < amount; i++)
		Distance::v.push_back(v[i]);
}

// Breadth-first Search
void Distance::distance(Distance_type type)
{
	Distance::type = type;

	// create a queue q
	queue<Node> q;

	// create a list visited
	list<Node> visited;

	// enqueue start onto q
	// mark start as visited
	q.push(Node(start, nullptr));
	visited.push_back(Node(start, nullptr));

	// while q is not empty and not find end
	bool find_flag = false;
	while (q.empty() == false && find_flag == false)
	{
		// dequeue a vertex from q into node
		Node node = q.front();
		q.pop();

		// find node's parent
		Coordinate parent;
		if (node.parent != nullptr)
			parent = node.parent->coord;
		else
			parent = Coordinate(0, 0);

		// for each i adjacent to node
		for (auto i : Distance::adjacency(parent, node.coord, type))
		{
			bool visited_flag = false;
			for (auto j : visited)
				if (j.coord == i)
				{
					visited_flag = true;
					break;
				}

			// if i unvisited 
			if (visited_flag == false)
			{
				// find node's memory address on visited
				Node* parent = nullptr;
				for (auto& j : visited)
					if (j.coord == node.coord)
					{
						parent = &j;
						break;
					}

				// mark i as visited
				visited.push_back(Node(i, parent));

				// if find end
				if (i == Distance::end)
				{
					find_flag = true;
					break;
				}
				// enqueue i onto q
				else
					q.push(Node(i, parent));
			}
		}
	}

	// use Node's element "parent" to make the shortest paths
	// visited.back() --> .... --> start
	Distance::path.clear();
	Distance::path.shrink_to_fit();
	Node path = visited.back();
	while (true)
	{
		Distance::path.push_back(path.coord);
		if (path.parent == nullptr)
			break;
		path = *path.parent;
	}
}

void Distance::draw_Picture(uint8_t** output_img)
{
	for (int r = 0; r < Distance::img_row; r++)
		for (int c = 0; c < Distance::img_column; c++)
			output_img[r][c] = 0;
	for (auto i : Distance::path)
		output_img[i.row][i.column] = 255;
}

void Distance::print_PathDistance()
{
	string str;
	if (Distance::type == Distance_type::D4)
		str = "D4";
	else if (Distance::type == Distance_type::D8)
		str = "D8";
	else
		str = "Dm";

	if (Distance::path.front() != Distance::end)
		cout << str << " Path doesn't exist." << endl;
	else
		cout << str << " distance: " << Distance::path.size() - 1 << endl;
}

vector<Coordinate> Distance::adjacency(Coordinate parent, Coordinate coord, Distance_type type)
{
	bool direction[8];
	Coordinate next[8];
	vector<Coordinate> adj;
	switch (type)
	{
	case Distance_type::D4:
		next[0].row = coord.row - 1;
		next[0].column = coord.column;
		direction[0] = (0 <= next[0].row);

		next[1].row = coord.row + 1;
		next[1].column = coord.column;
		direction[1] = (next[1].row < Distance::img_row);

		next[2].row = coord.row;
		next[2].column = coord.column - 1;
		direction[2] = (0 <= next[2].column);

		next[3].row = coord.row;
		next[3].column = coord.column + 1;
		direction[3] = (next[3].column < Distance::img_column);

		for (int i = 0; i < 4; i++)
		{
			if (next[i] == parent)
				continue;

			if (direction[i])
				for (auto j : Distance::v)
					if (Distance::img[next[i].row][next[i].column] == j)
					{
						adj.push_back(next[i]);
						break;
					}
		}
		break;

	case Distance_type::D8:
		next[0].row = coord.row - 1;
		next[0].column = coord.column;
		direction[0] = (0 <= next[0].row);

		next[1].row = coord.row + 1;
		next[1].column = coord.column;
		direction[1] = (next[1].row < Distance::img_row);

		next[2].row = coord.row;
		next[2].column = coord.column - 1;
		direction[2] = (0 <= next[2].column);

		next[3].row = coord.row;
		next[3].column = coord.column + 1;
		direction[3] = (next[3].column < Distance::img_column);

		next[4].row = coord.row - 1;
		next[4].column = coord.column - 1;
		direction[4] = (0 <= next[4].row && 0 <= next[4].column);

		next[5].row = coord.row - 1;
		next[5].column = coord.column + 1;
		direction[5] = (0 <= next[5].row && next[5].column < Distance::img_column);

		next[6].row = coord.row + 1;
		next[6].column = coord.column - 1;
		direction[6] = (next[6].row < Distance::img_row && 0 <= next[6].column);

		next[7].row = coord.row + 1;
		next[7].column = coord.column + 1;
		direction[7] = (next[7].row < Distance::img_row && next[7].column < Distance::img_column);

		for (int i = 0; i < 8; i++)
		{
			if (next[i] == parent)
				continue;

			if (direction[i])
				for (auto j : Distance::v)
					if (Distance::img[next[i].row][next[i].column] == j)
					{
						adj.push_back(next[i]);
						break;
					}
		}
		break;

	case Distance_type::Dm:
		bool Dm_flag = false;
		next[0].row = coord.row - 1;
		next[0].column = coord.column;
		direction[0] = (0 <= next[0].row);
		next[1].row = coord.row + 1;
		next[1].column = coord.column;
		direction[1] = (next[1].row < Distance::img_row);
		next[2].row = coord.row;
		next[2].column = coord.column - 1;
		direction[2] = (0 <= next[2].column);
		next[3].row = coord.row;
		next[3].column = coord.column + 1;
		direction[3] = (next[3].column < Distance::img_column);
		for (int i = 0; i < 4; i++)
		{
			if (next[i] == parent)
				continue;

			if (direction[i])
				for (auto j : Distance::v)
					if (Distance::img[next[i].row][next[i].column] == j)
					{
						adj.push_back(next[i]);
						Dm_flag = true;
						break;
					}
		}

		if (Dm_flag == false)
		{
			next[0].row = coord.row - 1;
			next[0].column = coord.column - 1;
			direction[0] = (0 <= next[0].row && 0 <= next[0].column);
			next[1].row = coord.row - 1;
			next[1].column = coord.column + 1;
			direction[1] = (0 <= next[1].row && next[1].column < Distance::img_column);
			next[2].row = coord.row + 1;
			next[2].column = coord.column - 1;
			direction[2] = (next[2].row < Distance::img_row && 0 <= next[2].column);
			next[3].row = coord.row + 1;
			next[3].column = coord.column + 1;
			direction[3] = (next[3].row < Distance::img_row && next[3].column < Distance::img_column);
			for (int i = 0; i < 4; i++)
			{
				if (next[i] == parent)
					continue;

				if (direction[i])
					for (auto j : Distance::v)
						if (Distance::img[next[i].row][next[i].column] == j)
						{
							adj.push_back(next[i]);
							break;
						}
			}
		}
		break;
	}

	return adj;
}
