/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        if(pre.empty() || in.empty())
            return NULL;
        struct TreeNode* pRoot = fun(pre,in,0,pre.size()-1,0,in.size()-1);
        return pRoot;
    }
    struct TreeNode* fun(vector<int> pre,vector<int> in,int preStart,int preEnd,int inStart,int inEnd)
    {
        int rootval = pre[preStart];
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = rootval;
        node->left = node->right = NULL;
         
        if(preStart==preEnd)
        {
            if(inStart==inEnd && pre[preStart]==in[inStart])
                return node;
        }
         
        int rootIn = inStart;
        for(int i=inStart;i<=inEnd && in[i]!=rootval;i++)
            ++rootIn;
         
        int leftlen = rootIn - inStart;
        if(leftlen>0)
            node->left = fun(pre,in,preStart+1,preStart+leftlen,inStart,rootIn-1);
        if(preStart+leftlen < preEnd)
            node->right = fun(pre,in,preStart+leftlen+1,preEnd,rootIn+1,inEnd);
         
        return node;
    }
};