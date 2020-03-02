//============================================================================
// Name        : MagicSquare.cpp
// Author      : Alex Dinkelacker
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class square {
private:

	vector<vector<int> > values;
	int size;

	void initialize() {
		for (int i = 0; i < size; i++) {
			vector<int> v;
			for (int j = 0; j < size; j++)
				v.push_back(0);

			values.push_back(v);
		}
	}

	void fill() {
		int nextNum = 1;
		int lastNum = size * size;
		int row = 0, column = size / 2;
		int prevRow = 0, prevCol = 0;
		while (nextNum <= lastNum) {
			if (values[row][column] == 0) //not yet filled
					{
				values[row][column] = nextNum;

				nextNum++;

				prevRow = row;
				prevCol = column;

				row--;
				column++;

			} else //go to one row below the previous filled number
			{
				row = prevRow + 1;
				column = prevCol;
			}

			if (row < 0)
				row = size - 1;
			else if (row == size)
				row = 0;

			if (column == size)
				column = 0;
			else if (column < 0)
				column = size - 1;

		}
	}

public:
	square(int n) {
		size = n;
		initialize();
		fill();

	}

	void display() {
		cout << endl << "magic square of size " << size << "x" << size << endl;
		for (int i = 0; i < size; i++) {
			cout << endl;
			for (int j = 0; j < size; j++)
				cout << setw(4) << values[i][j];
		}

		cout << endl;
	}
};

int main() {
	square magic1(5);
	magic1.display();

	square magic2(7);
	magic2.display();

	square magic3(15);
	magic3.display();

}
