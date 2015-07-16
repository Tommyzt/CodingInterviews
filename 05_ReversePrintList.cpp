/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> ans;
		while (head != nullptr)
		{
			ans.push_back(head->val);
			head = head->next;
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};