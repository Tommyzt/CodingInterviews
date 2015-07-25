//递归版本  
long long Fibonacci(unsigned int n)  
{  
     if(n<=0)  
       return 0;  
     if(n==1)  
       return 1;  
  
     return Fibonacci(n-1) + Fibonacci(n-2);  
}

//迭代版本  
class Solution {  
public:  
    int Fibonacci(int n) {  
        if(n==0)  
            return 0;  
        if(n==1)  
            return 1;  
        int one = 0, two = 1, ans =0;  
        for(int i=2; i<= n; i++)  
        {  
            ans = one + two;  
            one = two;  
            two = ans;  
        }  
        return ans;  
    }  
}; 

//跳台阶问题
class Solution {  
public:  
    int jumpFloor(int number) {  
        int prev = 0;  
        int cur = 1;  
        for(int i=0;i<number;i++)  
        {  
            int temp = cur;  
            cur = cur + prev;  
            prev = temp;  
        }  
        return cur;  
    }  
};  

//矩阵覆盖问题
class Solution {  
public:  
    int rectCover(int number) {  
        if(number == 0 || number == 1)  
            return 1;  
        if(number == 2)  
            return 2;  
        int one = 1, two = 2, ans = 0;  
        for(int i=3; i<= number; i++)  
        {  
                ans = one + two;  
                one = two;  
                two = ans;  
        }  
        return ans;  
    }  
}; 

