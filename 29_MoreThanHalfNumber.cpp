//O(nlogn)解法
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

//O(n)解法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int result=0;
        if(numbers.empty())
            return 0;
        //sort(numbers.begin(),numbers.end());
        int len = numbers.size();
        
        int mid = len >> 1;
        int start = 0;
        int end = len-1;
        int index = partition(numbers,start, end);
        while(index != mid)
        {
        	if(index > mid)
            {
            	end = index-1;
                index = partition(numbers,start,end);
            }
            else
            {
            	start = index+1;
                index = partition(numbers,start,end);
            }
        }
        
        
    
        int num = numbers[index];
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
    
    int partition(vector<int> numbers, int low, int high)
    {
    	int pivotloc = low;
        int temp = numbers[low];
        
        while(low < high)
        {
        	while(low < high && numbers[high] >= temp)
                high--;
            if(low < high)
            {
            	numbers[low] = numbers[high];
                low++;
            }
            
            while(low < high && numbers[low] <= temp)
                low++;
            if(low < high)
            {
            	numbers[high] = numbers[low];
                high--;
            }
        }
        numbers[low] = temp;
        return low;
    }
};