class Solution
{
public:
	void printOneToN(int n)
	{
		if (n <= 0)
			return;
		char *number = new char[n + 1];
		memset(number, '0', n);
		number[n] = '\0';

		while (!getInc(number))
		{
			Print(number);
		}

	}

	bool getInc(char *num)
	{
		bool isOver = false;
		int inc = 0;
		int len = strlen(num);
		for (int i = len - 1; i >= 0; i++)
		{
			int ans = num[i] - '0'+inc;
			if (i == len - 1)//只有最后一位增加1
				ans++;
			if (ans >= 10)
			{
				if (i == 0)//如果进位是最高位则说明已经达到最大数了
					isOver = true;
				else{
					ans -= 10;
					inc = 1;
					num[i] = '0' + inc;
				}
			}
			else
			{
				num[i] = '0' + inc;
				break;
			}

		}
		return isOver;
	}

	void Print(char *num)
	{
		int nLen = strlen(num);
		bool isBeginning0 = true;

		for (int i = 0; i < nLen; i++)
		{
			if (isBeginning0 && num[i] != '0')
			{
				isBeginning0 = false;
			}

			if (!isBeginning0)
			{
				cout << num[i];
			}
		}
		cout << '\t';
	}

};