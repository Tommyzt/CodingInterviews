
#include<iostream>
#include<vector>
using namespace std;

/*
因为每一行从左到右递增，每一列从上到下递增。
所以查找一个数num，可以这样做：
首先拿num与右上角的数进行比较。
若相等，则直接返回，找到该数。
若num < 右上角数，则剔除右上角数所在列 col--
若num > 右上角数，则剔除右上角数所在行 row++
*/
class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		bool ans = false;
		int Row_len = array.size();//获取行数
		int Col_len = array[0].size();//获取列数

		if (!array.empty() && Row_len > 0 && Col_len >0)
		{
			int row = 0;//下标从零开始
			int col = Col_len - 1;//同样下标从零开始
			while (row < Row_len && col>= 0) //这里注意 col >= 0，不要漏掉=号
			{
				if (array[row][col] == target)
				{
					ans = true;
					break;
				}
				else if (array[row][col] > target)
					--col;
				else
					++row;
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> arr;

	return 0;
}