
#include<iostream>
#include<vector>
using namespace std;

/*
��Ϊÿһ�д����ҵ�����ÿһ�д��ϵ��µ�����
���Բ���һ����num��������������
������num�����Ͻǵ������бȽϡ�
����ȣ���ֱ�ӷ��أ��ҵ�������
��num < ���Ͻ��������޳����Ͻ��������� col--
��num > ���Ͻ��������޳����Ͻ��������� row++
*/
class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		bool ans = false;
		int Row_len = array.size();//��ȡ����
		int Col_len = array[0].size();//��ȡ����

		if (!array.empty() && Row_len > 0 && Col_len >0)
		{
			int row = 0;//�±���㿪ʼ
			int col = Col_len - 1;//ͬ���±���㿪ʼ
			while (row < Row_len && col>= 0) //����ע�� col >= 0����Ҫ©��=��
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