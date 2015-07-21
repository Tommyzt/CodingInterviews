class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()<= 0)
        {
        	    while(stack1.size()>0)
                {
                    int num = stack1.top();
                    stack1.pop();
                	stack2.push(num);
                }
        }
        
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};