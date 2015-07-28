/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        
        vector<vector<int>> ansPath;
        vector<int> curPath;
        if(root == nullptr)
            return ansPath;
        int curNum = 0;
        
        findAPath(root,ansPath,curPath,expectNumber,curNum);
        
        return ansPath;

    }
    //注意用引用传递参数
    void findAPath(TreeNode* root,vector<vector<int> > &ansPath,vector<int> &curPath, int expNum, int curNum)
    {
        curNum += root->val;//累加
        
        curPath.push_back(root->val);//把当前节点入栈
        
        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        
        if(isLeaf && curNum == expNum)
        {
        	ansPath.push_back(curPath);//找到就压栈
        }
        
        if(root->left != nullptr)
            findAPath(root->left, ansPath, curPath, expNum, curNum);
        
        if(root->right != nullptr)
            findAPath(root->right, ansPath, curPath, expNum, curNum);
        
        curNum -= root->val;//回到上一个节点 要减去当前节点的值
        curPath.pop_back();//在返回到父节点之前，要删除当前节点
    }
};