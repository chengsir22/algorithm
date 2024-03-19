#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head;
    while (fast) {
        if (fast->val != slow->val) {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = nullptr;
    return head;
}

ListNode *deleteDuplicates2(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *cur = head;
    while (cur->next) {
        if (cur->next->val == cur->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

ListNode *deleteDuplicates1(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            int val = cur->next->val;
            ListNode *p = cur->next;
            while (p->next) {
                if (p->next->val == val) {
                    p = p->next;
                } else {
                    break;
                }
            }
            cur->next->next = p->next;
            cur = p;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}

int main() {
}