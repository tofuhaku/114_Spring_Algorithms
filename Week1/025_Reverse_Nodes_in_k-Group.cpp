#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Reference to 092 */
class Solution {
private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* Calculate the length */
        int len = getLength(head);
        
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* p0 = dummy;
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        
        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        while (len >= k) {
            len -= k;
            
            for (int i = k; i--;) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            
            ListNode* tail = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = tail;
        }
        
        // ListNode* res = dummy->next;
        // delete dummy;
        // return res;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    // head = [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 3;
    head = sol.reverseKGroup(head, k);
    for (ListNode* node = head; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }
    return 0;
}