#include"iostream"
#include"vector"
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len <= 0) return 0;
		int preIndex = 0;
		int endIndex = len - 1;
		int ansMin = preIndex;
		
		while (rotateArray[preIndex] >= rotateArray[endIndex])
		{

			int midIndex = (preIndex + endIndex) / 2;

			if (endIndex - preIndex == 1)
			{
				ansMin = endIndex;
				return rotateArray[ansMin];
			}

			if (rotateArray[preIndex] == rotateArray[midIndex] && rotateArray[midIndex] == rotateArray[endIndex])
				return getMinNumber(rotateArray);

			if (rotateArray[preIndex] <= rotateArray[midIndex])
				preIndex = midIndex;
			else if (rotateArray[endIndex] >= rotateArray[midIndex])
				endIndex = midIndex;
		}
		return  rotateArray[ansMin];

	}

	int getMinNumber(vector<int> nums)
	{
		int result = nums[0];
		for (auto ans : nums)
		{
			if (ans < result)
				result = ans;
		}

		return result;

	}
};

int main()
{
	vector<int> arr = { 3, 4, 5, 6, 2 };
	Solution s;
	int ans = s.minNumberInRotateArray(arr);
	cout << ans << endl;
	return 0;
}