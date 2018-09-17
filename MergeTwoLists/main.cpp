#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* input(int m);
void output(ListNode *l1);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main() {
    int m, n;
    cin >> m >> n;
    auto l1 = input(m);
    auto l2 = input(n);
    output(l1);
    output(l2);
    auto re = mergeTwoLists(l1, l2);
    output(re);
    return 0;
}

ListNode* input(int m) {
    auto h1 = new ListNode(0), t1 = h1;
    for(int i = 0; i < m; ++i) {
        auto node = new ListNode(0);
        cin >> node->val;
        t1->next = node;
        t1 = t1->next;
    }
    return h1->next;
}

void output(ListNode *l1) {
    while(l1 != nullptr) {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    cout << endl;
}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto p = l1, q = l2;
    auto head = new ListNode(0);
    auto tail = head;
    while(p != nullptr && q != nullptr) {
        bool cond = p->val < q->val;
        auto node = cond? p: q;
        p = cond? p->next: p;
        q = cond? q: q->next;
        tail->next = node;
        tail = tail->next;
    }
    p = (p == nullptr)? q: p;
    while(p != nullptr) {
        tail->next = p;
        tail = tail->next;
        p = p->next;
    }
    return head->next;
}