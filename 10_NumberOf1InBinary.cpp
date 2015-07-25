//方法1，左移flag
int NumberOf1(int n)
{
	int flag = 1;
	static unsigned int count = 0;
	while(flag)
	{
		if(n & flag)
			count++;
		flag = flag << 1;
	}
	
	return count;
}

//规律：把一整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。
//那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作。

int NumberOf1(int n)
{
	static unsigned int count = 0;
	while(n)
	{
		count++;
		n = n&(n-1);
	}
	return count;
}