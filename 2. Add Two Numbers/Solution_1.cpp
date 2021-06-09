/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		const auto val = l1->val + l2->val;
		auto result = new ListNode(val % 10);
		auto start = result;
		int remain = val / 10;

		l1 = l1->next;
		l2 = l2->next;

		while (l1 && l2)
		{
			remain += l1->val + l2->val;
			result->next = new ListNode(remain % 10);
			remain /= 10;
			result = result->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		auto restList = l1 ? l1 : l2;
		while (restList)
		{
			remain += restList->val;
			result->next = new ListNode(remain % 10);
			remain /= 10;
			result = result->next;
			restList = restList->next;
		}

		if (remain)
			result->next = new ListNode(remain);

		return start;
	}
};