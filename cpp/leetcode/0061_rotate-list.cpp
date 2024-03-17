#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *ratateRight(ListNode *head, int k) {
    ListNode *cur = head, *end;
    int n = 0;
    while (cur) {
        if (cur->next == nullptr)
            end = cur;
        cur = cur->next;
        n++;
    }
    if (n == 0 || k % n == 0)
        return head;

    k = k % n;
    k = n - k;
    cur = head;
    while (--k) {
        cur = cur->next;
    }
    ListNode *res = cur->next;
    cur->next = nullptr;
    end->next = head;
    return res;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    ListNode* res = ratateRight(l1,2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}

// 4
// 5
// 1
// 2
// 3