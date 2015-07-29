class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        
        if(array.empty())
            return 0;
        
        int retMax=INT_MIN;
        int len = array.size();
        vector<int> ans(len,INT_MIN);
        
        ans[0] = array[0];
        retMax = ans[0];
        
        for(int i=1; i<len; i++)
        {
        	ans[i] = getMax( (ans[i-1] + array[i]), array[i]);  
            
            if(ans[i] > retMax)
                retMax = ans[i];
        }
        
        return retMax;
    
    }
    
    int getMax(int a, int b)
    {
    	return a>b?a:b;    
    }
};