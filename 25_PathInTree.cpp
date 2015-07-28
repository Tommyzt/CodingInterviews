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
    //ע�������ô��ݲ���
    void findAPath(TreeNode* root,vector<vector<int> > &ansPath,vector<int> &curPath, int expNum, int curNum)
    {
        curNum += root->val;//�ۼ�
        
        curPath.push_back(root->val);//�ѵ�ǰ�ڵ���ջ
        
        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        
        if(isLeaf && curNum == expNum)
        {
        	ansPath.push_back(curPath);//�ҵ���ѹջ
        }
        
        if(root->left != nullptr)
            findAPath(root->left, ansPath, curPath, expNum, curNum);
        
        if(root->right != nullptr)
            findAPath(root->right, ansPath, curPath, expNum, curNum);
        
        curNum -= root->val;//�ص���һ���ڵ� Ҫ��ȥ��ǰ�ڵ��ֵ
        curPath.pop_back();//�ڷ��ص����ڵ�֮ǰ��Ҫɾ����ǰ�ڵ�
    }
};