class Solution {
public:
    bool isVaild = false;
    
    double Power(double base, int exponent) {
   		isVaild = false;
        double ans = 0.0;
        if( isEqual(base,0.0) && exponent <0 )
        {
        	isVaild = true;
            return 0.0;
        }
        
        unsigned int absExp = (unsigned int) (exponent);
        
        if(exponent < 0)
        {
        	absExp = (unsigned int)(-exponent);    
        }
        
        ans = getValue(base, absExp);
        
        if(exponent < 0)
            ans = 1.0/ans;
        return ans;
    }
    
    double getValue(double base, unsigned int absExp)
    {
        double ret = 0.0;
        if(absExp == 0)
            return 1;
        if(absExp == 1)
            return base;
        ret = getValue(base,absExp>>1);
        ret = ret * ret;
        
        if(absExp & 0x1 == 1)
            ret = ret * base;
        return ret;
    }
    
    bool isEqual(double a, double b)
    {
    	if( (a-b < 0.0000001) && (b-a > -0.0000001) )
            return true;
        else
            return false;
    }
};