#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;

        // Push the head of each linked list from 'lists' into pq
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            curr->next = smallest;
            curr = curr->next;
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    Solution sol;
    // lists = [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged_head = sol.mergeKLists(lists);
    for (ListNode* node = merged_head; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }
    cout << endl;
    
    return 0;
}
