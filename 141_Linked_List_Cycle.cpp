/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// approach
// Approach Current:
// Two Pointers / Linked List
// Suggested: Two Pointers / Linked List / Floyd's Cycle Finding Algorithm
// Key Idea: Using fast and slow pointers to detect cycles in linear time with constant space.

  
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
