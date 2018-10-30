#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* reverseKGroup(ListNode* head, int k);

int main() {
	ListNode *head = nullptr, *tail = nullptr;
	int data, k;
	cin >> k;
	while (cin >> data) {
		auto p = new ListNode(data);
		if (head == nullptr)
			head = tail = p;
		else {
			tail->next = p;
			tail = p;
		}
	}
	ListNode *ptr = reverseKGroup(head, k);
	while (ptr != nullptr) {
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
	return 0;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == nullptr or k == 1)
		return head;

	int num = 0;
	for (ListNode *p = head; p != nullptr; p = p->next)
		++num;

	auto dummy = new ListNode(-1);
	dummy->next = head;
	head = dummy;


	ListNode *pre, *cur, *nxt;
	pre = head;
	while (num >= k) {
		cur = pre->next;
		nxt = cur->next;
		for (int i = 0; i < k - 1; ++i) {
			ListNode *temp = nxt->next;
			nxt->next = pre->next;
			pre->next = nxt;
			cur->next = temp;
			nxt = temp;
		}
		pre = cur;
		num -= k;
	}
	ListNode *todel = head;
	head = head->next;
	delete todel;
	return head;
}