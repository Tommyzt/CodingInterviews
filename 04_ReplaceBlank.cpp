#include"iostream"
using namespace std;

class Solution {
public://ע�⣺length�������ַ����������� ����δռ�õĿռ�
	void replaceSpace(char *str, int length) {
		//�����жϱ߽����������ɶ��
		if (str == nullptr || length <= 0)
			return;
		int originLen = 0;
		int numOfblank = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			originLen++;
			if (str[i] == ' ')
				numOfblank++;
			i++;
		}
		int newLen = originLen + numOfblank * 2; 
		if (newLen > length)
			return;
		
		while (originLen >= 0 && newLen > originLen)
		{
			if (str[originLen] == ' ')
			{
				str[newLen--] = '0';
				str[newLen--] = '2';
				str[newLen--] = '%';
			}
			else
				str[newLen--] = str[originLen];
			originLen--;
		}
	}
};
