#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy, *cur = dummy;
    while (cur->next) {
        for (int i = 0; i < k && cur != nullptr; i++) {
            cur = cur->next;
        }
        if (cur == nullptr)
            return dummy->next;
        ListNode* t = cur->next;
        cur->next = nullptr;
        ListNode* start = pre->next;
        pre->next = reverseList(start);
        start->next = t;
        pre = start;
        cur = pre;
    }
    return dummy->next;
}

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr, *cur=head;
    while(cur){
        ListNode *nextNode = cur->next;
        cur->next=pre;
        pre = cur;
        cur=nextNode;
    }
    return pre;
}