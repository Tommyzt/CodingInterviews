//����1������flag
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

//���ɣ���һ������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0��
//��ôһ�������Ķ����Ʊ�ʾ���ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����

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