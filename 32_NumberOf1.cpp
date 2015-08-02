//O(nlogn)算法

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n<=0)
            return 0;
        int ret = 0;
        for(int i=1; i<=n;i++)
            ret += numOf1(i);
        return ret;
    }
    
    int numOf1(int num)
    {
    	int ans = 0;
        while(num)
        {
        	if(num%10 == 1)
                ans++;
            num = num/10;
        }
        return ans;
            
    }
};