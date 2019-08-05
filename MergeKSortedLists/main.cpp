#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int x) : val(x), next(nullptr) {}
};

void addToList(ListNode* &list, ListNode* node);
ListNode* mergeKLists(vector<ListNode*>& lists);

int main() {
	string str;
	vector<ListNode*> lists;

	while (getline(cin, str)) {
		stringstream ss;
		int data;
		ListNode* list = nullptr;
		ss << str;
		while (ss >> data)
			addToList(list, new ListNode(data));
		lists.emplace_back(list);
	}

	ListNode *sorted = mergeKLists(lists), *p = sorted;
	while (p != nullptr) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}

void addToList(ListNode* &list, ListNode* node) {
	if (list == nullptr) {
		assert(node);
		list = node;
		node->next = nullptr;
		return;
	}
	ListNode* p = list;
	while (p->next != nullptr)
		p = p->next;
	p->next = node;
	node->next = nullptr;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* ret = nullptr;

	while (true) {
		bool allEmpty = true;
		int minVal = INT_MAX, minIdx = -1;

		for (int i = 0; i < (int)lists.size(); ++i) {
			if (lists[i] != nullptr) {
				allEmpty = false;
				if (lists[i]->val < minVal) {
					minVal = lists[i]->val;
					minIdx = i;
				}
			}
		}

		if (allEmpty)
			break;

		ListNode* toAdd = lists[minIdx];
		lists[minIdx] = lists[minIdx]->next;
		addToList(ret, toAdd);
	}

	return ret;
}