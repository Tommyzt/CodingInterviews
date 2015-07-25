void DeleteNode(ListNode *pHead, ListNode *pDelete)
{
	if(pHead == null|| pDelete == null)
		return;
	if(pDelete->next != null)
	{
		ListNode *pNext = pDelete->next;
		pDelete->val = pNext->val;
		pDelete->next = pNext->next;
		
		delete pNext;
		pNext = null;
	}
	else if(*pHead == *pDelete)
	{
			delete pDelete;
			pDelete = null;
			*pHead = null;
	}
	else
	{
			ListNode *pNode = *pHead;
			while(pNode->next != pDelete)
				pNode = pNode->next;
			
			pNode->next = null;
			delete pDelete;
			pDelete = null;
	}
}