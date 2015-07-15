#include"iostream"
using namespace std;

class Solution {
public://注意：length是整个字符串的总容量 包括未占用的空间
	void replaceSpace(char *str, int length) {
		//首先判断边界条件，如空啥的
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
