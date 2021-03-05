#include "vector"
#include "string"
#include "math.h"

using namespace std;

class Solution {
public:
	int inline min(int x, int y) {
		if (x > y)return y;
		return x;
	};
	int maximalSquare(vector<vector<char>>& matrix) {
		int height = matrix.size();

		if (height == 0)return 0;

		int width = matrix[0].size();

		auto bp = new int* [height];

		for (size_t i = 0; i < height; i++)
		{
			bp[i] = new int[width] {0};
			for (size_t j = 0; j < width; j++)
			{
				if (matrix[i][j] == '1') {
					bp[i][j] = 1;
				}
				else {
					bp[i][j] = 0;
				}
			}
		}

		int max_area = 0;

		for (size_t i = 1; i < height; i++)
		{
			for (size_t j = 1; j < width; j++)
			{
				if (bp[i][j] == 0) {
					continue;
				}

				bp[i][j] = min(bp[i - 1][j - 1], min(bp[i][j - 1], bp[i - 1][j])) + 1;
			}
		}

		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				if (max_area < bp[i][j]) {
					max_area = bp[i][j];
				}
			}
		}
		return max_area * max_area;
	}
};

void main() {
	Solution s;

	const int c = 5;
	string buf[c + 100];

	buf[0] = "0001";
	buf[1] = "1101";
	buf[2] = "1111";
	buf[3] = "0111";
	buf[4] = "0111";

	/*buf[0] = "000001";
	buf[1] = "111101";
	buf[2] = "111111";
	buf[2] = "111111";
	buf[3] = "011111";
	buf[4] = "011111";*/

	vector<vector<char>> input;

	for (int i = 0; i < c; i++) {
		vector<char> v;

		for (size_t j = 0; j < buf[i].size(); j++)
		{
			v.push_back(buf[i][j]);
		}

		input.push_back(v);
	}

	s.maximalSquare(input);

}