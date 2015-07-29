class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int result=0;
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());
        int len = numbers.size();
        int num = numbers[len/2];
        int count = 0;
        
        for(int i=0;i<len;i++)
        {
        	if(numbers[i] == num)
                count++;
        }
        
        if(count > len/2)
        {
        	result = num;
            return result;
        }
        else
            return 0;
    }
};