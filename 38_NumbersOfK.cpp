class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int result=0;
        
        if(data.empty())
            return 0;
        int start = 0;
        int end = data.size()-1;
        
        int first = getFirstK(data,k,start,end);
        int last = getLastK(data,k,start,end);
        
        if(first >-1 && last >-1)
            result = last - first+1;
        
        return result;
    }
    
    int getFirstK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        int midIndex = (start + end)/2;
        int midData = data[midIndex];
        
        if(midData == k)
        {
         	if(midIndex > 0 && data[midIndex-1] != k || midIndex == 0)
                return midIndex;
            else
                end = midIndex-1;
        }
        else if(midData > k)
            end = midIndex-1;
        else
            start = midIndex+1;
            
        return getFirstK(data,k,start,end);
    }
    
    int getLastK(vector<int> data, int k, int start, int end)
    {
        if(start > end)
            return -1;
        int midIndex = (start + end)/2;
        int midData = data[midIndex];
        
        if(midData == k)
        {
         	if(midIndex < data.size()-1 && data[midIndex+1] != k || midIndex == data.size()-1)
                return midIndex;
            else
                start = midIndex+1;
        }
        else if(midData > k)
            end = midIndex-1;
        else
            start = midIndex+1;
            
        return getLastK(data,k,start,end);
    }
};